#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
void caua(int A[], int n, int& max1, int& max2)
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[j + 1])
			{
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}


		}max1 = A[0];
	max2 = A[1];

}int snt(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 0;

	}return 1;
}






using namespace std;
int main()
{
	int max1, max2;
	int n; int A[100];
	ifstream inp("songuyen.inp");
	ofstream oup("ketqua.out");
	inp >> n;
	for (int i = 0; i < n; i++)
	{
		inp >> A[i];
	}
	caua(A, n, max1, max2);
	oup << max1 << " " << max2;


}