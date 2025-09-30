#include <stdio.h>

int main() {
    int position ;          // ตำแหน่งงาน (1=Junior, 2=Mid-Level, 3=Senior)
    int years ;             // จำนวนปีที่ทำงาน
    int projects ;          // จำนวนโปรเจคที่สำเร็จ
    float baseSalary ;      // เงินเดือนพื้นฐาน
    float bonus = 0 ;       // โบนัสตามอายุงาน
    float extraBonus = 0 ;  // โบนัสพิเศษ
    float totalSalary ;     // เงินเดือนสุทธิ

    // รับค่าตำแหน่งงาน
    printf( "Enter position (1=Junior Programmer, 2=Mid-Level Programmer, 3=Senior Programmer): " ) ;
    scanf( "%d" , &position ) ;

    // รับค่าอายุงาน
    printf( "Enter years of experience: " ) ;
    scanf( "%d" , &years) ;

    // รับจำนวนโปรเจค
    printf( "Enter number of successful projects this year: " ) ;
    scanf( "%d" , &projects ) ;

    // กำหนดเงินเดือนพื้นฐานตามตำแหน่ง
    if ( position == 1 ) {
        baseSalary = 20000 ;
    } else if ( position == 2 ) {
        baseSalary = 35000 ;
    } else if ( position == 3 ) {
        baseSalary = 50000 ;
    } else {
        printf( "Invalid position.\n" ) ;
        return 0 ; // จบโปรแกรมถ้าใส่ตำแหน่งไม่ถูกต้อง
    }

    // คำนวณโบนัสตามอายุงาน
    if ( years < 1 ) {
        bonus = 0 ;
    } else if ( years >= 1 && years <= 3 ) {
        bonus = baseSalary * 0.10 ;
    } else if ( years >= 4 && years <= 5 ) {
        bonus = baseSalary * 0.15 ;
    } else if (years > 5) {
        bonus = baseSalary * 0.20 ;
    }

    // คำนวณโบนัสพิเศษถ้ามี
    if ( projects > 5 ) {
        extraBonus = baseSalary * 0.05 ;
    }

    // เงินเดือนสุทธิ
    totalSalary = baseSalary + bonus + extraBonus ;

    // แสดงผลลัพธ์
    printf( "\n=== Salary Details ===\n" ) ;
    printf( "Base Salary     : %.2f Baht\n" , baseSalary ) ;
    printf( "Bonus (by years): %.2f Baht\n" , bonus ) ;
    printf( "Extra Bonus     : %.2f Baht\n" , extraBonus ) ;
    printf( "Total Salary    : %.2f Baht\n" , totalSalary ) ;

    return 0 ;
}
