#include<iostream>
using namespace std;

int dequy(int n)
{
	int x = 1;

	for (int i = 2; i < n; i++)
	{
		x = 2 * x + x;
	}
	return x;

}




int main()
{
	int x = 1;
	cin >> n;
	cout>>dequy(n);
	
	return 0;
}