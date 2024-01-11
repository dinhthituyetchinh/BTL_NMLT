#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>


//Cau 1
struct dsChamCong
{
	int thang;
	int nam;
	int ngay;
	int soSP;
	float tienCong;
};

typedef struct CongNhan
{
	char mscn[11];
	char hoTen[36];
	char gioiTinh[6];
	char phanXuong[21];
	float heSoLuong;
	char chucVu[31];
	int phuCap;
	dsChamCong chamCong;
} CN;
//Ham nguyen mau
void MENU();
void docFile1CN(FILE*& f, CN& cn);
void docFileDSCN(FILE*& f, CN a[], int& n);
void xuat1CN(CN cn);
void XuatMangDSCN(CN a[], int n);
int tongNgayCong1CN(CN cn);
int tongSoSP1CN(CN cn);
float luonghangthang1CN(CN cn);
float tongluong1CN(CN cn);
void xuatLuong1CN(CN cn);
void XuatLuongCN(CN cn[], int n);
void xuatTongLuongCaoNhatMax(CN cn[], int n);
void themCN(CN cn[], int& n);
void xoaNhanVien(CN cn[], int& n, int k);
void xoaDSNhanVienCoThangChamCongCoNgayCongNhoHon20(CN cn[], int& n);
void xoaNhanVienChuaCoDanhSachChamCong(CN cn[], int& n);
void TongNgayCong(CN cn[], int n);
int demSoCongNhan(CN a[], int n);
void luongCaoNhatNam2020(CN a[], int n);
void tongSoSPCaoNhat(CN a[], int n);
void tongNgayCongVaTongLuongcuaCN(CN a[], int n);
void sapXepDSChamCongGiamDanTheoSP(CN a[], int n);
void xuat1CNSauKhiTangTienCongToTruong(CN cn);
void  tienCongChoToTruong(CN a[], int n);
void baiII()
{
	int c;
	FILE* f;
	CN a[100];
	int n;
	do
	{
		system("cls");
		MENU();
		printf("Moi ban nhap lua chon: ");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			printf(" 1. Doc thong tin cong nhan tu tep tin van ban.\n");
			docFileDSCN(f, a, n);
			printf("Vui long nhan Enter de tiep tuc.\n");
			system("pause");
			break;
		case 2:
			printf(" 2. Xuat thong tin cua cac cong nhan.\n");
			XuatMangDSCN(a, n);
			system("pause");
			break;
		case 3:
			printf(" 3. Nhap vao nam va ma so cong nhan, xuat thong tin bang luong cua nam.\n");
			XuatLuongCN(a, n);
			system("pause");
			break;
		case 4:
			printf(" 4. Xuat thong tin cong nhan co tong luong cao nhat va tong luong thap nhat trong mot nam cho truoc.\n");
			xuatTongLuongCaoNhatMax(a, n);
			system("pause");
			break;
		case 5:
			printf(" 5. Them thong tin cua mot cong nhan vao danh sach.\n");
			themCN(a, n);
			XuatMangDSCN(a, n);
			system("pause");
			break;
		case 6:
			printf(" 6. Xoa danh sach cac thang cham cong ma co ngay cong <20 cua cong nhan co ma so cho truoc.\n");
			xoaDSNhanVienCoThangChamCongCoNgayCongNhoHon20(a, n);
			system("pause");
			break;
		case 7:
			printf(" 7. Xoa cac cong nhan ma chua co thong tin cham cong.\n");
			xoaNhanVienChuaCoDanhSachChamCong(a, n);
			system("pause");
			break;
		case 8:
			printf(" 8. Tinh tong so ngay cong va tong so thang da tung lam cua cong nhan.\n");
			TongNgayCong(a, n);
			system("pause");
			break;
		case 9:
			printf(" 9. Dem so cong nhan co ngay cong trong thang 12 nam 2021 tu 24 tro len va xuat ra thong tin cua cac cong nhan nay.\n");
			demSoCongNhan(a, n);
			system("pause");
			break;
		case 10:
			printf("10. Cho biet luong cao nhat trong thang 12 nam 2020 va thong tin cua cong nhan co luong cao nhat.\n");
			luongCaoNhatNam2020(a, n);
			system("pause");
			break;
		case 11:
			printf("11. Tinh tong so san pham cao nhat ma mot cong nhan da lam trong nam 2020.\n");
			tongSoSPCaoNhat(a, n);
			system("pause");
			break;
		case 12:
			printf("12. Tinh tong ngay cong va tong luong trong nam 2020 cua mot phan xuong cho truoc.\n");
			tongNgayCongVaTongLuongcuaCN(a, n);
			system("pause");
			break;
		case 13:
			printf("13. Sap xep danh sach cong nhan tang dan theo ten, danh sach cham cong giam dan theo moi san pham.\n");
			sapXepDSChamCongGiamDanTheoSP(a, n);
			XuatMangDSCN(a, n);
			system("pause");
			break;
		case 14:
			printf("14. Cap nhat tang them 15 phan tram tien cong tu thang 12 nam 2021 cho nhung cong nhan co chuc vu to truong.\n");
			tienCongChoToTruong(a, n);
			system("pause");
			break;
		case 0:
			printf("Ban da chon thoat chuong trinh.\n");
			break;
		default:
			printf("So ban nhap khong co trong chuong trinh!\nVui long nhap lai!!!\n(So ban nhap phai trong khoang tu 1 den 14)\n");
			printf("Vui long nhan Enter de tiep tuc.\n");
			system("pause");
			break;
		}
	} while (c != 0);
	_getch;
}
void MENU()
{
	printf("===================================================== = MENU = ===================================================\n");
	printf("\t\tHay chon chuong trinh ma ban can thuc hien:\n");
	printf(" 1. Doc thong tin cong nhan tu tep tin van ban.\n");
	printf(" 2. Xuat thong tin cua cac cong nhan.\n");
	printf(" 3. Nhap vao nam va ma so cong nhan, xuat thong tin bang luong cua nam.\n");
	printf(" 4. Xuat thong tin cong nhan co tong luong cao nhat va tong luong thap nhat trong mot nam cho truoc.\n");
	printf(" 5. Them thong tin cua mot cong nhan vao danh sach.\n");
	printf(" 6. Xoa danh sach cac thang cham cong ma co ngay cong <20 cua cong nhan co ma so cho truoc.\n");
	printf(" 7. Xoa cac cong nhan ma chua co thong tin cham cong.\n");
	printf(" 8. Tinh tong so ngay cong va tong so thang da tung lam cua cong nhan.\n");
	printf(" 9. Dem so cong nhan co ngay cong trong thang 12 nam 2021 tu 24 tro len va xuat ra thong tin cua cac cong nhan nay.\n");
	printf("10. Cho biet luong cao nhat trong thang 12 nam 2020 va thong tin cua cong nhan co luong cao nhat.\n");
	printf("11. Tinh tong so san pham cao nhat ma mot cong nhan da lam trong nam 2020.\n");
	printf("12. Tinh tong ngay cong va tong luong trong nam 2020 cua mot phan xuong cho truoc.\n");
	printf("13. Sap xep danh sach cong nhan tang dan theo ten, danh sach cham cong giam dan theo moi san pham.\n");
	printf("14. Cap nhat tang them 15 phan tram tien cong tu thang 12 nam 2021 cho nhung cong nhan co chuc vu to truong.\n");
	printf(" Neu ban muon thoat chuong trinh hay nhap so 0.\n");
	printf("===================================================================================================================\n");
	_getch;
}
//Cau 2
void docFile1CN(FILE*& f, CN& cn)
{
	fflush(stdin);
	fscanf(f, "%s ", cn.mscn);
	fflush(stdin);
	fgets(cn.hoTen, 35, f);
	fscanf(f, "%s ", cn.gioiTinh);
	fscanf(f, "%s ", cn.phanXuong);
	fscanf(f, "%f ", &cn.heSoLuong);
	fgets(cn.chucVu, 30, f);
	fscanf(f, "%d ", &cn.phuCap);
	fscanf(f, "%d ", &cn.chamCong.thang);
	fscanf(f, "%d ", &cn.chamCong.nam);
	fscanf(f, "%d ", &cn.chamCong.ngay);
	fscanf(f, "%d ", &cn.chamCong.soSP);
	fscanf(f, "%f ", &cn.chamCong.tienCong);
}
void docFileDSCN(FILE*& f, CN a[], int& n)
{
	f = fopen("DuLieuII.txt", "r+t");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		docFile1CN(f, a[i]);
	}
	fclose(f);
	if (n != 0)
		printf("\nDoc file thanh cong.\n");
	else
		printf("\nDoc file that bai, vui long thu lai.\n ");
}
//Cau 3
void xuat1CN(CN cn)
{
	printf("\tMSCN: %s", cn.mscn);
	printf("\tHo ten: %s", cn.hoTen);
	printf("\tGioi tinh: %s", cn.gioiTinh);
	printf("\tPhan xuong: %s", cn.phanXuong);
	printf("\tHe so luong: %.1f", cn.heSoLuong);
	printf("\tChuc vu: %s\n", cn.chucVu);
	printf("\tPhu Cap: %dVND", cn.phuCap);
	printf("\tThang: %d", cn.chamCong.thang);
	printf("\tNam: %d", cn.chamCong.nam);
	printf("\tNgay Cong: %d", cn.chamCong.ngay);
	printf("\tSo san pham: %d", cn.chamCong.soSP);
	printf("\tTien cong 1 san pham: %.1fVND\n", cn.chamCong.tienCong);
}
void XuatMangDSCN(CN a[], int n)
{
	printf("Danh sach cong nhan la:\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n\t\t====================================================================\n");
		printf("\nSTT %d", i + 1);
		xuat1CN(a[i]);
		printf("\n");
	}
}
// Cau 4
int tongNgayCong1CN(CN cn)
{
	int tongngaycong;
	tongngaycong = cn.chamCong.ngay * cn.chamCong.thang;
	return tongngaycong;
}
int tongSoSP1CN(CN cn)
{
	int tongsosp;
	tongsosp = cn.chamCong.ngay * cn.chamCong.thang * cn.chamCong.soSP;
	return tongsosp;
}
float luonghangthang1CN(CN cn)
{
	float luonghangthang;
	luonghangthang = cn.heSoLuong * cn.chamCong.ngay + cn.chamCong.tienCong * cn.chamCong.soSP + cn.phuCap;
	return luonghangthang;
}
float tongluong1CN(CN cn)
{
	float kq;
	kq = luonghangthang1CN(cn) * cn.chamCong.thang;
	return kq;
}
void xuatLuong1CN(CN cn)
{
	printf("\tMSCN: %s", cn.mscn);
	printf("\tHo ten: %s", cn.hoTen);
	printf("\tPhan xuong: %s", cn.phanXuong);
	printf("\tChuc vu: %s\n", cn.chucVu);
	printf("\tNam: %d", cn.chamCong.nam);
	printf("\tTong so ngay cong: %d", tongNgayCong1CN(cn));
	printf("\tTong so san pham: %d", tongSoSP1CN(cn));
	printf("\tLuong hang thang: %.1fVND", luonghangthang1CN(cn));
	printf("\tTong luong: %.1fVND\n", tongluong1CN(cn));
}
//Nhap vao nam va ma so cong nhan, xuat thong tin bang luong cua nam
void XuatLuongCN(CN cn[], int n)
{
	int  dem = 0, nam1;
	char mscn1[10];
	printf("\nNhap vao nam: ");
	scanf_s("%d", &nam1);
	printf("\nNhap vao ma so cong nhan: ");
	scanf("%s", &mscn1);
	for (int i = 0; i < n; i++)
	{
		if ((nam1 == cn[i].chamCong.nam) && (_strcmpi(cn[i].mscn, mscn1) == 0))
		{
			xuatLuong1CN(cn[i]);
			dem++;
		}
	}
	if (dem == 0)
		printf("\nKhong tim thay thong tin cua cong nhan nay.\n");
	else
		printf("\nTim kiem thong tin thanh cong.\n");
}
//Cau 5
void xuatTongLuongCaoNhatMax(CN cn[], int n)
{
	float MAX = tongluong1CN(cn[0]);
	int nam2;
	printf("\nNhap vao nam: ");
	scanf_s("%d", &nam2);
	for (int i = 0; i < n; i++)
	{
		if ((nam2 == cn[i].chamCong.nam) && tongluong1CN(cn[i]) > MAX)
			MAX = tongluong1CN(cn[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (tongluong1CN(cn[i]) == MAX)
		{
			xuatLuong1CN(cn[i]);
		}
	}
	printf("\nTong luong cao nhat la : %.2f", MAX);
}
//Cau 6: Them thong tin mot cong nhan vao danh sach
void themCN(CN cn[], int& n)
{
	n++;
	int i = n - 1;
	printf("Nhap ma so cong nhan: ");
	scanf("%s", cn[i].mscn);
	printf("Nhap ho ten: ");
	gets_s(cn[i].hoTen);
	getchar();
	printf("Nhap gioi tinh: ");
	scanf("%s", cn[i].gioiTinh);
	getchar();
	printf("Nhap phan xuong: ");
	gets_s(cn[i].phanXuong);
	getchar();
	printf("Nhap he so luong: ");
	scanf("%f", &cn[i].heSoLuong);
	printf("Nhap chuc vu: ");
	gets_s(cn[i].chucVu);
	getchar();
	printf("Nhap phu cap: ");
	scanf("%d", &cn[i].phuCap);
	printf("Nhap vao thang: ");
	scanf("%d", &cn[i].chamCong.thang);
	printf("Nhap vao nam: ");
	scanf("%d", &cn[i].chamCong.nam);
	printf("Nhap vao ngay cong: ");
	scanf("%d", &cn[i].chamCong.ngay);
	printf("Nhap vao so san pham: ");
	scanf(" %d", &cn[i].chamCong.soSP);
	printf("Nhap vao tien cong 1 san pham: ");
	scanf("%f", &cn[i].chamCong.tienCong);
}
//Cau 7
void xoaNhanVien(CN cn[], int& n, int k)
{
	for (int i = k; i < n - 1; i++)
		cn[i] = cn[i + 1];
	n--;
}
void xoaDSNhanVienCoThangChamCongCoNgayCongNhoHon20(CN cn[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (cn[i].chamCong.ngay < 20)
			xoaNhanVien(cn, n, i);
	}
	printf("Danh sach sau khi xoa la:");
	XuatMangDSCN(cn, n);
}
//Cau 8
void xoaNhanVienChuaCoDanhSachChamCong(CN cn[], int& n) {

	for (int i = 0; i < n; i++) {
		if ((cn[i].chamCong.thang) == 0 && (cn[i].chamCong.ngay) == 0 && (cn[i].chamCong.nam) == 0 && (cn[i].chamCong.soSP) == 0 && (cn[i].chamCong.tienCong == 0))
			xoaNhanVien(cn, n, i);
	}
	printf("\n************************************\n");
	printf("Danh sach sau khi xoa cac thong tin rong la:\n");
	XuatMangDSCN(cn, n);
}
//Cau 9
void TongNgayCong(CN cn[], int n)
{
	printf("\n====== CHUONG TRINH TINH TONG SO NGAY CONG DA LAM CUA CONG NHAN ======");
	for (int i = 0; i < n; i++)
	{
		printf("\nSTT: %d", i + 1);
		printf("\tMSCN: %s", cn[i].mscn);
		printf("\tHo ten: %s", cn[i].hoTen);
		printf("\tTong so ngay cong: %d", cn[i].chamCong.thang * cn[i].chamCong.ngay);
		printf("\tTong so thang la: %d\n", cn[i].chamCong.thang * (2022 - cn[i].chamCong.nam));
	}
}
//cau 10
int demSoCongNhan(CN a[], int n)
{
	int dem1 = 0;
	printf("Danh sach cong nhan co so ngay cong lon hon 24 trong thang 12 nam 2021 la:");
	for (int i = 0; i < n; i++)
	{
		if (a[i].chamCong.ngay >= 24 && a[i].chamCong.thang == 12 && a[i].chamCong.nam == 2021) {
			dem1++;
			printf("\n\t\t--------------------------------------------\n");
			xuat1CN(a[i]);
			printf("\n");
		}
	}
	if (dem1 == 0)
		printf("\nKhong co cong nhan nao co so ngay cong lon hon 24 trong thang 12 nam 2021");
	return dem1;

}
//cau 11
void luongCaoNhatNam2020(CN a[], int n)
{
	int i;
	float max = tongluong1CN(a[0]);
	printf("\nCong Nhan co luong cao nhat thang 12 nam 2020: \n");
	for (i = 0; i < n; i++)
	{
		if (a[i].chamCong.thang == 12 && a[i].chamCong.nam == 2020 && tongluong1CN(a[i]) > max)
		{
			max = tongluong1CN(a[i]);
			xuatLuong1CN(a[i]);
		}
	}
	printf("\nLuong cao nhat la: %.1f", max);
}
//cau 12
void tongSoSPCaoNhat(CN a[], int n)
{
	int i;
	int max = a[0].chamCong.soSP;
	int tongSP = 0;
	printf("Cong Nhan co tong so pham cao nhat 2020: \n");
	for (i = 0; i < n; i++)
	{
		if (a[i].chamCong.nam == 2020 && a[i].chamCong.soSP > max)
		{
			max = a[i].chamCong.soSP;
			tongSP += a[i].chamCong.ngay * a[i].chamCong.thang * a[i].chamCong.soSP;
			xuat1CN(a[i]);
		}
	}
	printf("\nTong so san pham cao nhat nam 2020 la: %d", tongSP);
}
//Bai 13
void tongNgayCongVaTongLuongcuaCN(CN a[], int n)
{
	int i;
	char PX[21];
	int TongNgayCong = 0;
	float TongLuong = 0;
	printf("Nhap phan xuong can tinh tong:");
	gets_s(PX);
	//XOA_KHOANG_TRANG(PX);
	for (i = 0; i < n; i++)
	{
		if (strstr(a[i].phanXuong, PX)) {
			TongNgayCong += a[i].chamCong.ngay * a[i].chamCong.thang;
			TongLuong += luonghangthang1CN(a[i]) * a[i].chamCong.thang;
			xuatLuong1CN(a[i]);
		}
	}
	printf("Tong ngay cong cua phan xuong %s la : %d", PX, TongNgayCong);
	printf("\nTong luong cua phan xuong %s la : %.1f", PX, TongLuong);
}
//Bai 14
void sapXepDSChamCongGiamDanTheoSP(CN a[], int n) {
	CN SP;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].chamCong.soSP < a[j].chamCong.soSP) {
				SP = a[i];
				a[i] = a[j];
				a[j] = SP;
			}
		}
	}
}
//cau 15
void xuat1CNSauKhiTangTienCongToTruong(CN cn)
{
	printf("\tMSCN: %s", cn.mscn);
	printf("\tHo ten: %s", cn.hoTen);
	printf("\tGioi tinh: %s", cn.gioiTinh);
	printf("\tPhan xuong: %s", cn.phanXuong);
	printf("\tHe so luong: %.1f", cn.heSoLuong);
	printf("\tChuc vu: %s\n", cn.chucVu);
	printf("\tPhu Cap: %dVND", cn.phuCap);
	printf("\tThang: %d", cn.chamCong.thang);
	printf("\tNam: %d", cn.chamCong.nam);
	printf("\tNgay Cong: %d", cn.chamCong.ngay);
	printf("\tSo san pham: %d", cn.chamCong.soSP);
}
void  tienCongChoToTruong(CN a[], int n) {
	int i, dem = 0;
	printf("\nDanh sach cac to truong duoc tang tien cong la: \n");
	for (i = 0; i < n; i++) {
		if (a[i].chamCong.thang == 12 && a[i].chamCong.nam == 2021 || a[i].chamCong.thang >= 1 && a[i].chamCong.nam == 2022) {
			if (strcmp(a[i].chucVu, "To Truong") == 0) {
				xuat1CNSauKhiTangTienCongToTruong(a[i]);
				printf("\nTien cong cua to truong %s la %.1fVND\n", a[i].hoTen, a[i].chamCong.tienCong * 0.15 + a[i].chamCong.tienCong);
			}
		}
		dem++;
	}
	if (dem == 0)
		printf("Khong co ai chuc vu to truong.\n");
}

