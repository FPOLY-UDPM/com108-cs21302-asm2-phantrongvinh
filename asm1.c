/******************************************************************************
 * Họ và tên: Phan Trọng Vinh
 * MSSV:      PS49909
 * Lớp:       CS21301
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
#include <string.h>
#include <stdlib.h>

// Kiểm tra số nguyên bằng cách lấy số num
int isInteger(float num, char *x, int *n)
{
    int len = strlen(x);
    const float EPS = 1e-6;

    if (fabs(num - round(num)) < EPS)
    {
        len += sprintf(x + len, "%.2f la so nguyen\n", num);
        *n = (int)round(num);
        return 1;
    }
    else
    {
        len += sprintf(x + len, "%.2f khong la so nguyen\n", num);
        return 0;
    }
}

// Kiểm tra số nguyên tố
void isSNT(int num, char *x)
{
    int len = strlen(x);
    if (num < 2)
    {
        len += sprintf(x + len, "%d không là số nguyên tố\n", num);
    }
    else
    {
        int i = 2;
        int isSNT = 1;
        while (i <= (num / 2) && isSNT == 1)
        {
            if (num % i == 0)
            {
                isSNT = 0;
                len += sprintf(x + len, "%d không là số nguyên tố\n", num);
            }
            else
            {
                i++;
            }
        }
        if (isSNT == 1)
        {
            len += sprintf(x + len, "%d là số nguyên tố\n", num);
        }
    }
}

// Kiểm tra số chính phương
void isSCP(int num, char *x)
{
    int i = 1;
    int isSCP = 0;
    int len = strlen(x);
    while (i <= sqrt(num) && isSCP == 0)
    {
        if (i * i == num)
        {
            isSCP = 1;
            len += sprintf(x + len, "%d la so chinh phuong\n", num);
        }
        else
        {
            i++;
        }
    }
    if (isSCP == 0)
    {
        len += sprintf(x + len, "%d không la so chinh phuong\n", num);
    }
}

// Chức năng số 1 kiểm tra số
void testNum()
{
    float num = 0;
    int n = 0;
    printf("Nhap mot so: ");
    scanf("%f", &num);
    char x[200] = "";
    if (isInteger(num, x, &n))
    {
        isSNT(n, x);
        isSCP(n, x);
    }
    printf("%s\n", x);
}

// Tìm ước chung lớn nhất
void gcd(int a, int b, int *ucln)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    *ucln = a;
}

// Tìm bội chung nhỏ nhất
void lcm(int a, int b, int ucln, int *bcnn)
{
    *bcnn = (a * b) / ucln;
}

// Chuc nang so 2 tim uoc chung ln va boi so chung nn
void uclnAndBcnn()
{
    int a, b, ucln, bcnn;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    gcd(a, b, &ucln);
    lcm(a, b, ucln, &bcnn);

    printf("Uoc chung lon nhat cua %d va %d: %d\n"
           "Boi chung nho nhat cua %d va %d: %d\n",
           a, b, ucln, a, b, bcnn);
}

// Format so tien in ra
void formatMoney(int money, char *x)
{
    char temp[20];
    sprintf(temp, "%d", money);

    int len = strlen(temp);
    int cnt = 0, j = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        x[j++] = temp[i];
        cnt++;
        if (cnt == 3 && i != 0)
        {
            x[j++] = '.';
            cnt = 0;
        }
    }
    x[j] = '\0';
    strrev(x);
}

// Chuc nang so 3 tinh tien cho quan karaoke
void karaokeFee()
{
    int timeIn, timeOut, day;

    do
    {
        printf("Nhap gio vao (12 - trước 23): ");
        scanf("%d", &timeIn);
    } while (timeIn < 12 || timeIn >= 23);

    do
    {
        do
        {
            printf("Nhap gio ra (0 - 23)(gio ra chi nho hon gio vao neu su dung dich vu tu 1 ngay tro len): ");
            scanf("%d", &timeOut);
        } while (timeOut < 0 || timeOut > 23);

        do
        {
            printf("Nhap so ngay(trong ngay(0), nhieu ngay nhap theo so ngay): ");
            scanf("%d", &day);
        } while (day < 0);
    } while (timeOut <= timeIn && day == 0);

    int time;

    if (day > 0)
    {
        printf("Khach hang su dung dich vu qua %d dem\n", day);
        time = 24 - timeIn + timeOut + 24 * (day - 1);
    }
    else
    {
        time = timeOut - timeIn;
    }

    int rs;

    if (time > 3)
    {
        rs = 3 * 150000 + (time - 3) * 150000 * 70 / 100;
    }
    else
    {
        rs = time * 150000;
    }

    if (timeIn >= 14 && timeIn <= 17)
    {
        rs = rs * 90 / 100;
    }

    char s[100];
    formatMoney(rs, s);
    printf("%s VND\n", s);
}

// Chuc nang 4 Tinh tien dien
void electricFee()
{
    // Khai báo biến
    unsigned int tongSoDienMotThang, giaTienDien, giaTienDienSauThue = 0;

    // Nhập dữ liệu
    printf("Nhap vao so dien tieu thu hang thang: ");
    scanf("%d", &tongSoDienMotThang);

    // Xử lý, tính toán VÀ Hiển thị kết quả
    if (tongSoDienMotThang < 51)
    {
        giaTienDien = tongSoDienMotThang * 1678;
    }
    else if (tongSoDienMotThang >= 51 && tongSoDienMotThang < 101)
    {
        giaTienDien = 50 * 1678 + (tongSoDienMotThang - 50) * 1734;
    }
    else if (tongSoDienMotThang >= 101 && tongSoDienMotThang < 201)
    {
        giaTienDien = 50 * 1678 + 50 * 1734 + (tongSoDienMotThang - 50 * 2) * 2014;
    }
    else if (tongSoDienMotThang >= 201 && tongSoDienMotThang < 301)
    {
        giaTienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (tongSoDienMotThang - 50 * 4) * 2536;
    }
    else if (tongSoDienMotThang >= 301 && tongSoDienMotThang < 401)
    {
        giaTienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (tongSoDienMotThang - 50 * 6) * 2834;
    }
    else
    {
        giaTienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (tongSoDienMotThang - 50 * 8) * 2927;
    }

    giaTienDienSauThue = giaTienDien + (giaTienDien * 8 / 100);
    char s[100];
    formatMoney(giaTienDienSauThue, s);
    printf("%s VND\n", s);
}

// Chuc nang 5 doi tien
void changeMoney()
{
    int money = 842;
    // printf("Nhap tien: ");
    // scanf("%d", money);
    int firstMoney = money;

    // 500,200,100,50,20,10,5,2,1
    int money500 = money / 500;
    money = money % 500;

    int money200 = money / 200;
    money = money % 200;

    int money100 = money / 100;
    money = money % 100;

    int money50 = money / 50;
    money = money % 50;

    int money20 = money / 20;
    money = money % 20;

    int money10 = money / 10;
    money = money % 10;

    int money5 = money / 5;
    money = money % 5;

    int money2 = money / 2;
    money = money % 2;

    int money1 = money / 1;
    money = money % 1;

    printf("So tien %d duoc doi thanh: \n"
           "%d to 500k,\n"
           "%d to 200k,\n"
           "%d to 100k,\n"
           "%d to 50k,\n"
           "%d to 20k,\n"
           "%d to 10k,\n"
           "%d to 5k,\n"
           "%d to 2k,\n"
           "%d to 1k\n",
           firstMoney, money500, money200, money100, money50, money20, money10, money5, money2, money1);
}

int main()
{
    int chonChucNang;

    do
    {
        printf("\nChon chuc nang:\n");
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
            testNum();
            break;
        case 2:
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            uclnAndBcnn();
            break;
        case 3:
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            karaokeFee();
            break;
        case 4:
            // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            electricFee();
            break;
        case 5:
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            changeMoney();
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