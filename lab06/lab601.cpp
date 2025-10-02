#include <stdio.h>

int main() {
    int num ;
    printf( "User Input : " ) ;
    scanf( "%d" , &num ) ;

    // เก็บชื่อเลขเป็นคำ
    char *ones[] = { "zero", "one", "two", "three", "four", "five",
                     "six", "seven", "eight", "nine", "ten",
                     "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" } ;

    char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty",
                     "sixty", "seventy", "eighty", "ninety" } ;

    printf( "Result : " ) ;

    if ( num < 20 ) {
        printf( "%s\n" , ones[num] ) ;
    } else if ( num < 100 ) {
        printf( "%s" , tens[num / 10] ) ;
        if ( num % 10 != 0 ) {
            printf( "-%s" , ones[ num % 10 ] ) ;
        }
        printf( "\n" ) ;
    } else {
        printf( "Not supported yet\n" ) ;
    }

    return 0 ;
}
