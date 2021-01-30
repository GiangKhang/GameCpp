#ifndef VIEW_H
#define VIEW_H
#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;

class view
{
public:
    view();
    void gotoxy(short x, short y);
    int start();
    void begin_play(vector<string> &ID, vector<int>&STEP);
    void replay(vector<string>ID, vector<string> &temp);

    void begin_replay(string &temp);
    void hienThi(vector<string>ID, vector<int>STEP, char **arr);
    void Nhap(int count, int m, vector<string>ID, int &a, int &b);
    void thongbao(vector<string>ID, int m);
    int selec_check();
    void top(vector<string>name, vector<int>win, vector<int>draw, vector<int>lose, vector<float>tile);
    void check_player(vector<string> name, vector<unsigned int>&temp);

    void NoPlayer();
    void Player(vector<string>name, vector<int>win, vector<int>draw, vector<int>lose, vector<float>tile, vector<unsigned int>temp);
};

#endif // VIEW_H
