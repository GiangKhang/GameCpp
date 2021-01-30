#include<iostream>
using namespace std;
#define Max 2020

void Nhapmang(int Arr[], int &a)
{
	for (int i = 0; i < a; i++)
	{
		cout << "Nhap vao phan tu Arr[" << i << "] la : " ;
		cin >> Arr[i];
	}
}

void Xuatmang(int Arr[], int& a)
{
	for (int i = 0; i < a; i++)
	{
		cout << Arr[i] << " ";
	}
}

/*void Noimang(int A[], int B[], int C[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		C[i] = A[i];
	}
	int k = 0;
	for (int i = n; i < (m + n) ; i++)
	{
		C[i] = B[k++];
	}
}*/
void 

int main()
{
	int Arr_n[Max], Arr_m[Max], Arr_nm[Max];
	int n,m;
	int Sz = m + n;
	cout << "So phan tu cua Arr_n (n >= 0) la : ";
	cin >> n;
	Nhapmang(Arr_n, n);
	cout << "So phan tu cua mang Arr_m (m < 2020) la : ";
	cin >> m;
	Nhapmang(Arr_m, m);
	cout << "Mang Arr_n : ";
	Xuatmang(Arr_n, n) ;
	cout << "\nMang Arr_m : ";
	Xuatmang(Arr_m, m);
	/*int Arr_nm[Max];
	int size = n + m;
	Noimang(Arr_n, Arr_m, Arr_nm, n, m);
	cout << endl;
	Xuatmang(Arr_nm, size);*/
	int Oddsz, Evensz;
	int Arr_odd[Max], Arr_even[Max];
	for (int i = 0; i < n; i++)
	{
		if (Arr_n[i] % 2 == 0)
		{
			Arr_odd[Oddsz] = Arr_n[i];
			Oddsz += 1;
		}
		else
		{
			Arr_even[Evensz] = Arr_n[i];
			Evensz += 1;
		}
	}
	for (int i = 0; i < m ; i++)
	{
		if (Arr_m[i] % 2 == 0)
		{
			Arr_odd[Oddsz] = Arr_m[i];
			Oddsz += 1;
		}
		else
		{
			Arr_even[Evensz] = Arr_m[i];
			Evensz += 1;
		}
	}

	return 0;
}