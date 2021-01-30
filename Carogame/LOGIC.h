#include"GUI.h"
#ifndef LOGIC
#define LOGIC
#include<iostream>
#include<fstream>
#include<string>
static std::string play1, play2, player;
bool Check(char, char, char, char);
int Check_state(char table[16][16]);
void Two_player(char[16][16], std::string&, std::string&, std::string&, std::fstream&);
int Random(int, int);
void Easy_BOT(char[16][16]);
void Medium_BOT(char[16][16]);
void Hard_BOT(char[16][16]);
void Start(char[16][16]);
void writefile(std::string);


#endif 