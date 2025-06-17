#include <iostream>
#include <cstring>

using namespace std;

struct LoaiHoa {
    char Ten[51];
    int SoLuong;
    char DVT[21]; // Don vi tinh
    double DonGia;
};

struct DanhSachLoaiHoa {
    LoaiHoa dsHoa[20];
    int SoLuong;
};

void NhapDanhSach(DanhSachLoaiHoa& ds) {
    cout << "Nhap so luong loai hoa (toi da 20): ";
    do {
        cin >> ds.SoLuong;
        if (ds.SoLuong < 0 || ds.SoLuong > 20) {
            cout << "So luong khong hop le. Nhap lai: ";
        }
    } while (ds.SoLuong < 0 || ds.SoLuong > 20);

    for (int i = 0; i < ds.SoLuong; ++i) {
        cout << "Nhap thong tin loai hoa thu " << i + 1 << ":" << endl;
        cout << "Ten loai hoa: ";
        cin >> ds.dsHoa[i].Ten;

        cout << "So luong: ";
        do {
            cin >> ds.dsHoa[i].SoLuong;
            if (ds.dsHoa[i].SoLuong < 0) {
                cout << "So luong khong hop le. Nhap lai: ";
            }
        } while (ds.dsHoa[i].SoLuong < 0);

        cout << "Don vi tinh: ";
        cin >> ds.dsHoa[i].DVT;

        cout << "Don gia: ";
        do {
            cin >> ds.dsHoa[i].DonGia;
            if (ds.dsHoa[i].DonGia < 0) {
                cout << "Don gia khong hop le. Nhap lai: ";
            }
        } while (ds.dsHoa[i].DonGia < 0);
    }
}

void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "Danh sach loai hoa:" << endl;
    for (int i = 0; i < ds.SoLuong; ++i) {
        cout << "Ten: " << ds.dsHoa[i].Ten
            << ", So luong: " << ds.dsHoa[i].SoLuong
            << ", Don vi tinh: " << ds.dsHoa[i].DVT
            << ", Don gia: " << ds.dsHoa[i].DonGia << endl;
    }
}

int TimLoaiHoa(DanhSachLoaiHoa ds, char* tenloai) {
    for (int i = 0; i < ds.SoLuong; ++i) {
        if (strcmp(ds.dsHoa[i].Ten, tenloai) == 0) {
            return i;
        }
    }
    return -1;
}

void XuLyBanHoa(DanhSachLoaiHoa& ds, char* tenloai, int soluong) {
    int index = TimLoaiHoa(ds, tenloai);
    if (index == -1) {
        cout << "Loai hoa khong ton tai." << endl;
        return;
    }

    if (ds.dsHoa[index].SoLuong < soluong) {
        cout << "Khong du so luong de ban." << endl;
    }
    else {
        double tongTien = soluong * ds.dsHoa[index].DonGia;
        cout << "Tong tien: " << tongTien << endl;
        ds.dsHoa[index].SoLuong -= soluong;
    }
}

int main() {
    DanhSachLoaiHoa ds;
    NhapDanhSach(ds);

    cout << "Thong tin danh sach loai hoa:" << endl;
    XuatDanhSach(ds);

    char tenHoa[51];
    int soLuong;

    cout << "Nhap ten loai hoa can mua: ";
    cin >> tenHoa;

    cout << "Nhap so luong can mua: ";
    cin >> soLuong;

    XuLyBanHoa(ds, tenHoa, soLuong);

    cout << "Thong tin danh sach loai hoa sau khi ban:" << endl;
    XuatDanhSach(ds);

    return 0;
}
