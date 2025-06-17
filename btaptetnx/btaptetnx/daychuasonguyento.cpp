#include<iostream>
#include<math.h>
using namespace std;
void nhapmang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu " << i << "  ";
		cin >> a[i];

	}

}int ktra(int n)
{
	if (n < 2)return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)return 0;
	}return 1;
}void debai(int* a, int* b, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
        if (ktra(a[i]) == 1) {
            b[dem] = a[i];
                dem++;
        }
	}if (dem == 0)cout << "day ko co so nguyen to";
	
	else {
		cout << "Mang chua cac so nguyen to " << endl;
		cout << "Day so co " << dem << " phan tu : ";
		for (int k = 0; k < dem; k++) cout << b[k] << "  ";
	}
}	





int main()
{
	int a[100], b[100], n;
	cout << " nhap vao so phan tu n "; cin >> n;
	nhapmang(a, n);
	debai(a, b, n);



	return 0;
}














