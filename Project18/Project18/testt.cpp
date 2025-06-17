#include<iostream>
using namespace std;

void nhapmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu " << i << "  ";
		cin >> a[i];
	}

}int sapxep(int n)
{
	if (n % 2 == 0) return 1;
	else return 0;

}
void debai(int* a, int* b, int* c, int n)
{
	int demb = 0, demc = 0;
	for (int i = 0; i < n; i++)
	{
		if (sapxep(a[i]) == 1)
		{
			b[demb] = a[i]; demb++;
		}if (sapxep(a[i]) == 0)
		{
			c[demc] = a[i]; demc++;
		}
	}cout << " day so b chua chan" << endl;
	cout << "day co " << demb << "  phan tu  ";
	for (int j = 0; j < demb; j++)
	{
		cout << b[j] << "  ";
	}cout << endl;
	cout << " day so c chua le " << endl;
	cout << "day co " << demc << "  phan tu  ";
	for (int k = 0; k < demc; k++)
	{
		cout << c[k] << "  ";
	}
}




int main()
{
	int a[100], b[100], c[100], n;
	cout << "nhap vao so nguyen n "; cin >> n;
	nhapmang(a, n);
	debai(a, b, c, n);
	return 0;

}