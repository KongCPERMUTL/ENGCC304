#include <stdio.h>  

int main ( ) {  
    int n ;    
    printf ( "Enter number: " ) ;      // ขอให้ผู้ใช้ป้อนค่า  
    scanf ( "%d" , &n ) ;               // รับค่าจากผู้ใช้  
    int i = n ;                         // เริ่มตรวจสอบจาก n  
    do {
        int x = 1 ;                     // i เป็นจำนวนเฉพาะ  
        int j = 2 ;                     // เริ่มตรวจสอบตัวประกอบที่ 2  
        while ( j <= i / j ) {          // ตรวจสอบไปจนถึง sqrt(i)  
            if ( i % j == 0 )           // ถ้าหารลงตัว  
            {  
                x = 0 ;                 // i ไม่ใช่จำนวนเฉพาะ  
                break ;                 // หยุดตรวจสอบ  
            }  
            j++ ;                       // ไปเช็คตัวถัดไป  
        }  

        if ( x ) {                // ถ้าเป็นจำนวนเฉพาะ  
            printf ( "%d " , i ) ;      // แสดงผล  
        }  

        i-- ;                           // ลดค่า i  
    }  
    while ( i >= 2 ) ; // end do while  // ทำซ้ำจนถึงเลข 2  

    return 0 ;  
}  // end function
