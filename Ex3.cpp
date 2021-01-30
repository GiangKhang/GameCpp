#include<iostream>
#include<string.h>
using namespace std;

bool checkcharac(string, )
{
	for (size_t i = 0; i < sizeof ; i++)
	{

	}
}

void Comp() {
	string Str1, Str2;

	do
	{
		cout << "Nhap vao chuoi s1 la : ";
		cin >> Str1;
		cout << "Nhap vao chuoi s2 la : ";
		cin >> Str2;

		int result = strcmp( Str1, Str2);
		if (result > 0)
			cout << "Chuoi can tim la s1 : " << Str1;
		else if (result < 0)
		{
			cout << "Chuoi can tim la : " << Str2;
		}
		else
		{
			cout << "s1 = s2";
		}
	} while (1);
}

int main()
{
	
	Comp();


	return 0;
}