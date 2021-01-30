#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<iostream>
#include"view.h"
#include<string>
#include<vector>
#include"model.h"
//#include<unistd.h>

class controller
{
private:
    char **arr;
public:
    view *c_view = new view;
    model *c_model = new model;
    controller();
    ~controller();
    // màn hình menu
    int start();
    void playGame1();
    void NhapThongTinChoi();
    void TaoBanCo();
    void HuyBanCo();
    void NhapXO();
    void write();
    void read_person();
    void UpDate();
    bool win(int m, int &count);

    void replay1();
    void NhapID();
    void playGame2();

    void check();
    void SapXep();




};

#endif // CONTROLLER_H
