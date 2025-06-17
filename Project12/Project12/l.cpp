#include<iostream>
#include<math.h>
using namespace std;



int tinhtong(int n)
{
	if (n == 1)return 1; else return tinhtong(n = n + (n - 1));
}










int main()
{
	int n;
	cin >> n; cout << tinhtong(n);

	return 0;

}