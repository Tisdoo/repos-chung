#include <iostream>
#include <string>

using namespace std;


bool LaChuoiDoiXung(const string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false; 
        }
        left++;
        right--;
    }
    return true; 
}

int main() {
    string s;
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;

    if (LaChuoiDoiXung(s)) {
        cout << "Chuoi \"" << s << "\" la doi xung." << endl;
    }
    else {
        cout << "Chuoi \"" << s << "\" khong la doi xung." << endl;
    }

    return 0;
}
