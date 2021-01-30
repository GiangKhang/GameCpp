#include "GUI.h"



void Show_menu()
{
	std::cout << "*----------MAIN MENU---------*\n";
	std::cout << "Press number to choice:\n";
	std::cout << "1.Play with Other Player\n";
	std::cout << "2.Play with BOT\n";
	std::cout << "3.REPLAY\n";
	std::cout << "4.Player's Information\n";
	std::cout << "5.Guild\n";
	std::cout << "6.Exit\n";

}

void Show_table(char Table[16][16])
{
	std::cout << "=> Player 1 = X, Player 2 = O:\n\n";
	std::cout << "    0   1   2   3   4   5   6   7   8   9  \n";
	std::cout << "  |---|---|---|---|---|---|---|---|---|---|\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " | ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << Table[i + 3][j + 3] << " | ";
		}
		std::cout << std::endl;
		std::cout << "  |---|---|---|---|---|---|---|---|---|---|\n";
	}
}

void Play_W_otherplayer()
{
	std::cout << "*---------Play with other player--------*\n";
	std::cout << "1.Select X\n";
	std::cout << "2.Select O\n";
	std::cout << "3.Back to MAIN MENU\n";
}

void Play_W_BOT()
{
	std::cout << "*---------Play with BOT--------*\n";
	std::cout << "1.Easy\n";
	std::cout << "2.Normal\n";
	std::cout << "3.Back to MAIN MENU\n";
}

void Show_inforplayer()
{
	std::cout << "*----------Information Player----------*";

}

void Show_guild()
{

}
