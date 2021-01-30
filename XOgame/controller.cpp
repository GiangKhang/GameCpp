#include "controller.h"
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

controller::controller(){}
controller::~controller()
{
    delete c_view;
    delete c_model;
}

int controller::start()
{
    return (c_view->start());
}

void controller::NhapThongTinChoi()
{
    vector<string>id;
    vector<int>step;
    string temp;
    fstream f("ID.txt", ios::in);
    while(!f.eof())
    {
        f >> temp;
        id.push_back(temp);
    }
    int NumID = id.size()/3+1;
    temp = to_string(NumID);
    temp = "XO" + temp;
    id.clear();
    id.push_back(temp);
    c_view->begin_play(id, step);
    c_model->setID(id);
    c_model->setStep(step);
}
void controller::TaoBanCo()
{
    vector<string>id;
    vector<int>step;
    c_model->getID(id);
    c_model->getStep(step);

    arr= new char* [step[0]+1];
    for(int i=0; i<step[0]; i++){
        arr[i] = new char[step[0]];
    }
    for(int i=0; i<step[0]; i++){
        for(int j=0; j<step[0]; j++){
            arr[i][j]=' ';
        }
    }
    system("cls");
    c_view->hienThi(id, step, arr);

}
void controller::HuyBanCo()
{
    vector<int>step;
    c_model->getStep(step);
    for(int i=0; i<step[0]; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
#define XOR(a1, a2, a3, a4)  ((a1!=' ')&&(a1==a2)&&(a1==a3)&&(a1==a4))
bool controller::win(int m, int &count)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i<(m-3))
            {
                if(XOR(arr[i][j],arr[i+1][j],arr[i+2][j],arr[i+3][j])) //doc
                    return 1;
                if(j<(m-3))
                    if(XOR(arr[i][j],arr[i+1][j+1],arr[i+2][j+2],arr[i+3][j+3])) //cheo xuong
                        return 1;
            }
            if(j<(m-3))
            {
                if(XOR(arr[i][j],arr[i][j+1],arr[i][j+2],arr[i][j+3])) //ngang
                    return 1;
                if(i>3)
                    if(XOR(arr[i][j],arr[i-1][j+1],arr[i-2][j+2],arr[i-3][j+3])) //cheo len
                        return 1;
            }
        }
    }
    if(count==m*m)
    {
        count++;
        return 1;
    }
    else
        return 0;
}
void controller::NhapXO()
{
    vector<string>id;
    vector<int>step;
    c_model->getID(id);
    c_model->getStep(step);
    step.push_back(0);
    int m=step[0];
    static int count=step[1];
    int a=0, b=0;
    while(1)
    {
        count++;
        c_view->Nhap(count, m, id, a, b);
//        do
//        {
//            c_view->Nhap(count, m, id, a, b);
//        }while(arr[a][b]!=' ');
        if(count%2)
            arr[a][b]='X';
        else
            arr[a][b]='O';
        step.push_back(a+1);
        step.push_back(b+1);
//        system("cls");
//        c_view->hienThi(id, step, arr);
        if(win(m, count))
            break;
    }
    if(count>m*m)
        id.push_back("draw");
    else if(count%2)
        id.push_back("win");
    else
        id.push_back("lose");
    c_view->thongbao(id,m);
    step[1]=count;
    c_model->setID(id);
    c_model->setStep(step);
}
void controller::read_person()
{
    vector<string>name;
    vector<int>win;
    vector<int>draw;
    vector<int>lose;

    string n;
    int w, d, l;
    fstream file;
    file.open("player.txt", ios::in);
    while(!file.eof())
    {
        file >> n >> w >> d >>l;
        name.push_back(n);
        win.push_back(w);
        draw.push_back(d);
        lose.push_back(l);
    }
    file.close();
    c_model->set(name, win, draw, lose);
}
void controller::UpDate()
{
    vector<string>name;
    vector<int>win;
    vector<int>draw;
    vector<int>lose;
    c_model->get(name, win, draw, lose);
    vector<string>id;
    c_model->getID(id);

    for(int i=1; i<3; i++)
    {
        for(unsigned int j=0; j<name.size(); j++)
        {
            if(name[j]!=id[i])
            {
                if(j<name.size()-1)
                    continue;
                else
                {
                    name.push_back(id[i]);
                    win.push_back(0);
                    draw.push_back(0);
                    lose.push_back(0);
                }
            }
            else break;
        }
    }

    for(unsigned int i=0; i<name.size(); i++)
    {
        if(name[i]==id[1])
        {
            if(id[3]=="draw")
                draw[i]++;
            else if(id[3]=="win")
                win[i]++;
            else
                lose[i]++;
        }
        if(name[i]==id[2])
        {
            if(id[3]=="draw")
                draw[i]++;
            else if(id[3]=="win")
                lose[i]++;
            else
                win[i]++;
        }
    }
     c_model->set(name, win, draw, lose);
}
void controller::write()
{
    vector<string>id;
    c_model->getID(id);
    fstream file;
    file.open("ID.txt", ios::app);
    file << endl;
    file <<id[0]<<"\t"<<id[1]<<"\t"<<id[2];
    file.close();

    vector<int>step;
    c_model->getStep(step);
    file.open("step.txt", ios::app);
    file << endl;
    for(unsigned int i=0; i<step.size(); i++)
    {
        file <<step[i]<<" ";
    }
    file.close();

    read_person();
    UpDate();
    vector<string>name;
    vector<int>win;
    vector<int>draw;
    vector<int>lose;
    c_model->get(name, win, draw, lose);
    file.open("player.txt");
    for(unsigned int i=0; i<name.size(); i++)
    {
        file<< name[i]<<"\t"<< win[i] <<"  "<< draw[i] <<"  "<< lose[i];
        if(i<name.size()-1)
            file << "\n";
    }
    file.close();
}
void controller::playGame1()
{
    NhapThongTinChoi();
    TaoBanCo();
    NhapXO();
    write();
    system("pause");
    HuyBanCo();
}

void controller::NhapID()
{
    vector<string>id;
    vector<string>temp;
    //string temp;
    fstream file;
    file.open("ID.txt",ios::in);
    string s;
    while (!file.eof())
    {
        file >> s;
        temp.push_back(s);
    }
    file.close();

    c_view->replay(temp, id);

    int count=-1;

    for(unsigned int i=0; i<temp.size(); i=i+3)
    {
        if(temp[i]==id[0])
            count = i/3;
    }

    vector<int>step;
    file.open("step.txt", ios::in);
    while(count!=-1)
    {
        step.clear();
        int a,b;
        file >> a >>b;
        step.push_back(a);
        step.push_back(b);
        cout<<a<<b<<endl;
        for(int i=0; i<2*b; i++)
        {
            file >> a;
            step.push_back(a);
        }
        count--;
    }
    file.close();
    c_model->setID(id);
    c_model->setStep(step);
}
void controller::playGame2()
{
    vector<string>id;
    vector<int>step;
    c_model->getID(id);
    c_model->getStep(step);
    int m = step[0];
    int count= step[1];
    for(int i=0; i<count; i++)
    {
        int a, b;
        a = --step[2+2*i];
        b = --step[2*i+3];
        if(i%2==0)
            arr[a][b] = 'X';
        else
            arr[a][b] = 'O';
        system("cls");
        c_view->hienThi(id, step, arr);
    }
    if(count>m*m)
        id.push_back("draw");
    else if(count%2)
        id.push_back("win");
    else
        id.push_back("lose");
    c_view->thongbao(id, m);
}
void controller::replay1()
{
    NhapID();
    TaoBanCo();
    playGame2();
    system("pause");
}

void controller::SapXep()
{
    vector<string>name;
    vector<int>win;
    vector<int>draw;
    vector<int>lose;

    c_model->get(name, win, draw, lose);

    vector<float>tile;
    for(unsigned int i=0; i<name.size(); i++)
    {
        float a =(double) win[i]/(win[i]+draw[i]+lose[i])*100;
        tile.push_back(a);
    }

    for(unsigned int i=0; i<name.size()-1; i++)
    {
        for(unsigned int j=i+1; j<name.size(); j++)
        {
            if(tile[i]<tile[j])
            {
                swap(name[i], name[j]);
                swap(win[i], win[j]);
                swap(draw[i], draw[j]);
                swap(lose[i], lose[j]);
                swap(tile[i], tile[j]);
            }
        }
    }
    switch (c_view->selec_check())
    {
    case 1:
    {
        vector<unsigned int>temp;
        c_view->check_player(name, temp);
        float tam=100, denta=100;
        for(unsigned int i=0; i<name.size(); i++)
        {
            if(i==temp[0])
                continue;
            if(denta>=abs(tile[i]-tile[temp[0]]))
            {
                denta = tile[i]-tile[temp[0]];
                tam=tile[i];
            }
            else
                break;
        }

        for(unsigned int i=0; i<name.size(); i++)
        {
            if(i==temp[0])
                continue;
            if(tile[i]==tam)
                temp.push_back(i);
        }
        c_view->Player(name, win, draw, lose, tile, temp);
        break;
    }
    case 2:
        c_view->top(name, win, draw, lose, tile);
        break;
    }
}
void controller::check()
{
    read_person();
    SapXep();

    system("pause");
}
