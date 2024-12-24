#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char maSach[20];
    char tenSach[50];
    char tacGia[50];
    double giaTien;
    char theLoai[30];
} Sach;

Sach danhSach[MAX];
int soLuongSach = 0;

void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);
    for (int i = 0; i < soLuongSach; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", danhSach[i].maSach);
        printf("Ten sach: ");
        scanf(" %[^\n]", danhSach[i].tenSach);
        printf("Tac gia: ");
        scanf(" %[^\n]", danhSach[i].tacGia);
        printf("Gia tien: ");
        scanf("%lf", &danhSach[i].giaTien);
        printf("The loai: ");
        scanf(" %[^\n]", danhSach[i].theLoai);
    }
}

void hienThiThongTinSach() {
    printf("\nDanh sach sach:\n");
    printf("%-15s %-30s %-30s %-10s %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia Tien", "The Loai");
    for (int i = 0; i < soLuongSach; i++) {
        printf("%-15s %-30s %-30s %-10.2f %-20s\n", danhSach[i].maSach, danhSach[i].tenSach, danhSach[i].tacGia, danhSach[i].giaTien, danhSach[i].theLoai);
    }
}

void themSachVaoViTri() {
    int viTri;
    if (soLuongSach >= MAX) {
        printf("Khong the them sach. Danh sach day.\n");
        return;
    }
    printf("Nhap vi tri muon them (0-%d): ", soLuongSach);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > soLuongSach) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = soLuongSach; i > viTri; i--) {
        danhSach[i] = danhSach[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", danhSach[viTri].maSach);
    printf("Ten sach: ");
    scanf(" %[^\n]", danhSach[viTri].tenSach);
    printf("Tac gia: ");
    scanf(" %[^\n]", danhSach[viTri].tacGia);
    printf("Gia tien: ");
    scanf("%lf", &danhSach[viTri].giaTien);
    printf("The loai: ");
    scanf(" %[^\n]", danhSach[viTri].theLoai);
    soLuongSach++;
}

void xoaSachTheoMa() {
    char maSach[20];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", maSach);
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSach[i].maSach, maSach) == 0) {
            for (int j = i; j < soLuongSach - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            soLuongSach--;
            printf("Da xoa sach.\n");
            return;
        }
    }
    printf("Khong tim thay sach.\n");
}

void capNhatSachTheoMa() {
    char maSach[20];
    printf("Nhap ma sach can cap nhat: ");
    scanf("%s", maSach);
    for (int i = 0; i < soLuongSach; i++) {
        if (strcmp(danhSach[i].maSach, maSach) == 0) {
            printf("Nhap ten sach moi: ");
            scanf(" %[^\n]", danhSach[i].tenSach);
            printf("Nhap tac gia moi: ");
            scanf(" %[^\n]", danhSach[i].tacGia);
            printf("Nhap gia tien moi: ");
            scanf("%lf", &danhSach[i].giaTien);
            printf("Nhap the loai moi: ");
            scanf(" %[^\n]", danhSach[i].theLoai);
            printf("Da cap nhat thong tin sach.\n");
            return;
        }
    }
    printf("Khong tim thay sach.\n");
}

void sapXepSachTheoGia(int tangDan) {
    for (int i = 0; i < soLuongSach - 1; i++) {
        for (int j = i + 1; j < soLuongSach; j++) {
            if ((tangDan && danhSach[i].giaTien > danhSach[j].giaTien) || (!tangDan && danhSach[i].giaTien < danhSach[j].giaTien)) {
                Sach temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

void timKiemSachTheoTen() {
    char tenSach[50];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", tenSach);
    printf("\nKet qua tim kiem:\n");
    printf("%-15s %-30s %-30s %-10s %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia Tien", "The Loai");
    int found = 0;
    for (int i = 0; i < soLuongSach; i++) {
        if (strstr(danhSach[i].tenSach, tenSach)) {
            printf("%-15s %-30s %-30s %-10.2f %-20s\n", danhSach[i].maSach, danhSach[i].tenSach, danhSach[i].tacGia, danhSach[i].giaTien, danhSach[i].theLoai);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach.\n");
    }
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                hienThiThongTinSach();
                break;
            case 3:
                themSachVaoViTri();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                capNhatSachTheoMa();
                break;
            case 6: {
                int tangDan;
                printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                scanf("%d", &tangDan);
                sapXepSachTheoGia(tangDan);
                break;
            }
            case 7:
                timKiemSachTheoTen();
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 8);

    return 0;
}

