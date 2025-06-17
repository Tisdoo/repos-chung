#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    char s[1001];
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;
    int length = strlen(s);
    sort(s, s + length);
    cout << "Chuoi \"" << s << "\" sau khi sap xep: " << s << endl;

    return 0;
}