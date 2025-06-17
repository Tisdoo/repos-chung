#include <iostream>
using namespace std;

void Nhapmang(char* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao ky tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void dieukien(char* b, char* a, int n) {
    int k = 0; 
    for (int i = 0; i < n; i++) {
       
        if (a[i] == 'a' || a[i] == 'u' || a[i] == 'o' || a[i] == 'i' || a[i] == 'e' ||a[i] == 'A' || a[i] == 'U' || a[i] == 'O' || a[i] == 'I' || a[i] == 'E') {
            b[k++] = a[i]; 
        }
    }

    
    cout << "Cac ky tu nguyen am trong day la: ";
    for (int i = 0; i < k; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    char a[100], b[100];
    int n;

    cout << "Nhap so ky tu cua mang: ";
    cin >> n;

    Nhapmang(a, n);
    dieukien(b, a, n);

    return 0;
}
