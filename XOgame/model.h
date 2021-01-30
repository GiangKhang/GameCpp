#ifndef MODEL_H
#define MODEL_H
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
class model
{
private:
    vector<string>name;
    vector<int>win;
    vector<int>draw;
    vector<int>lose;
    vector<float>tile;

    vector<string>ID;
    vector<int>step;


public:
    model();

    void setID(vector<string>ID);
    void getID(vector<string>&ID);
    void setStep(vector<int>step);
    void getStep(vector<int>&step);
    void get(vector<string>&name, vector<int>&win, vector<int>&draw, vector<int>&lose);
    void set(vector<string>name, vector<int>win, vector<int>draw, vector<int>lose);
};

#endif // MODEL_H
