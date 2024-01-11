#define _CRT_SECURE_NO_WARNINGS
//De tai 17
//Cac bai tap duoc thuc hien tren VISUAL STUDIO 2022 va DEV - C
// Sau do duoc tong hop lai tren visual studio 2022
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include<string.h>

void baiI();
//MENU
void menuMaTran();
//menu bai 1
void menubai1();
//menu bai 2
void menubai2();
//Bai 1
void NhapMaTran(int a[][100], int& dong, int& cot);
void sinhMaTran(int array[][100], int& dong, int& cot);
void docFileM2C(FILE*& f, int a[][100], int& m, int& n);
void XuatMaTran(int array[][100], int dong, int cot);
//Bai 2
float tinhTrungBinhCongThuocBien(int array[][100], int dong, int cot);
float tinhTrungBinhCongDuongCheoChinh(int array[][100], int dong, int cot);
float tinhTrungBinhCongDuongCheoPhu(int array[][100], int dong, int cot);
//Bai 3
int kiemTraSoThinhVuong(int x);
void LietKeSoThinhVuongCuaTungCot(int array[][100], int dong, int cot);
//Bai 4
int SNT(int x);
void dongChuaTBNCacSoNguyenToMax(int arr[][100], int dong, int cot);
//Bai 5
void HoanDoiGiaTri2Cot(int array[][100], int dong, int cot, int& k, int& l);
//Bai 6
void MaTranDongGiaTriChanTangDanGiaTriLeGiamDan(int array[100], int dong, int cot);
void xuatMaTranDongGiaTriChanTangDanGiaTriLeGiamDan(int array[][100], int dong, int cot);
//Bai 7
void nhapMaTranC(int a[][100], int c[][100], int m, int n);
void nhapMaTranD(int a[][100], int d[][100], int m, int n);
//Bai 8
int demSoLanXuatHienCuaMTETrongA(int a[][100], int e[][100], int m, int n, int x, int y);
//Bai 9
void dichTungDong(int a[][100], int n, int& b);
void dichPhaiKLan(int a[][100], int m, int n, int& x);
//Bai 10
void swap(int& a, int& b);
void dichTungDong2(int a[100][100], int n, int b);
void hamXoanOc(int a[100][100], int m, int n, int b[100]);
void DoiSangMang1Chieu(int a[100][100], int  m, int n, int b[100]);
void baiII();
void main()
{
	int n;
	do
	{
		system("cls");
		printf("==================== = MENU = ======================\n");
		printf("Hay chon chuong trinh ma ban can thuc hien:\n");
		printf(" 1. Thuc hien xu li tren mang hai chieu.\n");
		printf(" 2. Thuc hien xu li tren mang cau truc.\n");
		printf("Neu ban muon thoat chuong trinh hay nhap so 0.\n");
		printf("====================================================\n");
		printf("\nMoi ban nhap chuong trinh ban muon thuc hien: ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 0:
			printf("Ban da chon thoat chuong trinh.\n");
			break;
		case 1:
			printf(" 1. Thuc hien xu li tren mang hai chieu.\n");
			baiI();
			printf("\nBan da thuc thi xong xu li tren mang hai chieu.\nVui long nhan Enter de tiep tuc thuc thi cac bai khac.\n");
			system("pause");
			break;
		case 2:
			printf(" 2. Thuc hien xu li tren mang cau truc.\n");
			baiII();
			printf("\nBan da thuc thi xong xu li tren mang cau truc.\nVui long nhan Enter de tiep tuc thuc thi cac bai khac.\n");
			system("pause");
			break;
		default:
			printf("Chuc nang nay chua cai dat. Vui long kiem tra lai!!!\nCac chuc nang da duoc cai dat da hien tren MENU.\n");
			printf("Vui long nhan Enter de tiep tuc.\n");
			system("pause");
			break;
		}
	} while (n != 0);
	_getch;
}
void baiI()
{
	int c;
	int array[100][100], dong = 0, cot = 0;
	do
	{
		system("cls");
		menuMaTran();
		printf("Moi ban nhap lua chon: ");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			printf(" 1. Khoi tao ma tran.\n");
			int x;
			do
			{
				system("cls");
				menubai1();
				printf("Moi ban lua chon cach tao ma tran: ");
				scanf_s("%d", &x);
				switch (x)
				{
				case 1:
					printf("Moi ban nhap ma tran\n");
					NhapMaTran(array, dong, cot);
					XuatMaTran(array, dong, cot);
					printf("Nhap va xuat ma tran thanh cong.\nVui long nha Enter de tiep tuc.\n");
					break;
				case 2:
					sinhMaTran(array, dong, cot);
					XuatMaTran(array, dong, cot);
					printf("Tao va xuat ma tran thanh cong.\nVui long nha Enter de tiep tuc.\n");
					break;
				case 3:
					FILE * f;
					docFileM2C(f, array, dong, cot);
					XuatMaTran(array, dong, cot);
					printf("Doc file va xuat ma tran thanh cong.\nVui long nha Enter de tiep tuc.\n");
					break;
				default:
					printf("Ban nhap sai, hay chon 1 hoac 2 hoac 3 de thuc hien chuong trinh.\nVui long nha Enter de tiep tuc.\n");
					system("pause");
					break;
				}
			} while (x != 1 && x != 2 && x != 3);
			system("pause");
			break;
		case 2:
			if (dong != 0 || cot != 0)
			{
				int so;
				do
				{
					system("cls");
					printf(" 2. Tinh gia tri trung binh cong cua cac phan tu tren 4 bien\n");
					printf("    duong cheo chinh, duong cheo phu trong ma tran.\n");
					menubai2();
					printf("Moi ban lua chon chuong trinh can thuc hien: ");
					scanf_s("%d", &so);
					switch (so)
					{
					case 1:
						float kq1;
						XuatMaTran(array, dong, cot);
						kq1 = tinhTrungBinhCongThuocBien(array, dong, cot);
						printf("\nTrung binh cong cac phan tu thuoc bien la: %.2f \n", kq1);
						printf("Thuc thi xong.\nVui long nha Enter de tiep tuc.\n");
						system("pause");
						break;
					case 2:
						float kq2;
						XuatMaTran(array, dong, cot);
						kq2 = tinhTrungBinhCongDuongCheoChinh(array, dong, cot);
						printf("\nTrung binh cong cac phan tu thuoc duong cheo chinh la: %.2f \n", kq2);
						printf("Thuc thi xong.\nVui long nha Enter de tiep tuc.\n");
						system("pause");
						break;
					case 3:
						float kq3;
						XuatMaTran(array, dong, cot);
						kq3 = tinhTrungBinhCongDuongCheoPhu(array, dong, cot);
						printf("\nTrung binh cong cac phan tu thuoc duong cheo phu la: %.2f \n", kq3);
						printf("Thuc thi xong. Vui long nha Enter de tiep tuc.\n");
						system("pause");
						break;
					case 0:
						printf("Ban da chon thoat chuong trinh.\n");
						printf("Vui long nha Enter de tiep tuc thuc thi cac bai khac.\n");
						break;
					default:
						printf("Ban nhap sai, hay chon 1 hoac 2 hoac 3 de thuc hien chuong trinh.\nVui long nha Enter de tiep tuc.\n");
						system("pause");
						break;
					}
				} while (so != 0);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 3:
			if (dong != 0 || cot != 0)
			{
				printf(" 3. Liet ke danh sach phan tu cua tung cot chua toan bo so thinh vuong.\n");
				XuatMaTran(array, dong, cot);
				LietKeSoThinhVuongCuaTungCot(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 4:
			if (dong != 0 || cot != 0)
			{
				printf(" 4. Hay cho biet dong co chua gia tri trung binh nhan cua cac so nguyen to lon nhat.\n");
				XuatMaTran(array, dong, cot);
				dongChuaTBNCacSoNguyenToMax(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 5:
			if (dong != 0 || cot != 0)
			{
				int k, l;
				printf("5. Chuyen doi vi tri 2 cot k va l trong ma tran.\n");
				XuatMaTran(array, dong, cot);
				HoanDoiGiaTri2Cot(array, dong, cot, k, l);
				XuatMaTran(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 6:
			if (dong != 0 || cot != 0)
			{
				printf(" 6. Tu ma tran A xuat ma tran B sao cho tung dong cac gia tri chan tang dan, cac gia tri le giam dan.\n");
				XuatMaTran(array, dong, cot);
				xuatMaTranDongGiaTriChanTangDanGiaTriLeGiamDan(array, dong, cot);
				printf("Sau khi sap xep:\n");
				XuatMaTran(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 7:
			if (dong != 0 || cot != 0)
			{
				int c[100][100], d[100][100];
				printf(" 7. Tu A tao va xuat ra hai ma tran C, D sao cho C chua toan so duong va D chua toan so am.\n");
				printf("Ma tran A ban dau:\n");
				XuatMaTran(array, dong, cot);
				nhapMaTranC(array, c, dong, cot);
				printf("Ma tran C la:\n");
				XuatMaTran(c, dong, cot);
				nhapMaTranD(array, d, dong, cot);
				printf("Ma tran D la:\n");
				XuatMaTran(d, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 8:
			if (dong != 0 || cot != 0)
			{
				int e[100][100], x, y;
				int k;
				do
				{
					system("cls");
					printf(" 8. Tao mot ma tran E co kich thuoc la x dong nhan y cot. Dem so lan xuat hien cua E trong A.\n");
					XuatMaTran(array, dong, cot);
					printf("Nhap va xuat ma tran E:\n");
					menubai1();
					printf("Moi ban lua chon cach tao ma tran: ");
					scanf_s("%d", &k);
					switch (k)
					{
					case 1:
						printf("Moi ban nhap ma tran\n");
						NhapMaTran(e, x, y);
						XuatMaTran(e, x, y);
						break;
					case 2:
						sinhMaTran(e, x, y);
						XuatMaTran(e, x, y);
						break;
					case 3:
						FILE * f;
						docFileM2C(f, e, x, y);
						XuatMaTran(e, x, y);
						break;
					default:
						printf("Ban nhap sai, hay chon 1 hoac 2 hoac 3 de thuc hien chuong trinh.\nVui long nha Enter de tiep tuc.\n");
						system("pause");
						break;
					}
				} while (k != 1 && k != 2 && k != 3);
				printf("So lan xuat hien cua cac phan tu cua ma tran E trong ma tran A: %d", demSoLanXuatHienCuaMTETrongA(array, e, dong, cot, x, y));
				printf("\n");
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 9:
			if (dong != 0 || cot != 0)
			{
				int k;
				printf(" 9. Tu A  tao va xuat ra ma tran F duoc dich phai xoay vong cac cot theo truc dung\n voi chieu tu trai sang phai k lan.\n");
				XuatMaTran(array, dong, cot);
				printf("Ma tran duoc dich xoay vong cac cot theo truc dung voi chieu tu trai sang phai: ");
				dichPhaiKLan(array, dong, cot, k);
				printf("\nMa tran sau khi dich phai:\n");
				XuatMaTran(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 10:
			if (dong != 0 || cot != 0)
			{
				int b[100];
				printf("10. Tu A xuat ra ma tran I duoc xoan oc giam dan nguoc chieu kim dong ho.\n");
				XuatMaTran(array, dong, cot);
				hamXoanOc(array, dong, cot, b);
				DoiSangMang1Chieu(array, dong, cot, b);
				XuatMaTran(array, dong, cot);
			}
			else
			{
				printf("Ban chua tao ma tran. Vui long tao ma tran truoc khi thuc hien yeu cau.\n");
				printf("Hay nhan Enter de tiep tuc.\n");
			}
			system("pause");
			break;
		case 0:
			printf("Ban da chon thoat chuong trinh.\n");
			break;
		default:
			printf("So ban nhap khong co trong chuong trinh!\nVui long nhap lai!!!\n(So ban nhap phai trong khoang tu 1 den 10)\n");
			printf("Vui long nhan Enter de tiep tuc.\n");
			system("pause");// lenh dung chuong trinh
			break;
		}
	} while (c != 0);
	_getch;
}
//MENU PHAN MANG HAI CHIEU
void menuMaTran()
{
	printf("=========================================== = MENU = ================================================\n");
	printf("\t\tHay chon chuong trinh ma ban can thuc hien:\n");
	printf(" 1. Khoi tao ma tran A va xuat ma tran A\n");
	printf(" 2. Tinh gia tri trung binh cong cua cac phan tu tren 4 bien; duong cheo chinh, phu\n");
	printf(" 3. Liet ke danh sach phan tu cua tung cot chua toan bo so thinh vuong.\n");
	printf(" 4. Hay cho biet dong co chua gia tri trung binh nhan cua cac so nguyen to lon nhat.\n");
	printf(" 5. Hoan vi hai cot bat ki cua ma tran A voi hai cot nhap tu ban phim.\n");
	printf(" 6. Tu ma tran A xuat ma tran B sao cho tung dong cac gia tri chan tang dan, cac gia tri le giam dan.\n");
	printf(" 7. Tu A tao va xuat ra hai ma tran C, D sao cho C chua toan so duong va D chua toan so am.\n");
	printf(" 8. Tao mot ma tran E co kich thuoc la x dong nhan y cot. Dem so lan xuat hien cua E trong A.\n");
	printf(" 9. Tu A tao va xuat ra ma tran F duoc dich phai xoay vong cac cot theo truc dung\n voi chieu tu trai sang phai k lan.\n");
	printf("10. Tu A xuat ra ma tran I duoc xoan oc giam dan nguoc chieu kim dong ho.\n");
	printf(" Neu ban muon thoat chuong trinh hay nhap so 0.\n");
	printf("=====================================================================================================\n");
	_getch;
}
//menu nhap ma tran
void menubai1()
{
	printf("================ = MENU CHON CACH NHAP MA TRAN = =================\n");
	printf("Nhap 1 neu ban muon nhap gia tri cho cac phan tu ma tran.\n");
	printf("Nhap 2 neu ban muon sinh so ngau nhien cho cac phan tu ma tran.\n");
	printf("Nhap 3 neu ban muon lay du lieu tu file.\n");
	printf("==================================================================\n");
	_getch;
}
//menu bai 2
void menubai2()
{
	printf("========================= = MENU Bai 2 = =========================\n");
	printf("\nChuong trinh tinh trung binh cong cac gia tri mang 2 chieu: ");
	printf("\n\t1. Cac phan tu nam tren duong bien cua mang.");
	printf("\n\t2. Cac phan tu nam tren duong cheo chinh cua mang");
	printf("\n\t3. Cac phan tu nam tren duong cheo phu cua mang");
	printf("\n\t0. Ket thuc chuong trinh.\n");
	printf("==================================================================\n");
	_getch;
}
//Bai 1
//Nhap ma tran bang cach thu cong.
void NhapMaTran(int a[][100], int& dong, int& cot)
{
	int i, j;
	do
	{
		printf("Moi ban nhap so dong: ");
		scanf_s("%d", &dong);
		if (dong <= 0 || dong > 100)
		{
			printf("Ban da nhap sai so dong. Vui long nhap lai!!!\n");
			printf("So dong ban nhap phai lon hon 0 va nho hon 100.\n");
		}
	} while (dong <= 0 || dong > 100);
	do
	{
		printf("Moi ban nhap so cot: ");
		scanf_s("%d", &cot);
		if (cot <= 0 || cot > 100)
		{
			printf("Ban da nhap sai so cot. Vui long nhap lai!!!\n");
			printf("So cot ban nhap phai lon hon 0 va nho hon 100.\n");
		}
	} while (cot <= 0 || cot > 100);
	for (i = 0; i < dong; i++)
		for (j = 0; j < cot; j++)
		{
			printf("Phan tu o dong va cot [%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	_getch;
}
//Nhap ma tran bang cach sinh ngau nhien.
void sinhMaTran(int array[][100], int& dong, int& cot)
{
	int i, j;
	do
	{
		printf("Moi ban nhap so dong: ");
		scanf_s("%d", &dong);
		if (dong <= 0 || dong > 100)
		{
			printf("Ban da nhap sai so dong. Vui long nhap lai!!!\n");
			printf("So dong ban nhap phai lon hon 0 va nho hon 100.\n");
		}
	} while (dong <= 0 || dong > 100);
	do
	{
		printf("Moi ban nhap so cot: ");
		scanf_s("%d", &cot);
		if (cot <= 0 || cot > 100)
		{
			printf("Ban da nhap sai so cot. Vui long nhap lai!!!\n");
			printf("So cot ban nhap phai lon hon 0 va nho hon 100.\n");
		}
	} while (cot <= 0 || cot > 100);
	srand((int)time(0));
	for (i = 0; i < dong; i++)
		for (j = 0; j < cot; j++)
		{
			array[i][j] = rand() % 101 - 30;
		}
	_getch;
}
//Nhap ma tran bang cach doc file
void docFileM2C(FILE*& f, int a[][100], int& m, int& n) {
	f = fopen("MangHaiChieu.txt", "rt");
	fscanf(f, "%d", &m);
	fscanf(f, "%d", &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			fscanf(f, "%d", &a[i][j]);
		}
	fclose(f);
}
//Xuat ma tran
void XuatMaTran(int array[][100], int dong, int cot)
{
	int i, j;
	printf("Noi dung cua ma tran la:\n");
	for (i = 0; i < dong; i++)
	{
		for (j = 0; j < cot; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}
//Bai 2
float tinhTrungBinhCongThuocBien(int array[][100], int dong, int cot)
{
	int i, j, dem1 = 0, tong_bien = 0;
	float tbc_bien;
	printf("\nCac phan tu thuoc bien:\n");
	for (i = 0; i < dong; i++)
	{
		for (j = 0; j < cot; j++)
		{
			if (i == 0 || i == dong - 1 || j == 0 || j == cot - 1)
			{
				printf("%d\t", array[i][j]);
				tong_bien += array[i][j];
				dem1++;
			}
			else printf(" \t");
		}
		printf("\n");
	}
	return tbc_bien = (float)tong_bien / dem1;
}
float tinhTrungBinhCongDuongCheoChinh(int array[][100], int dong, int cot)
{
	int i, j, dem2 = 0, tong_duong_cheo_chinh = 0;
	float tbc;
	printf("\nCac phan tu thuoc duong cheo chinh :\n");
	for (i = 0; i < dong; i++)
	{
		for (j = 0; j < cot; j++)
		{
			if (i == j)
			{
				printf("%d\t", array[i][j]);
				tong_duong_cheo_chinh += array[i][j];
				dem2++;
			}
			else printf(" \t");
		}
		printf("\n");
	}
	return tbc = (float)tong_duong_cheo_chinh / dem2;
}
float tinhTrungBinhCongDuongCheoPhu(int array[][100], int dong, int cot)
{
	int i, j, dem3 = 0, tong_duong_cheo_phu = 0;
	float tbc;
	printf("\nCac phan tu thuoc duong cheo phu :\n");
	for (i = 0; i < dong; i++)
	{
		for (j = 0; j < cot; j++)
		{
			if (i + j == cot - 1)
			{
				printf("%d\t", array[i][j]);
				tong_duong_cheo_phu += array[i][j];
				dem3++;
			}
			else printf(" \t");
		}
		printf("\n");
	}
	return tbc = (float)tong_duong_cheo_phu / dem3;
}
//Bai 3
int kiemTraSoThinhVuong(int x)
{
	int tong = 0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0)
			tong = tong + i;
	}
	if (tong > x)
	{
		return true;
	}
	else
		return false;
}
void LietKeSoThinhVuongCuaTungCot(int array[][100], int dong, int cot)
{
	int i, j, dem = 0;
	printf("\nSo thinh vuong la: \n");
	for (i = 0; i < dong; i++)
	{
		for (j = 0; j < cot; j++)
		{
			if (kiemTraSoThinhVuong(array[i][j]) == true)
			{
				printf("%d o cot %d \n", array[i][j], j);
				dem++;
			}
		}
	}
	if (dem == 0)
		printf("Trong ma tran khong co so thinh vuong nao.\n");
}
//Bai 4
int SNT(int x)
{
	if (x == 2)
		return true;
	else if (x < 2)
		return false;
	else
	{
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0)
				return false;
			if (x % i != 0 && i == (x - 1))
				return true;
		}
	}
}
void dongChuaTBNCacSoNguyenToMax(int arr[][100], int m, int n)
{
	float csn = 1, csn2;
	int vt = 0;
	float dem = 0;
	float dem2;
	float maxtbn, maxtbn2;
	for (int j = 0; j < n; j++)
	{
		if (SNT(arr[0][j]) == true)
		{
			csn = arr[0][j] * csn;
			dem++;
		}
	}
	maxtbn = pow(csn, 1 / dem);
	for (int i = 0; i < m; i++)
	{
		csn2 = 1;
		dem2 = 0;
		maxtbn2 = 0;
		for (int j = 0; j < n; j++)
		{
			if (SNT(arr[i][j]) == true)
			{
				csn2 = arr[i][j] * csn2;
				dem2++;
			}
		}
		maxtbn2 = pow(csn2, 1 / dem2);
		if (maxtbn2 > maxtbn)
		{
			maxtbn = maxtbn2;
			vt = i;
		}
	}
	if (dem == 0 || dem2 == 0)
		printf("Cac dong trong ma tran khong co so nguyen to.\n");
	else
		printf("Dong co chua gia tri trung binh nhan cua cac so nguyen to lon nhat la %d, trung binh nhan: %.2f\n", vt, maxtbn);
}
//Bai 5
void HoanDoiGiaTri2Cot(int array[][100], int dong, int cot, int& k, int& l)
{
	do
	{
		printf("Moi ban nhap cot thu nhat ma ban muon hoan doi: ");
		scanf_s("%d", &k);
		if (k < 0 || k > cot - 1)
		{
			printf("Cot ban muon nhap khong ton tai. Vui long kiem tra lai!!!\n");
			printf("Cac cot phai thuoc pham vi [0; %d].\n", cot - 1);
		}
	} while (k < 0 || k > cot - 1);
	do
	{
		printf("Moi ban nhap cot thu hai ma ban muon hoan doi: ");
		scanf_s("%d", &l);
		if (l < 0 || l > cot - 1)
		{
			printf("Cot ban muon nhap khong ton tai. Vui long kiem tra lai!!!\n");
			printf("Cac cot phai thuoc pham vi [0; %d].\n", cot - 1);
		}
	} while (l < 0 || l > cot - 1);
	for (int i = 0; i < dong; i++) // duyet qua cac dong
	{
		//a[i][k] a[i][l] Hoan vi cac cot voi nhau cac hang giu nguyen
		int temp = array[i][k];
		array[i][k] = array[i][l];
		array[i][l] = temp;
	}
}
//Bai 6
void MaTranDongGiaTriChanTangDanGiaTriLeGiamDan(int array[100], int dong, int cot)
{
	for (int k = 0; k < dong; k++)
	{
		for (int i = 0; i < dong; i++)
		{
			if (array[i] % 2 != 0)
			{
				for (int j = i + 1; j < cot; j++)
				{
					if (array[j] % 2 != 0 && array[j] > array[i])
					{
						int temp = array[i];
						array[i] = array[j];
						array[j] = temp;
						i = j;
					}
				}
			}
			if (array[i] % 2 == 0)
			{
				for (int j = i + 1; j < cot; j++)
				{
					if (array[j] % 2 == 0 && array[j] < array[i])
					{
						int temp = array[i];
						array[i] = array[j];
						array[j] = temp;
						i = j;
					}
				}
			}
		}
	}
}
void xuatMaTranDongGiaTriChanTangDanGiaTriLeGiamDan(int array[][100], int dong, int cot)
{

	for (int i = 0; i < dong; i++)
	{
		MaTranDongGiaTriChanTangDanGiaTriLeGiamDan(array[i], dong, cot);
	}

}
//Bai 7
void nhapMaTranC(int a[][100], int c[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				c[i][j] = a[i][j];
			else
				c[i][j] = 0;
}
void nhapMaTranD(int a[][100], int d[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] < 0)
				d[i][j] = a[i][j];
			else
				d[i][j] = 0;
}
//Bai 8
int demSoLanXuatHienCuaMTETrongA(int a[][100], int e[][100], int m, int n, int x, int y)
{
	int i, j, k, b, dem = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < x; k++)
			{
				for (b = 0; b < y; b++)
				{
					if (e[k][b] == a[i][j])
						dem++;
				}
			}
		}
	}
	return dem;
}
//Bai 9
void dichTungDong(int a[][100], int n, int& x)
{
	a[x][90] = a[x][n - 1];
	for (int i = n - 1; i >= 1; i--)
	{
		a[x][i] = a[x][i - 1];
	}
	a[x][0] = a[x][90];
}
void dichPhaiKLan(int a[][100], int m, int n, int& k)
{
	printf("\nNhap so lan dich: ");
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dichTungDong(a, n, j);
		}
	}
}
//Bai 10
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void dichTungDong2(int a[100][100], int n, int b)
{
	a[b][90] = a[b][n - 1];
	for (int i = n - 1; i >= 1; i--)
	{
		a[b][i] = a[b][i - 1];
	}
	a[b][0] = a[b][90];
}
void hamXoanOc(int a[100][100], int m, int n, int b[100])
{
	int z = 0, h1 = 0, h2 = m - 1, c1 = 0, c2 = n - 1;
	while (h1 <= h2 && c1 <= c2)
	{
		for (int i = h1; i <= h2; i++)
		{
			a[i][h1] = b[z];
			z++;
		}
		c1++;
		for (int i = c1; i <= c2; i++)
		{
			a[h2][i] = b[z];
			z++;
		}
		h2--;
		if (c1 <= c2) {
			for (int i = h2; i >= h1; i--)
			{
				a[i][c2] = b[z];
				z++;
			}
			c2--;
		}
		if (h1 <= h2)
		{
			for (int i = c2; i >= c1; i--)
			{
				a[h1][i] = b[z];
				z++;
			}
			h1++;
		}
	}
	XuatMaTran(a, m, n);
}
void DoiSangMang1Chieu(int a[100][100], int  m, int n, int b[100])
{
	int z = 0;
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < n; k++)
		{
			b[z] = a[i][k];
			z++;
		}
	}
	for (int i = 0; i < z - 1; i++)
	{
		for (int k = i; k < z; k++)
			if (b[i] < b[k])
				swap(b[i], b[k]);
	}
}