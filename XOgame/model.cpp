#include "model.h"

model::model(){}

void model::get(vector<string> &name, vector<int> &win, vector<int> &draw, vector<int> &lose)
{
    name = this->name;
    win = this->win;
    draw = this->draw;
    lose = this->lose;
}

void model::set(vector<string> name, vector<int> win, vector<int> draw, vector<int> lose)
{
    this->name = name;
    this->win = win;
    this->draw = draw;
    this->lose = lose;
}

void model::setID(vector<string> ID)
{
    this->ID=ID;
}
void model::getID(vector<string> &ID)
{
    ID = this->ID;
}
void model::setStep(vector<int> step)
{
    this->step =  step;
}
void model::getStep(vector<int> &step)
{
    step = this->step;
}











