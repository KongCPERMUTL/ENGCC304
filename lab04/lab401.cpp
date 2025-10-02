#include <stdio.h>

int main() {
    int days ;               // ตัวแปรเก็บจำนวนวัน
    long long seconds ;      // ตัวแปรเก็บจำนวนวินาที

    printf( "Input Days : " ) ;
    scanf( "%d" , &days ) ;     // รับค่าจำนวนวันจากผู้ใช้

    seconds = ( long long )days * 24 * 60 * 60 ;   // คำนวณวันเป็นวินาที

    printf( "%d days = %lld seconds\n" , days , seconds ) ;

    return 0 ;
}
