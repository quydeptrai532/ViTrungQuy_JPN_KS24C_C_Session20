#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char maSanPham[20];
    char tenSanPham[50];
    double giaNhap;
    double giaBan;
    int soLuong;
} SanPham;

SanPham danhSach[MAX];
int soLuongSanPham = 0;
double doanhThu = 0;

void nhapSanPham() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    if (n <= 0 || soLuongSanPham + n > MAX) {
        printf("So luong khong hop le hoac vuot qua gioi han.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        SanPham sp;
        printf("\nNhap thong tin san pham %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", sp.maSanPham);
        printf("Ten san pham: ");
        scanf(" %[^\n]s", sp.tenSanPham);
        printf("Gia nhap: ");
        scanf("%lf", &sp.giaNhap);
        printf("Gia ban: ");
        scanf("%lf", &sp.giaBan);
        printf("So luong: ");
        scanf("%d", &sp.soLuong);

        if (sp.giaNhap <= 0 || sp.giaBan <= 0 || sp.soLuong <= 0) {
            printf("Gia tri khong hop le. Bo qua san pham nay.\n");
            continue;
        }

        int found = 0;
        for (int j = 0; j < soLuongSanPham; j++) {
            if (strcmp(danhSach[j].maSanPham, sp.maSanPham) == 0) {
                danhSach[j].soLuong += sp.soLuong;
                found = 1;
                break;
            }
        }

        if (!found) {
            danhSach[soLuongSanPham++] = sp;
        }
    }
}

void hienThiSanPham() {
    if (soLuongSanPham == 0) {
        printf("Danh sach san pham trong.\n");
        return;
    }
    printf("\nDanh sach san pham:\n");
    printf("%-20s %-30s %-10s %-10s %-10s\n", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("%-20s %-30s %-10.2f %-10.2f %-10d\n", danhSach[i].maSanPham, danhSach[i].tenSanPham, danhSach[i].giaNhap, danhSach[i].giaBan, danhSach[i].soLuong);
    }
}

void capNhatSanPham() {
    char maSP[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", maSP);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSach[i].maSanPham, maSP) == 0) {
            printf("Nhap ten san pham moi: ");
            scanf(" %[^\n]s", danhSach[i].tenSanPham);
            printf("Nhap gia nhap moi: ");
            scanf("%lf", &danhSach[i].giaNhap);
            printf("Nhap gia ban moi: ");
            scanf("%lf", &danhSach[i].giaBan);
            printf("Nhap so luong moi: ");
            scanf("%d", &danhSach[i].soLuong);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

void sapXepSanPham(int tangDan) {
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if ((tangDan && danhSach[i].giaBan > danhSach[j].giaBan) || (!tangDan && danhSach[i].giaBan < danhSach[j].giaBan)) {
                SanPham temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

void timKiemSanPham() {
    char maSP[20];
    printf("Nhap ma san pham can tim: ");
    scanf("%s", maSP);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSach[i].maSanPham, maSP) == 0) {
            printf("%-20s %-30s %-10s %-10s %-10s\n", "Ma SP", "Ten SP", "Gia Nhap", "Gia Ban", "So Luong");
            printf("%-20s %-30s %-10.2f %-10.2f %-10d\n", danhSach[i].maSanPham, danhSach[i].tenSanPham, danhSach[i].giaNhap, danhSach[i].giaBan, danhSach[i].soLuong);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

void banSanPham() {
    char maSP[20];
    int soLuong;
    printf("Nhap ma san pham can ban: ");
    scanf("%s", maSP);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(danhSach[i].maSanPham, maSP) == 0) {
            if (danhSach[i].soLuong == 0) {
                printf("San pham da het hang.\n");
                return;
            }
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuong);
            if (soLuong > danhSach[i].soLuong) {
                printf("Khong du so luong san pham.\n");
                return;
            }
            danhSach[i].soLuong -= soLuong;
            doanhThu += soLuong * (danhSach[i].giaBan - danhSach[i].giaNhap);
            return;
        }
    }
    printf("San pham khong ton tai.\n");
}

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Cap nhat thong tin san pham\n");
        printf("4. Sap xep san pham theo gia (tang/giam)\n");
        printf("5. Tim kiem san pham\n");
        printf("6. Ban san pham\n");
        printf("7. Doanh thu hien tai\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapSanPham();
                break;
            case 2:
                hienThiSanPham();
                break;
            case 3:
                capNhatSanPham();
                break;
            case 4: {
                int tangDan;
                printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
                scanf("%d", &tangDan);
                sapXepSanPham(tangDan);
                break;
            }
            case 5:
                timKiemSanPham();
                break;
            case 6:
                banSanPham();
                break;
            case 7:
                printf("Doanh thu hien tai: %.2f\n", doanhThu);
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

