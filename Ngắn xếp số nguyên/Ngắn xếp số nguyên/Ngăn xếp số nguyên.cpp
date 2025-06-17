#include <iostream>
#include <string>
using namespace std;

// Ngăn xếp sử dụng mảng
struct stack {
    int top;
    int size;
    int* mang;
};

// Khởi tạo ngăn xếp
void init(stack& s, int size) {
    s.top = -1;
    s.size = size;
    s.mang = new int[size];
}

// Kiểm tra ngăn xếp rỗng
bool Empty(stack& s) {
    return s.top == -1;
}

// Kiểm tra ngăn xếp đầy
bool Full(stack& s) {
    return s.top == s.size - 1;
}

// Đẩy phần tử vào ngăn xếp
void push(stack& s, int x) {
    if (Full(s)) {
        cout << "Ngan xep day!" << endl;
        return;
    }
    s.mang[++s.top] = x;
}

// Lấy phần tử ra khỏi ngăn xếp
int pop(stack& s) {
    if (Empty(s)) {
        cout << "Ngan xep rong!" << endl;
        return -1;
    }
    return s.mang[s.top--];
}

// Xóa toàn bộ ngăn xếp và giải phóng bộ nhớ
void Xoa(stack& s) {
    delete[] s.mang;
    s.top = -1;
}

struct node {
    int info;
    node* next;
};

struct stacklist {
    node* top;
};

// Khởi tạo ngăn xếp liên kết
void initstacklist(stacklist& s) {
    s.top = NULL;
}

// Kiểm tra ngăn xếp liên kết rỗng
bool Emptylist(stacklist& s) {
    return s.top == NULL;
}

// Đẩy phần tử vào ngăn xếp liên kết
void pushlist(stacklist& s, int x) {
    node* newnode = new node;
    newnode->info = x;
    newnode->next = s.top;
    s.top = newnode;
}

// Lấy phần tử ra khỏi ngăn xếp liên kết
int poplist(stacklist& s) {
    if (Emptylist(s)) {
        cout << "Ngan xep rong!" << endl;
        return -1;
    }
    int gtri = s.top->info;
    node* tmp = s.top;
    s.top = s.top->next;
    delete tmp;
    return gtri;
}

// Xem phần tử trên cùng của ngăn xếp liên kết
int peeklist(stacklist& s) {
    if (Emptylist(s)) return -1;
    return s.top->info;
}

// Xóa toàn bộ ngăn xếp liên kết
void XoaNganXepLienKet(stacklist& s) {
    while (!Emptylist(s)) poplist(s);
}
// (b) Đảo ngược số bằng ngăn xếp
int DaoSo(int so) {
   stack s;
    init(s, 10);

    while (so > 0) {
        push(s, so % 10);
        so /= 10;
    }

    int ketqua = 0;
    int heSo = 1; // Hệ số nhân để ghép các chữ số đúng vị trí
    while (!Empty(s)) {
        ketqua += pop(s) * heSo;
        heSo *= 10;
    }
    Xoa(s); // Giải phóng bộ nhớ
    return ketqua;
}

// (c) Kiểm tra xâu có đối xứng không
bool DoiXung(string xau) {
    stack s;
    init(s, xau.length());

    for (char kyTu : xau) push(s, kyTu);

    string Daochuoi = "";
    while (!Empty(s)) {
        Daochuoi += (char)pop(s);
    }

    Xoa(s); // Giải phóng bộ nhớ
    return Daochuoi == xau;
}

// (d) Chuyển đổi số thập phân sang nhị phân
string ThapPhanSangNhiPhan(int so) {
    stack s;
    init(s, 32);

    while (so > 0) {
        push(s, so % 2);
        so /= 2;
    }

    string nhiPhan = "";
    while (!Empty(s)) {
        nhiPhan += to_string(pop(s));
    }

    Xoa(s); // Giải phóng bộ nhớ
    return nhiPhan;
}
void test()
{

    cout << "CauB " << DaoSo(12345) << endl;
    cout << "CauC " << (DoiXung("madam") ? "Co" : "Khong") << endl;
    cout << "CauD " << ThapPhanSangNhiPhan(25) << endl;
    
}
int main() {
    test();
    return 0;
}
