#include<iostream>
using namespace std;
void Nhapmang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap vao phan tu thu " << i<<"  :";
		cin >> A[i];
	}

}
int dandau(int *A,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] * A[i + 1] >= 0) return 0;

	}return 1;
}
bool dondieu(int* A, int n)
{
	int tang = true, giam = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] > A[i + 1]) tang = false;
		if (A[i] < A[i + 1]) giam = false;
	}return	tang || giam;

} int doixung(int* A, int n)
{
	for (int i = 0; i < n / 2; i++)
		if (A[i] == A[n - i - 1])return 1;
		else return 0;
			
}







int main()
{
	int A[100]; int n;
	
	cout << "nhap vao so luong phan tu n"<<":  ";
	cin >> n;
	Nhapmang(A, n);

	if (dandau(A, n) == 1)cout << " day  co dan dau"<<endl; else cout << "day ko co dan dau"<<endl;
	


	if (dondieu(A, n) == 1)cout << "day co tinh don dieu" << endl;else cout << "day ko co tinh don dieu" << endl;


	if(doixung(A, n)==1)cout << "day co doi xung" << endl; else cout << "day ko co doi xung" << endl;
	

 return 0;


}