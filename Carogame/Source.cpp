#include<iostream>
#include"GUI.h"
#include"LOGIC.h"
#include<fstream>
char Table[16][16];
int main() {
	memset(Table, ' ', 256);
	Start(Table);

	return 0;
}