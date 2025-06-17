#include<iostream>
using namespace std;
void Nhapmang(int a*, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao ky tu thu " << i << "  ";
		cin >> a[i];


	}
}
void dieukien(int* b, int* a; int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a || a[i] == u || a[i] == o || a[i] == i || a[i] == e || a[i] == A || a[i] == I || a[i] == U || a[i] == O || a[i] == E)
		{
			b[i] = b[a]; cout << "cac ky tu nguyen am cua day la   " << b[i];


	}
}
	int main()
	{
		int a[100], b[100]; int n = 0;
		cout << "nhap vao so ky tu cua mang   "; cin >> nl;
		Nhapmang(a, n);
		dieukien(b, a, n);
		return 0;
	}



