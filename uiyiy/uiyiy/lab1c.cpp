#include <iostream>
#include <algorithm>

using namespace std;

struct NhanVien {
    char MaSo[11];
    char Ho[11];
    char Ten[51];
    int Phai; // 0: Nu, 1: Nam
    int ThamNien;
};

struct PhongBan {
    NhanVien aNhanVien[100];
    int SoLuong;
};

void NhapPhongBan(PhongBan& pb) {
    cout << "Nhap so luong nhan vien (toi da 100): ";
    do {
        cin >> pb.SoLuong;
        if (pb.SoLuong < 0 || pb.SoLuong > 100) {
            cout << "So luong nhan vien khong hop le. Nhap lai: ";
        }
    } while (pb.SoLuong < 0 || pb.SoLuong > 100);

    for (int i = 0; i < pb.SoLuong; ++i) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        cout << "Ma so: ";
        cin >> pb.aNhanVien[i].MaSo;

        cout << "Ho lot: ";
        cin >> pb.aNhanVien[i].Ho;

        cout << "Ten: ";
        cin >> pb.aNhanVien[i].Ten;

        cout << "Phai (0: Nu, 1: Nam): ";
        do {
            cin >> pb.aNhanVien[i].Phai;
            if (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1) {
                cout << "Phai khong hop le. Nhap lai (0: Nu, 1: Nam): ";
            }
        } while (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1);

        cout << "Tham nien: ";
        do {
            cin >> pb.aNhanVien[i].ThamNien;
            if (pb.aNhanVien[i].ThamNien < 0) {
                cout << "Tham nien khong hop le. Nhap lai: ";
            }
        } while (pb.aNhanVien[i].ThamNien < 0);
    }
}

void XuatPhongBan(PhongBan pb) {
    cout << "Danh sach nhan vien trong phong ban:" << endl;
    for (int i = 0; i < pb.SoLuong; ++i) {
        cout << "Ma so: " << pb.aNhanVien[i].MaSo
            << ", Ho lot: " << pb.aNhanVien[i].Ho
            << ", Ten: " << pb.aNhanVien[i].Ten
            << ", Phai: " << (pb.aNhanVien[i].Phai == 1 ? "Nam" : "Nu")
            << ", Tham nien: " << pb.aNhanVien[i].ThamNien << endl;
    }
}

void DemSiSo(PhongBan pb, int& soNam, int& soNu) {
    soNam = 0;
    soNu = 0;
    for (int i = 0; i < pb.SoLuong; ++i) {
        if (pb.aNhanVien[i].Phai == 1) {
            ++soNam;
        }
        else {
            ++soNu;
        }
    }
}

void SapXepTangTheoThamNien(PhongBan& pb) {
    sort(pb.aNhanVien, pb.aNhanVien + pb.SoLuong, [](NhanVien a, NhanVien b) {
        return a.ThamNien < b.ThamNien;
        });
}

int main() {
    PhongBan pb;
    NhapPhongBan(pb);

    cout << "Thong tin phong ban truoc khi sap xep:" << endl;
    XuatPhongBan(pb);

    int soNam, soNu;
    DemSiSo(pb, soNam, soNu);
    cout << "So nam: " << soNam << ", So nu: " << soNu << endl;

    SapXepTangTheoThamNien(pb);
    cout << "Thong tin phong ban sau khi sap xep tang dan theo tham nien:" << endl;
    XuatPhongBan(pb);

    return 0;
}
