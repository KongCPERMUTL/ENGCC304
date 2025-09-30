#include <stdio.h>
#include <math.h>   // ใช้ฟังก์ชัน pow() สำหรับเลขยกกำลัง

// ฟังก์ชันตรวจสอบว่าเป็น Armstrong Number หรือไม่
void checkArmstrong( int num ) {
    int original = num ;   // เก็บค่าตัวเลขเดิมไว้
    int sum = 0 ;          // เก็บผลรวมเลขยกกำลังของแต่ละหลัก
    int count = 0 ;        // เก็บจำนวนหลักของตัวเลขชั่วคราว
    int temp = num ;       // ใช้ temp สำหรับการนับจำนวนหลัก

    // นับจำนวนหลัก
    while ( temp > 0 ) {
        temp = temp / 10 ;
        count++ ;
    }

    temp = num ;  // รีเซ็ตค่า temp เป็นเลขเดิม

    // หาผลรวมของเลขยกกำลังตามจำนวนหลัก
    while ( temp > 0 ) {
        int digit = temp % 10 ;                   // แยกหลักสุดท้าย
        sum += ( int )pow( digit , count ) ;           // ยกกำลังแล้วบวกเข้าผลรวม
        temp = temp / 10 ;                        // ตัดหลักสุดท้ายออก
    }

    // ตรวจสอบว่าผลรวมตรงกับเลขเดิมไหม
    if ( sum == original ) {
        printf( "Pass.\n" ) ;
    } else {
        printf( "Not Pass.\n" ) ;
    }
}

int main() {
    int num ;

    // รับค่าตัวเลขจากผู้ใช้
    printf( "Enter Number:\n" ) ;
    scanf( "%d", &num ) ;

    // เรียกใช้ฟังก์ชันตรวจสอบ
    checkArmstrong( num ) ;

    return 0 ;
}
