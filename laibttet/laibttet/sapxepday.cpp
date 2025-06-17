#include<iostream>
using namespace std;
void nhapmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu " << i << "   ";
		cin >> a[i];

	}
}void nhapmang(int* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu " << i << "   ";
		cin >> b[i];

	}
}
void nhapvaomangc(int* a, int* c, int n,int j,int*b)
{
	for (int i = 0; i < n; i++)

	{
		c[i] = a[i];
}for(int k=n;k<n+j;k++)
{
	c[k] = b[k];

}
}






int main()
{
	int a[100], b[100], c[100];
	int n = 0; int k = 0; cout << "day so a";
	cout << "nhap vao so phan tu "; cin >> n;
	nhapmang(a, n);
	cout << "day so b";
	cout << "nhap vao so phan tu "; cin >> k;
	for (int i = 0; i < n + k; i++)cout << c[i];


	return 0;
}