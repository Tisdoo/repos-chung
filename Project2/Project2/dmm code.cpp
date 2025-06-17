#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath> // Thư viện dùng cho hàm sqrt
using namespace std;

// Hàm nhập mảng
void nhapmang(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhập phần tử thứ " << i + 1 << ": ";
        cin >> A[i];
    }
}

// Hàm tìm giá trị lớn nhất, lớn nhì
void Giatri(int A[], int n, int& lon1, int& lon2) {
    lon1 = INT16_MIN;
    lon2 = INT16_MIN;
    for (int i = 0; i < n; i++) {
        if (A[i] > lon1) {
            lon2 = lon1;
            lon1 = A[i];
        }
        else if (A[i] > lon2 && A[i] != lon1) {
            lon2 = A[i];
        }
    }
}

// Hàm kiểm tra số nguyên tố
int ktrsSNT(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {  // Chạy từ 2 đến sqrt(n)
        if (n % i == 0) return 0;
    }
    return 1;
}

// Hàm tính tổng các số nguyên tố
int Tong(int A[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (ktrsSNT(A[i])) {
            tong += A[i];
        }
    }
    return tong;
}

// Hàm đếm số lần xuất hiện của các phần tử trong mảng
void Sotrung(int A[], int n) {
    cout << "Số lần xuất hiện của các phần tử là: " << endl;
    vector<bool> dadem(n, false); // Sử dụng vector để tránh tràn bộ nhớ
    for (int i = 0; i < n; i++) {
        if (!dadem[i]) {
            int dem = 1;
            for (int j = i + 1; j < n; j++) {
                if (A[i] == A[j]) {
                    dadem[j] = true;
                    dem++;
                }
            }
            cout << A[i] << " xuất hiện " << dem << " lần." << endl;
        }
    }
}

// Hàm sắp xếp mảng theo thứ tự tăng dần (bubble sort)
void sapXep(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                // Hoán đổi A[j] và A[j+1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Hàm xuất mảng
void xuatmang(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Chương trình chính
int main() {
    int n;
    cout << "Nhập số phần tử của mảng: ";
    cin >> n;

    int A[100];
    nhapmang(A, n);

    // Gọi hàm xuất mảng
    cout << "Mảng vừa nhập: ";
    xuatmang(A, n);

    // Tìm giá trị lớn nhất và lớn nhì
    int lon1, lon2;
    Giatri(A, n, lon1, lon2);
    cout << "Giá trị lớn nhất là: " << lon1 << endl;
    cout << "Giá trị lớn nhì là: " << lon2 << endl;

    // Tính tổng các số nguyên tố
    cout << "Tổng các số nguyên tố trong mảng là: " << Tong(A, n) << endl;

    // Đếm số lần xuất hiện của các phần tử
    Sotrung(A, n);

    // Sắp xếp mảng
    sapXep(A, n);
    cout << "Mảng sau khi sắp xếp tăng dần: ";
    xuatmang(A, n);

    return 0;
}
