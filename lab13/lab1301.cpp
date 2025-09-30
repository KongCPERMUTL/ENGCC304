#include <stdio.h>

// ฟังก์ชันสำหรับสลับค่าตัวเลขโดยใช้ Pointer (ไม่ใช้ตัวแปรพักค่า)
void swapNumbers( int *a , int *b ) {
    *a = *a + *b ;   // บวกค่าทั้งสองแล้วเก็บใน a
    *b = *a - *b ;   // หัก b ออก จะเหลือค่าเดิมของ a
    *a = *a - *b ;   // หักค่าใหม่ของ b ออก จะเหลือค่าเดิมของ b
}

int main() {
    int num1 , num2 ;    // ประกาศตัวแปรเก็บตัวเลข
    int *ptr1 , *ptr2 ;  // ประกาศตัวแปร Pointer

    // รับค่าตัวเลขจากผู้ใช้
    printf( "Enter num1 :\n" ) ;
    scanf( "%d", &num1 ) ;

    printf( "Enter num2 :\n" ) ;
    scanf( "%d", &num2 ) ;

    // กำหนดให้ Pointer ชี้ไปยัง num1 และ num2
    ptr1 = &num1 ;
    ptr2 = &num2 ;

    // แสดงค่าก่อนการสลับ
    printf( "Before swap (num1 & num2) : %d, %d\n" , num1, num2 ) ;

    // เรียกใช้ฟังก์ชันสลับค่า
    swapNumbers( ptr1 , ptr2 ) ;

    // แสดงค่าหลังการสลับ
    printf( "After swap (num1 & num2) : %d, %d\n" , num1, num2 ) ;

    return 0 ;
}
