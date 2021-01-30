#include<iostream>
#include "controller.h"
#include "view.h"
#include<fstream>
using namespace std;

int main()
{
    system("color 0b");
    controller *p_controller = new controller;
    while(1)
    {
        system("cls");
        switch (p_controller->start())
        {
        case 1:        
            p_controller->playGame1();
            break;        
        case 2:        
           p_controller->check();
            break;        
        case 3:
            p_controller->replay1();
            break;
        case 4:
            return 0;
        }
    }
    delete p_controller;

}
