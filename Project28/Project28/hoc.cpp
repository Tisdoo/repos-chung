#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int dem(string s)
{
	int count = 0;
	for (char c : s)
		if (c == ' ')
		{
			count++;
		}
	return count;
}

string last(string s)
{
	string lastword, word;
	stringstream ss(s);
	while (ss >> word)

	{
		lastword = word;

	}return lastword;



}
void swap(char& a, char& b)
{
	int temp = a;
	a = b;
	b = temp;
}
string daonguoc(string s)

{
	string tmp = s;
	int left = 0; int right = tmp.length() - 1;
	while (left < right)
	{
		swap(tmp[left], tmp[right]);
		left++; right--;


	}return tmp;
}
int main()
{
	string s = "kinh chao quy khach ml sang";
	cout << dem(s) << endl;
	cout << last(s) << endl << daonguoc(s);


	return 0;
}