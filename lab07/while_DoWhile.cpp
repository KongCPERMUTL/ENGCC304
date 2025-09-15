#include <stdio.h>   // ใช้ printf, scanf
#include <stdlib.h>  // ใช้ rand(), srand()
#include <time.h>    // ใช้ time()

int main() {
    srand( time(NULL) ) ;                                                     // ตั้งค่า seed ของ rand() ให้สุ่มไม่ซ้ำทุกครั้งที่รัน

    int menu ;                                                                // ตัวเลือกเมนู (1=เล่นเกม, -1=ออก)
    while ( 1 ) {                                                             // ลูปหลักของโปรแกรม
        printf( "Do you want to play game (1=play,-1=exit) :\n" ) ;
        
        // อ่านค่าเมนูจากผู้ใช้
        if ( scanf( "%d", &menu ) != 1 ) {                                   // ถ้าใส่ไม่ใช่ตัวเลข
            int ch ;
            while ( ( ch = getchar() ) != '\n' && ch != EOF ) ;              // ล้างค่าที่เหลือใน buffer
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;                   // แจ้งเตือนให้ใส่ใหม่
            continue ;                                                       // กลับไปถามเมนูอีกครั้ง
        }

        if ( menu == -1 ) {                                                  // ถ้าเลือก -1 ให้ออกจากโปรแกรม
            printf( "\nSee you again.\n" ) ;
            break ;
        } else if ( menu == 1 ) {                                            // ถ้าเลือก 1 ให้เริ่มเล่นเกม
            int score = 100 ;                                                // คะแนนเริ่มต้น = 100
            int number = rand() % 100 + 1 ;                                  // สุ่มเลขระหว่าง 1 ถึง 100
            int guess ;                                                      // ตัวเลขที่ผู้ใช้ทาย
            int low = 1, high = 100 ;                                        // ขอบเขตต่ำสุดและสูงสุดของการเดา

            printf( "\n(Score=100)\n" ) ;

            // ลูปการทายตัวเลข
            while ( 1 ) {
                printf( "\nGuess the winning number (%d-%d) :\n" , low, high ) ;
                scanf( "%d", &guess ) ;

                if ( guess == number ) {                                      // ถ้าทายถูก
                    printf( "\nThat is correct! The winning number is %d.\n" , number ) ;
                    printf( "\nScore this game: %d\n\n" , score) ;
                    break ;                                                   // จบเกม กลับไปถามเมนูใหม่
                } else {                                                      // ถ้าทายผิด
                    score -= 10 ;                                             // หักคะแนน 10
                    if ( guess < number ) {                                   // ถ้าทายต่ำกว่าเลขจริง
                        printf( "\nSorry, the winning number is HIGHER than %d. (Score=%d)\n" , guess, score ) ;
                        if ( guess + 1 > low ) low = guess + 1 ;              // ปรับขอบเขตต่ำสุด
                    } else {                                                  // ถ้าทายสูงกว่าเลขจริง
                        printf( "\nSorry, the winning number is LOWER than %d. (Score=%d)\n" , guess, score ) ;
                        if ( guess - 1 < high ) high = guess - 1 ;            // ปรับขอบเขตสูงสุด
                    }
                }
            }
        } else {                                                              // ถ้าไม่ใช่ 1 หรือ -1
            printf( "\nPlease enter only 1 or -1.\n\n" ) ;
        }
    }

    return 0 ;                                                                // จบโปรแกรม
}
