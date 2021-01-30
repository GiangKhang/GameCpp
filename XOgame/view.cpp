#include "view.h"
#include<iostream>
using namespace std;

view::view(){}

void view::gotoxy(short x, short y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

int view::start()
{
    if(GetAsyncKeyState(VK_RETURN))
        Sleep(150);
    string s[4]={"1: Choi Game", "2: Xem thong tin nguoi choi", "3: Replay", "4: Thoat"};
    int p = 0;
    while(1)
    {
        system("cls");
        cout<<"***************************************************\n";
        cout<<"***************************************************\n";
        cout<<"**                                               **\n";
        cout<<"**                  LUA CHON                     **\n";
        cout<<"**                                               **\n";
        cout<<"**                                               **\n";
        for(int i=0; i<4; i++)
        {
            if(i==p)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout<<"        "<<s[i]<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            }
            else
            {
                cout<<"        "<<s[i]<<endl;
            }
        }
        cout<<"**                                               **\n";
        cout<<"**                                               **\n";
        cout<<"**                                               **\n";
        cout<<"***************************************************\n";
        cout<<"***************************************************\n";
        while(1)
        {
            if(GetAsyncKeyState(VK_DOWN))
            {
                p++;
                if(p==4)
                    p=0;
                break;
            }
            if(GetAsyncKeyState(VK_UP))
            {
                p--;
                if(p==-1)
                    p=3;
                break;
            }
            if(GetAsyncKeyState(VK_RETURN))
                return ++p;
        }
        Sleep(150);
    }
}

void view::begin_play(vector<string> &ID, vector<int>&STEP)
{
    int m;
    string s1, s2;
    cout << "\n\n";
    cout<<"Chung toi tao cho ban ma ID sau: "<<ID[0]<<endl;
    cout<<"\nNhap kich thuoc ban co: ";
    cin >> m;
    cout<<"\nPlayer 1: ";
    cin>>s1;
    cout<<"\nPlayer 2: ";
    cin >>s2;
    STEP.push_back(m);
    ID.push_back(s1);
    ID.push_back(s2);
}

void view::replay(vector<string>temp, vector<string> &id)
{
    system("cls");
    cout<<"DANH SACH NHUNG TRAN DAU \n\n";
    cout<<"MaID\t\tPlayer1\t\tPlayer2\n\n";
    unsigned int p=0;
    while(1)
    {
        gotoxy(0,5);
        Sleep(150);
        for(unsigned int i=0; i<temp.size(); i=i+3)
        {
            if(i==p)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout<<temp[i]<<"\t\t"<<temp[i+1]<<"\t\t"<<temp[i+2]<<"\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            }
            else
                cout<<temp[i]<<"\t\t"<<temp[i+1]<<"\t\t"<<temp[i+2]<<"\n";
        }
        while(1)
        {
            if(GetAsyncKeyState(VK_DOWN))
            {
                if(p==temp.size()-3)
                    p=0;
                else
                    p+=3;
                break;
            }
            if(GetAsyncKeyState(VK_UP))
            {
                if(p==0)
                    p=temp.size()-3;
                else
                    p-=3;
                break;
            }
            if(GetAsyncKeyState(VK_RETURN))
            {
                for(int i=0; i<3; i++)
                {
                    id.push_back(temp[p+i]);
                }
                return ;
            }
        }
    }
}

void view::hienThi(vector<string>ID, vector<int>STEP, char **arr)
{
    cout<<ID[1]<< " <X> \t"<<ID[2]<<" <O>\n\n";
    for(int j=0; j<=STEP[0]; j++){
        if(j<10)
            cout<<" "<<j<<" |";
        else
        cout<<" "<<j<<"|";
    }
    //cout<<endl;
    for(int i=0; i<STEP[0]; i++){
        cout<<endl;
        for(int j=0; j<=STEP[0]; j++){
            cout<<"----";
        }
        cout<<endl;
        if(i<9)
            cout<<" "<<i+1<<" |";
        else
            cout<<" "<<i+1<<"|";

        for(int j=0; j<STEP[0]; j++){
            cout<<" "<<arr[i][j]<<" |";
        }
    }
    cout<<endl<<endl;
}
void view::Nhap(int count,int m, vector<string>ID, int &a, int &b)

{
    gotoxy(0, 2*m+7);
    if(count%2)
        cout<<ID[1]<<" turn: ";
    else
        cout<<ID[2]<<" turn: ";
    if(GetAsyncKeyState(VK_RETURN))
        Sleep(150);
    while(1)
    {

        int x= 5+4*b;
        int y= 4+2*a;
        gotoxy(x,y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        while(1)
        {
            if(GetAsyncKeyState(VK_DOWN))
            {
                if(a==m-1)
                    a=0;
                else
                    a++;
                break;
            }
            if(GetAsyncKeyState(VK_UP))
            {
                if(a==0)
                    a=m-1;
                else
                    a--;
                break;
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {
                if(b==m-1)
                    b=0;
                else
                    b++;
                break;
            }
            if(GetAsyncKeyState(VK_LEFT))
            {
                if(b==0)
                    b=m-1;
                else
                    b--;
                break;
            }

            if(GetAsyncKeyState(VK_RETURN))
            {
                if(count%2)
                    cout<<'X';
                else
                    cout<<'O';
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                return;
            }
        }
        Sleep(150);
    }
}

void view::thongbao(vector<string>ID,int m)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    gotoxy(0, 2*m+7);
    if(ID[3]=="win")
        cout<<ID[1]<<" thang\n";
    else if(ID[3]=="lose")
        cout<<ID[2]<<" thang\n";
    else
        cout<<"2 ben hoa nhau\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

int view::selec_check()
{
    string s[2]={"1: Kiem tra thong tin nguoi choi", "2: Diem cao nhat"};
    int p=0;
    while(1)
    {
        Sleep(150);
        gotoxy(0, 18);
        for(int i=0; i<2; i++)
        {
            if(i==p)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout<<s[i]<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            }
            else
                cout<<s[i]<<endl;
        }
        while(1)
        {
            if(GetAsyncKeyState(VK_DOWN)|GetAsyncKeyState(VK_UP))
            {
                p=p^1;
                break;
            }
            if(GetAsyncKeyState(VK_RETURN))
                return ++p;
        }
//        Sleep(150);

    }
}
void view::top(vector<string>name, vector<int>win, vector<int>draw, vector<int>lose, vector<float>tile)
{
    cout<<"\nDIEM CAO NHAT\n";
    cout<<"ten\twin\tdraw\tlose\tty le thang\n";
    for(int i=0; i<5; i++)
    {
        cout <<name[i]<<"\t "
             <<win[i]<<"\t "
             <<draw[i]<<"\t "
             <<lose[i]<<"\t  "
             <<tile[i]<<"\n";
    }
}

void view::check_player(vector<string>name, vector<unsigned int>&temp)
{
    string s;
    cout<<"\n\nNhap ten nguoi choi: ";
    cin >> s;
    for(unsigned int i=0; i<name.size(); i++)
    {
        if(s==name[i])
            temp.push_back(i);
    }
    while(temp.size()==0)
    {
        cout<<"\nKhong co ten trong danh sach, vui long nhap lai: ";
        cin>>s;
        for(unsigned int i=0; i<name.size(); i++)
        {
            if(s==name[i])
                temp.push_back(i);
        }
    }
}

void view::Player(vector<string>name, vector<int>win, vector<int>draw, vector<int>lose, vector<float>tile, vector<unsigned int>temp)
{
    cout<<"\nThong tin nguoi choi: ";
    cout<<"\n"<<name[temp[0]]<<"\t"<<win[temp[0]]<<"\t"<<draw[temp[0]]<<"\t"<<lose[temp[0]]<<"\t"<<tile[temp[0]];
    cout<<"\nThong tin nguoi choi tuong duong: ";
    for(unsigned int i=1; i<temp.size(); i++)
    {
        cout<<"\n"<<name[temp[i]]<<"\t"<<win[temp[i]]<<"\t"<<draw[temp[i]]<<"\t"<<lose[temp[i]]<<"\t"<<tile[temp[i]];
    }
    cout<<endl;
}
