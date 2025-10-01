#include <stdio.h>

int main() {
    float H , W , area ;

    printf( "Enter Height (H): " ) ;
    scanf( "%f" , &H ) ;

    printf( "Enter Width/Base (W): " ) ;
    scanf( "%f", &W ) ;

    area = ( H * W ) / 2.0 ;

    printf( "Area = %.1f\n", area ) ;

    return 0 ;
}  // end function
