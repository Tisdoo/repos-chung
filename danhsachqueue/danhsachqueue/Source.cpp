#include<iostream>
using namespace std;


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void selectionsort(int A[], int n)
{
	int min;

	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[min] > A[j])
			{
				min = j;
			}
		}swap(A[min], A[i]);
	}
}
void bubblesort(int A[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] > A[j])
				swap(A[i], A[j]);
		}

}
void insertsort(int A[], int n)
{
	int pos;
	for (int i = 1; i < n; i++)
	{
		pos = i;
		while (pos > 0 && A[pos] < A[pos - 1])
		{
			swap(A[pos], A[pos - 1]); pos--;
		}

	}
}
int binarysearch(int A[], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int mid = (l + r) / 2;

	while (l < r)
	{
		if (A[mid] == x)
			return true;
		else if (A[mid] > x)
		{
			r = mid - 1;
			mid = (l + r) / 2;
		}
		else if (A[mid] < x)
		{
			l = mid + 1;
			mid = (l + r) / 2;
		}
	}return false;
}
// dùng đệ quy
int binary(int A[]), int n, int l, int r, int x)
{
	int mid=




}
void test1()
{
	int n =9;
	int A [] = {4, 3,7,9,5,3,2,5,0};
	insertsort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}




void test2()
{
	int n = 9; int x = 2;
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	if (binarysearch(A, n, x) == 1)
		cout << "found\n";
	else cout << "not found\n";



	cout << "----------------------------\n";
	int B[] = { 1,3,3,4,5,6,7,8,9 };
	if (binarysearch(B, n, x) == 1)
		cout << "found\n";
	else cout << "not found\n";
}








int main()
{
	//test1();
	test2();
	return 0;
}