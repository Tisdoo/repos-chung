#include <iostream>
using namespace std;

void nhapmang(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void nhapvaomangc(int* a, int* c, int n, int j, int* b) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (int k = n; k < n + j; k++) {
        c[k] = b[k - n]; 
    }
}
void SapXep(int* c, int m) {
    for (int i = 0; i < m - 1; i++) {
        int min = i;
        for (int j = i + 1; j < m; j++) {
            if (c[j] < c[min]) {
                min = j;
            }
        }
     
        if (min!= i) {
            int temp = c[i];
            c[i] = c[min];
            c[min] = temp;
        }
    }
}
int main() {
    int a[100], b[100], c[100];
    int n = 0, k = 0;

    cout << "Day so a" << endl;
    cout << "Nhap vao so phan tu: ";
    cin >> n;
    nhapmang(a, n);

  
    cout << "Day so b" << endl;
    cout << "Nhap vao so phan tu: ";
    cin >> k;
    nhapmang(b, k);

    
    nhapvaomangc(a, c, n, k, b);

    SapXep(c, n + k);
    cout << "Day so c "<<endl<<"day co "<<n+k<<"  phan tu : ";
    for (int i = 0; i < n + k; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
