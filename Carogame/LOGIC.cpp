#include "LOGIC.h"
#include<fstream>

bool Check(char a1, char a2, char a3, char a4) {
	if ((a1 != ' ') && (a1 == a2) && (a1 == a3) && (a1 == a4))
		return 1;
	else
		return 0;
}

int Check_state(char table[16][16])
{
	for (int i = 3; i < 13; i++)
	{
		for (int j = 3; j < 13; j++)
		{
			if (Check(table[i][j], table[i + 1][j], table[i + 2][j], table[i + 3][j]) ||           //doc
				Check(table[i][j], table[i + 1][j + 1], table[i + 2][j + 2], table[i + 3][j + 3]) ||//cheo xuong
				Check(table[i][j], table[i][j + 1], table[i][j + 2], table[i][j + 3]) ||            //ngang
				Check(table[i][j], table[i - 1][j + 1], table[i - 2][j + 2], table[i - 3][j + 3])) //cheo len
			{
				if ('X' == table[i][j])
					return 1;
				else
					return 2;
			}

		}
	}

	for (int i = 3; i < 13; i++)
	{
		for (int j = 3; j < 13; j++)
		{
			if (' ' == table[i][j])
				return 0;
		}
	}
	return 3;
}

void Two_player(char Table[16][16], std::string& play1, std::string& play2, std::string& player, std::fstream& F)
{
	static int turn;
	turn++;
	turn %= 2;
	player = (turn) ? play1 : play2;
	F.open("Infor.txt", std::ios_base::app);
	if (Check_state(Table) == 0) {
		int x, y;
		Show_table(Table);
		std::cout << player << "'s Turn: \n";
		F << player << ":";
		do
		{
			std::cout << "Row: "; std::cin >> x;
		while (x < 0 || x > 9)
			{
				std::cout << "Nhap lai row: "; std::cin >> x;
			}
			std::cout << "Colum: "; std::cin >> y;
			while (y < 0 || y > 9)
			{
				std::cout << "Nhap lai colum: "; std::cin >> y;
			}
		} while (Table[x + 3][y + 3] != ' ');
		{if (turn == 1)
			Table[x + 3][y + 3] = 'X';
		else
			Table[x + 3][y + 3] = 'O'; }
		F << x << y << " ";
	}
	switch (Check_state(Table)){

	case 1:
		system("cls");
		Show_table(Table);
		std::cout << play1 << " Win!";
		F << play1 << " Win!" << std::endl;
		break;
	case 2:
		system("cls");
		Show_table(Table);
		std::cout << play2 << " Win!";
		F << play2 << " Win!" << std::endl;
		break;
	case 3:
		system("cls");
		Show_table(Table);
		std::cout << play2 << " Draw " << play2;
		F << play2 << " Draw " << play2 << std::endl;
	default:
		break;
	}
	F.close();
}

int Random(int min, int max) {
	int i = min + rand() % (max + 1 - min);
	return i;
}

void Easy_BOT(char Table[16][16])
{
	if (Check_state(Table) == 0)
	{
		static int turn1;
		turn1++;
		turn1 %= 2;
		int x, y;
		if (turn1 == 1)
		{
			std::cout << "Your's Turn: \n";
			do
			{
				std::cout << "Row: "; std::cin >> x;
				while (x < 0 || x > 9)
				{
					std::cout << "Nhap lai row: "; std::cin >> x;
				}
				std::cout << "Colum: "; std::cin >> y;
				while (y < 0 || y > 9)
				{
					std::cout << "Nhap lai colum: "; std::cin >> y;
				}
			} while (Table[x + 3][y + 3] != ' ');
			Table[x + 3][y + 3] = 'X';
		}
		else
			{
			do
			{
				do
				{
					x = Random(1, 10);
					y = Random(1, 10);
				} while (x < 0 || x > 9 || y < 0 || y > 9);
			} while (Table[x + 3][y + 3] != ' ');
			Table[x + 3][y + 3] = 'O';
			}
	}

}

void Medium_BOT(char Table[16][16])
{
}

void Hard_BOT(char Table[16][16])
{
}


void Start(char Table[16][16])
{
LABLE1:
	memset(Table, ' ', 256);
	system("cls");
	Show_menu();
	int m_select;
	std::cout << "Nhap vao lua chon: "; std::cin >> m_select;
	switch (m_select)
	{
	case 1:
	{
	
		system("cls");
		int m_select1;
		std::fstream F;
		std::cout << "_____________Play with Other Player_____________\n";
		std::cout << "1.Start\n";
		std::cout << "2.Xem lich su thang thua\n";
		std::cout << "3.Return to MENU\n";
		std::cout << "Nhap vao lua chon: "; std::cin >> m_select1;
		switch (m_select1)
		{
		case 1:
		{
			system("cls");
			char yes;
			std::cout << "_________________Start_________________\n";
			std::cout << "Player1's name: "; std::cin >> play1;
			std::cout << "Player2's name: "; std::cin >> play2;
			
		LABLE2:
			F.open("Infor.txt", std::ios::app);
			F << play1 << "vs";
			F << play2 << "_";
			F.close();
			memset(Table, ' ', 256);
			do
			{
				system("cls");
				Two_player(Table,play1,play2,player,F);
			} while (Check_state(Table)==0);
			do
			{
				std::cout << "\nBan co muon choi lai khong: y/n?"; std::cin >> yes;
			} while (yes!='y'&&yes!='n');
			switch (yes)
			{
			case 'y':
				goto LABLE2;
				break;
			case 'n':
				goto LABLE1;
				break;
			}
		}
		case 2:
		{
			system("cls");
			std::cout << "Lich su thang thua\n";
			
		}
		case 3:
		{
			goto LABLE1;
			break;
		}
		default:
			std::cout << "Nhap lai lua chon: "; std::cin >> m_select1;;
		}
	}
	case 2:
	{
		system("cls");
		int m_select2;
		std::cout << "_____________Play with BOT_______________\n";
		std::cout << "1.Easy mode\n";
		std::cout << "2.Normal mode\n";
		std::cout << "3.Hard mode\n";
		std::cout << "4.Return to MENU\n";
		std::cout << "Selection: "; std::cin >> m_select2;
		switch (m_select2)
		{
		case 1:
		{
			char y;
		LABLE3:
			memset(Table, ' ', 256);
			do
			{
				system("cls");
				Show_table(Table);
				Easy_BOT(Table);
			} while (Check_state(Table) == 0);
			system("cls");
			Show_table(Table);
			switch (Check_state(Table))
			{
			case 1:
				std::cout << "You Win!";
				break;
			case 2:
				std::cout <<"BOT Win!";
				break;
			case 3:
				std::cout << " Draw " ;
			default:
				break;
			}
			do
			{
				std::cout << "\nBan co muon choi lai khong: y/n?"; std::cin >> y;
			} while (y != 'y' && y != 'n');
			switch (y)
			{
			case 'y':
				goto LABLE3;
				break;
			case 'n':
				goto LABLE1;
				break;
				break;
			}
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		default:
			break;
		}
	}
	default:
		break;
	}
}

void writefile(std::string file)
{
	std::ofstream fileoutput(file);
	if (fileoutput.fail()) {
		std::cout << "Cannot open file at " << file << std::endl;
		return;
	}
	fileoutput << file;
}
