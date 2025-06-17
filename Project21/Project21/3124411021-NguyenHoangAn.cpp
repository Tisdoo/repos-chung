#include <iostream>
#include <string>

using namespace std;

void TachVaInTu(const string& s) {
    string word = "";

    for (char c : s) {
        if (c != ' ') { 
            word += c;
        }
        else if (!word.empty()) { 
            cout << "\"" << word << "\"" << endl;
            word = ""; 
        }
    }

    
    if (!word.empty()) {
        cout << "\"" << word << "\"" << endl;
    }
}

int main() {
    string s;
    cout << "Moi ban nhap chuoi s: ";
    getline(cin, s);

    cout << "Cac tu trong chuoi \"" << s << "\":" << endl;
    TachVaInTu(s);

    return 0;
}
