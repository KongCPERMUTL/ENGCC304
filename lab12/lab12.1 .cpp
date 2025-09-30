#include    <stdio.h>      
#include    <string.h>     // ไลบรารีสำหรับ string เช่น strcpy ()

// Fix Code
struct  Student  {          // โครงสร้างข้อมูลนักเรียน
    char    Name[20] ;      // ชื่อ ไม่เกิน 20
    char    ID[5] ;         // รหัสนักศึกษา ไม่เกิน 5
    float   ScoreSub1 ;     // คะแนนวิชา 1
    float   ScoreSub2 ;     // คะแนนวิชา 2
    float   ScoreSub3 ;     // คะแนนวิชา 3
    float   ScoreSub4 ;     // คะแนนวิชา 4
    float   ScoreSub5 ;     // คะแนนวิชา 5
} typedef S ;

// ฟังก์ชันตัดเกรด
void    getGrade( float score , char grade[] ) {
    // ตาราง Mapping เกรด (Score → Grade)
    // ------------------------------------------
    // |   Score         | Grade |
    // |-----------------|-------|
    // | 80 – 100        | A     |
    // | 75 – 79         | B+    | 
    // | 70 – 74         | B     |
    // | 65 – 69         | C+    |
    // | 60 – 64         | C     |
    // | 55 – 59         | D+    |
    // | 50 – 54         | D     |
    // | 0  – 49         | F     |
    // -------------------------------------------
    if      ( score >= 80 )    strcpy( grade , "A" ) ;
    else if ( score >= 75 )    strcpy( grade , "B+" ) ;
    else if ( score >= 70 )    strcpy( grade , "B" ) ;
    else if ( score >= 65 )    strcpy( grade , "C+" ) ;
    else if ( score >= 60 )    strcpy( grade , "C" ) ;
    else if ( score >= 55 )    strcpy( grade , "D+" ) ;
    else if ( score >= 50 )    strcpy( grade , "D" ) ;
    else                       strcpy( grade , "F" ) ;
}

int main() {
    S       students[3] ;     // เก็บข้อมูลนักเรียน 3 คน
    char    grade[5][3] ;     // เก็บเกรด 5 วิชา ของ นักเรียน 3 คน
    int     i , j ;           // ตัวแปรลูป
    float   sum , avg ;       // ใช้คำนวณผลรวมและค่าเฉลี่ย
    float   score[5] ;        // เก็บคะแนน 5 วิชาชั่วคราว

    printf( "Enter the details of 3 students :\n" ) ;   // แสดงข้อความ

    // รับข้อมูลนักเรียนทีละคน
    for ( i = 0 ; i < 3 ; i++ ) {
        printf( "Student %d:\n" , i + 1 ) ;            // แสดงหมายเลขนักเรียน

        // รับชื่อแบบมีช่องว่างโดย ใช้ scanf 
        printf( "Name: \n" ) ;
        scanf( " %[^\n]%*c" , students[i] . Name ) ;        // อ่านจนเจอ newline และทิ้ง newline ทิ้ง

        printf( "ID: \n" ) ;
        scanf( "%s" , students[i] . ID ) ;               // รับรหัสนักศึกษา 

        printf( "Scores in Subject 1: \n" ) ;
        scanf( "%f" , &students[i] . ScoreSub1 ) ;       // รับคะแนนวิชา 1

        printf( "Scores in Subject 2: \n" ) ;
        scanf( "%f" , &students[i] . ScoreSub2 ) ;       // รับคะแนนวิชา 2

        printf( "Scores in Subject 3: \n" ) ;
        scanf( "%f" , &students[i] . ScoreSub3 ) ;       // รับคะแนนวิชา 3

        printf( "Scores in Subject 4: \n" ) ;
        scanf( "%f" , &students[i] . ScoreSub4 ) ;       // รับคะแนนวิชา 4

        printf( "Scores in Subject 5: \n" ) ;
        scanf( "%f" , &students[i] . ScoreSub5 ) ;       // รับคะแนนวิชา 5
    }

    // แสดงผลลัพธ์ของนักเรียนแต่ละคน
    for ( i = 0 ; i < 3 ; i++ ) {
        printf( "\nStudent %d:\n" , i + 1 ) ;
        printf( "Name: %s\n" , students[i] . Name ) ;   // แสดงชื่อ
        printf( "ID: %s\n" , students[i] . ID ) ;       // แสดงรหัสนักศึกษา

        // เก็บคะแนนใน array ชั่วคราว
        score[0] = students[i] . ScoreSub1 ;
        score[1] = students[i] . ScoreSub2 ;
        score[2] = students[i] . ScoreSub3 ;
        score[3] = students[i] . ScoreSub4 ;
        score[4] = students[i]  . ScoreSub5 ;

        // แสดงคะแนนทั้งหมด
        printf( "Scores: " ) ;
        for ( j = 0 ; j < 5 ; j++ ) {
            printf( "%.0f " , score[j] ) ;              // แสดงคะแนนทีละตัว
        }
        printf( "\n" ) ;

        // ตัดเกรด
        for ( j = 0 ; j < 5 ; j++ ) {
            getGrade( score[j] , grade[j] ) ;           // ส่งคะแนนเข้า getGrade เพื่อได้เกรด
        }

        // แสดงเกรดทั้งหมด
        printf( "Grades: " ) ;
        for ( j = 0 ; j < 5 ; j++ ) {
            printf( "%s " , grade[j] ) ;
        }
        printf( "\n" ) ;

        // คำนวณค่าเฉลี่ย
        sum = score[0] + score[1] + score[2] + score[3] + score[4] ;  // บวกรวมคะแนน
        avg = sum / 5.0 ;                                              // หาร 5 เพื่อหาค่าเฉลี่ย
        printf( "Average Scores: %.1f\n" , avg ) ;                     // แสดงค่าเฉลี่ย
    }

    return 0 ;   // สิ้นสุดโปรแกรม
}
