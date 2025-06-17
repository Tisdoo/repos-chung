#include<iostream>
using namespace std;
struct Phanso
{
	int a, b, c, d;
};
int main()
{
	Phanso ps;
	
	cout<<"nhap vao tu so 1..."; cin >> ps.a;
	cout << "nhap vao mau so 1..."; cin >> ps.b;
	cout << "nhap vao tu so 2..."; cin >> ps.c;
	cout << "nhap vao mau so 2..."; cin >> ps.d;
}