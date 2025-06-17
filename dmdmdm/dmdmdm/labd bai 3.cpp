#include<iostream>
#include<string >
using namespace std;
void debai(string &s, int k,char c)
{
	if (k >= 0 && k <= s.length()) {
		s.insert(k, 1, c);
	}
	else {
		cout << "loi chuong trinh" << endl;
	}
}





int main()
{
	string s; int k; char c;
	cout << " Moi ban nhap chuoi s :"; getline(cin, s);
	cout << "Moi ban nhap vi tri can chen:  "; cin >> k;
	cout << "Moi ban nhap ky tu chen: "; cin >> c;
	string s1 = s; cout << "Chuoi " << s1 << " sau khi them ky tu  " << c << " vao vi tri " << k<<"  ";
	debai(s, k, c); cout << s;



	return 0;
}