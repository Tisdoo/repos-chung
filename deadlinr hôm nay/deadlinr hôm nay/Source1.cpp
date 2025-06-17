//3124411021-Nguyễn Hoàng Ấn
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


void readFile(int*& a, int& n, string& s, string& x, const string& name) {
    ifstream fin(name);


    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }


    fin.ignore();


    getline(fin, s);


    getline(fin, x);

    fin.close();
}

int SNT(int num)
{
    if (num < 2) return 0;


    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return 0;
    }
    return 1;
}


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sort(int* a, int n)
{
    // Tạo mảng tạm để lưu kết quả
    int* temp = new int[n];
    int demSNT = 0;
    int demnotSNT = 0;
    for (int i = 0; i < n; i++) {
        if (SNT(a[i])) {
            demSNT++;
        }
    }

    // Tạo mảng chứa số nguyên tố và không phải nguyên tố
    int* snt = new int[demSNT];
    int* kosnt = new int[n - demnotSNT];

    int pos = 0, pos0 = 0;
    for (int i = 0; i < n; i++) {
        if (SNT(a[i])) {
            snt[pos++] = a[i];
        }
        else {
            kosnt[pos0++] = a[i];
        }
    }

    sort(snt, demSNT);
    sort(kosnt, n - demnotSNT);

    // Gộp vào mảng kết quả
    int poss = 0;
    for (int i = 0; i < demSNT; i++) {
        temp[poss++] = snt[i];
    }
    for (int i = 0; i < n - demSNT; i++) {
        temp[poss++] = kosnt[i];
    }

    // Sao chép lại vào mảng ban đầu
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    // Giải phóng bộ nhớ
    delete[] snt;
    delete[] kosnt;
    delete[] temp;
}


// hàm đếm chuỗi
int demchuoi(const string& s, const string& x) {
    int count = 0;
    size_t dodaix = x.length();
    size_t dodais = s.length();

    if (dodaix == 0 || dodais < dodaix) return 0;

    for (size_t i = 0; i <= dodais - dodaix; i++) {
        bool found = true;
        for (size_t j = 0; j < dodaix; j++) {
            if (s[i + j] != x[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            count++;
            i += dodaix - 1; // Nhảy qua chuỗi vừa tìm thấy
        }
    }

    return count;
}



// Hàm tìm từ dài nhất trong chuỗi s
string longest(const string& s) {
    string longestWord;
    string tmp;

    for (char c : s) {
        if (c == ' ') {
            if (tmp.length() > longestWord.length()) {
                longestWord = tmp;
            }
            tmp.clear();
        }
        else {
            tmp += c;
        }
    }

    // Kiểm tra từ cuối cùng
    if (tmp.length() > longestWord.length()) {
        longestWord = tmp;
    }

    return longestWord;
}

// Hàm ghi kết quả ra file
void writeFile(int* a, int n, int count, const string& longestWord, const string& name) {
    ofstream fout(name);

    // Ghi mảng đã sắp xếp
    for (int i = 0; i < n; i++) {
        fout << a[i];
        if (i < n - 1) fout << " ";
    }
    fout << endl;

    // Ghi số lần xuất hiện
    fout << count << endl;

    // Ghi từ dài nhất
    fout << longestWord << endl;

    fout.close();
}


int main() {
    int* a = nullptr;
    int n;
    string s, x;

    // 1. Đọc file input và in ra console
    readFile(a, n, s, x, "DE03.INP");
    cout << "Mang doc duoc: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Chuoi s: " << s << endl;
    cout << "Chuoi x: " << x << endl;

    // 2. Sắp xếp mảng theo yêu cầu và in ra
    sort(a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 3. Đếm số lần xuất hiện của x trong s và in ra
    int dem = demchuoi(s, x);
    cout << "So lan xuat hien cua x trong s: " << dem << endl;

    // 4. Tìm từ dài nhất trong s và in ra
    string Longest = longest(s);
    cout << "Tu dai nhat trong s: " << longest << endl;

    // 5. Ghi kết quả ra file
    writeFile(a, n, dem, Longest, "DE03.OUT");

    // Giải phóng bộ nhớ
    delete[] a;

    return 0;
}