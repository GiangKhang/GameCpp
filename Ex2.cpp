#include<iostream>
using namespace std;

void inputArrayextend()
{
	int maxsize = 2;
	char* p = new char[maxsize];
	short nowsize = 0 ;
	char* q;
	char c;
	do
	{
		cout << "Nhap vao so nguyen duong n (0 <= n < 10)";
		cin >> c;
		if (c == 64)
			break;
		else if (c< 48 || c>= 57)
		{
			continue;
		}
		else
		{
			nowsize += 1;
			cout << "Kich thuoc cua mang hien tai la : " << nowsize << endl;
			if (nowsize < maxsize) {
				p[nowsize - 1] = c;
				continue;
			}
			else
			{
				maxsize = 2 * maxsize;
				q = new char[maxsize];
				for (int i = 0; i < maxsize; i++)
				{
					q[i] = p[i];
				}
				delete p;
				p = new char[maxsize];
				for (int i = 0; i < maxsize; i++)
				{
					p[i] = q[i];
				}
				delete q;
			}
		}
	} while (1);
}
int main()
{
	inputArrayextend();
	
	return 0;
}