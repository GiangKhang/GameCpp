#include<iostream>
using namespace std;

int main()
{
	int nLength;
	cout << "Nhap vao do dai cua mang N = " ;
	cin >> nLength;
	int* nArr = new int[nLength];
	for (int i = 0; i < nLength; i++)
	{
		cout << "Nhap vao phan tu thu " << i << "cua mang Arr[" << i << "] = ";
		cin >> nArr[i];
	}

	cout << "Day cac so vua nhap la : ";
	for (int i = 0; i < nLength; i++)
	{
		cout << nArr[i]<< " ";
	}

	return 0;
}