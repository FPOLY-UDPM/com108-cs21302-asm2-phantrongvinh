/******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c

// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện
// 5. Chức năng số 5: Chức năng đổi tiền
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>

void isInteger()
{
    float num;
    printf("Nhap mot so: ");
    scanf("%f", &num);

    // Kiem tra so nguyen
    if (floor(num) != num)
    {
        printf("%.2f khong la so nguyen\n", num);
    }
    else
    {
        printf("%.2f la so nguyen \n", num);
        int n = (int)num;
        if (n < 0)
        {
            printf("%d la so nguyen am\n", n);
        }
        else if (n > 0)
        {
            printf("%d la so nguyen duong\n", n);

            // Kiem tra so nguyen to
            if (n > 1)
            {
                int i = 2;
                int isSNT = 1;
                while (i < (n / 2) && isSNT == 1)
                {
                    if (n % i == 0)
                    {
                        isSNT = 0;
                        printf("%d khong la so nguyen to\n", n);
                    }
                    else
                    {
                        i++;
                    }
                }
                if (isSNT == 1)
                {
                    printf("%d la so nguyen to\n", n);
                }
            }

            // Kiem tra so chinh phuong
            int j = 1;
            int isSCP = 0;
            while (j <= sqrt(n) && isSCP == 0)
            {
                if (j * j == n)
                {
                    isSCP = 1;
                    printf("%d la so chinh phuong\n", n);
                }
                else
                {
                    j++;
                }
            }
            if (isSCP == 0)
            {
                printf("%d khong la so chinh phuong\n", n);
            }
        }
        else
        {
            printf("%d la so 0\n", n);
            printf("%d la so chinh phuong\n", n);
        }
    }
}
void gdc()
{
    int a = 0, b = 0, i = 1;
    printf("Nhap so thu 1: ");
    scanf("%d", &a);
    printf("Nhap so thu 2: ");
    scanf("%d", &b);
    int length = 0;
    if (a > b)
    {
        length = b;
    }
    else
    {
        length = a;
    }
    printf("Uoc so chung: \n");
    while (i <= length / 2)
    {
        if (a % i == 0 & b % i == 0)
        {
            printf("%d | ", i);
        }
        i++;
    }
}

int main()
{
    int chonChucNang;

    do
    {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang)
        {
        case 1:
            // Gọi hàm kiểm tra số nguyên
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            isInteger();
            break;
        case 2:
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            gdc();
            break;
        case 3:
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            break;
        case 4:
            // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            break;
        case 5:
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            break;
        case 6:
            // Gọi hàm tính lãi suất vay ngân hàng
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
            break;
        case 7:
            // Gọi hàm vay tiền mua xe
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            break;
        case 8:
            // Gọi hàm sắp xếp thông tin sinh viên
            printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
            break;
        case 9:
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            break;
        case 10:
            // Gọi hàm tính toán phân số
            printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}