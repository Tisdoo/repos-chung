#include <iostream>
using namespace std;

void nhapmang(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao mang phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

int ktra(int* a, int n) {
    int chan = 0, le = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            chan++;
    }

    for (int i = 0; i < n - 1; i++) {
        if ((a[i] + a[i + 1]) % 2 != 0)
            le++;
    }

    if (chan == n)
        return 1; 
    else if (le == n - 1)
        return 0; 
    return -1; 
}

int main() {
    int a[100], n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;

    nhapmang(a, n);

    int result = ktra(a, n);
    if (result == 1) {
        cout << "Day co toan chan" << endl;
        cout << "Day khong co tinh chat chan le";
    }
    else if (result == 0) {
        cout << "Day co tinh chan le" << endl;
        cout << "Day khong co toan chan";
    }
    else {
        cout << "Day khong co ca 2 tinh chat";
    }

    return 0;
}