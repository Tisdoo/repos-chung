//MSSV: 3124411021
//Họ Tên:Nguyễn Hoàng ấn
//Lớp:DCT124C6
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void nhapmang(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> A[i];

}


// Tìm giá trị lớn nhất lớn nhì
void Giatri(int A[], int n, int& lon1, int& lon2)
{
	lon1 = INT16_MIN;
	lon2 = INT16_MIN;
	for (int i = 0; i < n; i++)
		//hàm kiểm tra giá trị lớn nhất lớn nhì
	{
		if (lon1 < A[i]) {
			lon2 = lon1; lon1 = A[i];
		}
		else if (lon2 < A[i] && lon2 != lon1)
		{
			lon2 = A[i];
		}

	}
}
// kiểm tra số nguyên tố
int ktrsSNT(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i < n / 2; i++)
	{
		if (n % i == 0)return 0;
	}return 1;
} //Hàm tính tổng số nguyên tố
int Tong(int A[], int n)
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		
		if (ktrsSNT(A[i])) {
			 tong = tong + A[i];
		}
	}return tong;
}
//hàm đếm số lần xuất hiện của các phần tử
void Sotrung(int A[], int n)
{
	{
		cout << "So lan xuat hien cua cac so trung la: ";
		vector<bool> dadem(n, false); // phải dùng thư viện vector để tránh tràn bộ nhớ
		for (int i = 0; i < n; i++)
		{
			if (!dadem[i])
			{
				int dem = 1;
				for (int j = i + 1; j < n; j++)
				{
					if (A[i] == A[j])
					{
						dadem[j] = { true };
						dem++;
					}
				}
				cout << A[i] << " xuat hien " << dem << " lan " << endl;
			}
		}
	}

}
//Hàm sắp xếp các phần tử trong mảng
