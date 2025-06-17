#include<iostream>
using namespace std;
 
void readfile(char*& s) {
	const char* fn = "input.txt";
	FILE* fp = fopen(fn, "r");
	if (!fp)
		cout << "Cannot open file " << fn << endl;
	else
		cout << "Read file " << fn << endl;
	s = new char[200];
	fgets(s, 200, fp);
	
	if (*(s + strlen(s) - 1) == 10)
		*(s + strlen(s) - 1) = '\0';
	fclose(fp);
}
int main()
{
	char *s;
	readfile(s);
	cout << s;


	return 0;
}