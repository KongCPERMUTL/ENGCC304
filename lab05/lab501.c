#include <stdio.h>

int main() {
    char empID[ 11 ] ;        // เก็บรหัสประจำตัวพนักงาน (สูงสุด 10 ตัวอักษร + '\0')
    int hours ;             // เก็บจำนวนชั่วโมงทำงาน
    double rate ;           // เก็บค่าจ้างต่อชั่วโมง
    double salary ;         // เก็บรายได้รวม

    printf( "Input the Employees ID(Max. 10 chars): " ) ;
    scanf( "%s", empID ) ;   // รับรหัสพนักงาน (string)

    printf( "Input the working hrs: " ) ;
    scanf( "%d", &hours ) ;  // รับจำนวนชั่วโมงทำงาน

    printf( "Salary amount/hr: " ) ;
    scanf( "%lf", &rate ) ;  // รับค่าแรงต่อชั่วโมง

    salary = hours * rate ;   // คำนวณรายได้รวม

    printf( "Employees ID = %s\n" , empID ) ;
    printf( "Salary = U$ %.2f\n" , salary ) ;

    return 0 ;
}
