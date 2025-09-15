#include <stdio.h>

int main() {
    char word[ 100 ] ;            // เก็บข้อความจากผู้ใช้
    int len = 0 ;                 // ตัวแปรเก็บความยาวสตริง
    int palindrome = 1 ;          // สมมติว่าเป็น palindrome

    printf( "Enter word:\n" ) ;   // ขอให้ผู้ใช้กรอกคำ
    scanf( "%s" , word ) ;        // รับคำ (ไม่รองรับเว้นวรรค)

    // หาความยาวสตริงเอง (จนกว่าจะเจอ '\0')
    while ( word[ len ] != '\0' ) {
        len++ ;
    }

    // ตรวจสอบ palindrome
    for ( int i = 0 ; i < len / 2 ; i++ ) {
        if ( word[ i ] != word [ len - i - 1 ] ) {
            palindrome = 0 ;      // ไม่ใช่ palindrome
            break;                // หยุดการตรวจสอบ
        }
    }

    // แสดงผล
    if ( palindrome == 1 )
        printf( "Pass.\n" ) ;
    else
        printf( "Not Pass.\n" ) ;

    return 0 ;                    // จบโปรแกรม
}
