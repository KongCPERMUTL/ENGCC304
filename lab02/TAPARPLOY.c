#include <stdio.h>
#include <windows.h>

int main( void ) {
    SetConsoleOutputCP( 65001 ) ;
    SetConsoleCP( 65001 ) ;

    int category , choice , money , insert , change , qty ;
    int totalPrice = 0 ;
    int more = 0 ;
    int bill = 0 ;

    int stock[8]     = {0, 5, 5, 5, 5, 5, 5, 5} ;
    int priceList[8] = {0, 10, 12, 30, 35, 13, 20, 15} ;
    char *nameList[8] = {
        "" , "โค้ก" , "น้ำเขียว" , "อเมริกาโน่" , "ลาเต้", "เมล็ดทานตะวัน" , "ถั่วแปบ" , "จิ้นส้มหมก"
    } ;
    char *unit[8] = {
        "", "กระป๋อง" , "กระป๋อง" , "แก้ว" , "แก้ว" , "ถุง" , "ถุง" , "ชิ้น"
    } ;

    int cart[8] = {0} ;

    printf( "=== เครื่องขายน้ำอัตโนมัติ ตะพาบลอย ===\n" ) ;

    do {
        printf( "\nเลือกประเภทสินค้า:\n" ) ;
        printf( "1. ประเภทน้ำ\n" ) ;
        printf( "2. ประเภทขนม\n" ) ;
        printf( "เลือก: " ) ;
        scanf( "%d" , &category ) ;

        if ( category == 1 ) {
            if ( stock[1] <= 0 && stock[2] <= 0 && stock[3] <= 0 && stock[4] <= 0 ) {
                printf( "\n❌ ขอโทษครับ หมวด 'น้ำ' สินค้าหมดแล้ว!\n" ) ;
                continue ;
            }

            int valid = 0 ;
            while ( !valid ) {
                printf( "\n---- ประเภทน้ำ ----\n" ) ;
                printf( "1. โค้ก          ราคา 10 บาท (เหลือ %d)\n" , stock[1] ) ;
                printf( "2. น้ำเขียว      ราคา 12 บาท (เหลือ %d)\n" , stock[2] ) ;
                printf( "3. อเมริกาโน่     ราคา 30 บาท (เหลือ %d)\n" , stock[3] ) ;
                printf( "4. ลาเต้         ราคา 35 บาท (เหลือ %d)\n" , stock[4] ) ;

                printf( "เลือกสินค้า (1-4): " ) ;
                scanf( "%d" , &choice ) ;

                if ( choice < 1 || choice > 4 ) {
                    printf( "เลือกไม่ถูกต้อง!\n" ) ;
                    continue ;
                }

                if ( stock[choice] <= 0 ) {
                    printf( "ขออภัย! %s หมดสต็อก กรุณาเลือกใหม่\n" , nameList[choice] ) ;
                    continue ;
                }

                // เลือกจำนวนสินค้า
                printf( "จำนวนที่ต้องการซื้อ (%s, เหลือ %d): " , unit[choice], stock[choice]) ;
                scanf( "%d" , &qty ) ;

                if ( qty < 1 || qty > stock[choice] ) {
                    printf( "จำนวนไม่ถูกต้อง! กรุณาเลือกใหม่\n" ) ;
                    continue ;
                }

                stock[choice] -= qty ;
                cart[choice] += qty ;
                totalPrice += qty * priceList[choice] ;

                printf( "คุณเลือก: %s x %d %s (รวม %d บาท)\n" ,
                       nameList[choice] , qty , unit[choice] , qty * priceList[choice] ) ;

                valid = 1 ;
            }
        }
        else if ( category == 2 ) {
            if ( stock[5] <= 0 && stock[6] <= 0 && stock[7] <= 0 ) {
                printf( "\n❌ ขอโทษครับ หมวด 'ขนม' สินค้าหมดแล้ว!\n" ) ;
                continue ;
            }

            int valid = 0 ;
            while ( !valid ) {
                printf( "\n---- ประเภทขนม ----\n" ) ;
                printf( "5. เมล็ดทานตะวัน ราคา 13 บาท (เหลือ %d)\n" , stock[5] ) ;
                printf( "6. ถั่วแปบ       ราคา 20 บาท (เหลือ %d)\n" , stock[6] ) ;
                printf( "7. จิ้นส้มหมก    ราคา 15 บาท (เหลือ %d)\n" , stock[7] ) ;

                printf( "เลือกสินค้า (5-7): " ) ;
                scanf( "%d", &choice ) ;

                if ( choice < 5 || choice > 7 ) {
                    printf( "เลือกไม่ถูกต้อง!\n" ) ;
                    continue ;
                }

                if ( stock[choice] <= 0 ) {
                    printf( "ขออภัย! %s หมดสต็อก กรุณาเลือกใหม่\n" , nameList[choice] ) ;
                    continue ;
                }

                // เลือกจำนวนสินค้า
                printf( "จำนวนที่ต้องการซื้อ (%s, เหลือ %d): ", unit[choice], stock[choice] ) ;
                scanf( "%d" , &qty ) ;

                if ( qty < 1 || qty > stock[choice] ) {
                    printf( "จำนวนไม่ถูกต้อง! กรุณาเลือกใหม่\n" ) ;
                    continue ;
                }

                stock[choice] -= qty ;
                cart[choice] += qty ;
                totalPrice += qty * priceList[choice] ;

                printf( "คุณเลือก: %s x %d %s (รวม %d บาท)\n" ,
                       nameList[choice] , qty , unit[choice] , qty * priceList[choice] ) ;

                valid = 1 ;
            }
        }
        else {
            printf( "เลือกประเภทไม่ถูกต้อง!\n" ) ;
            continue ;
        }

        printf( "ต้องการเลือกสินค้าเพิ่มเติมหรือไม่? (1=ใช่, 0=ไม่): " ) ;
        scanf( "%d" , &more ) ;

    } while ( more == 1 ) ;

    printf( "\nราคารวมทั้งหมด: %d บาท\n" , totalPrice ) ;

    // ---- ระบบหยอดเงิน ----
    money = 0 ;
    while ( money < totalPrice ) {
        printf( "กรุณาหยอดเงิน (คงเหลืออีก %d บาท): " , totalPrice - money ) ;
        scanf( "%d" , &insert ) ;
        money += insert ;

        if ( money < totalPrice ) {
            printf( "❌ เงินยังไม่พอ! ตอนนี้คุณหยอดแล้ว %d บาท\n" , money ) ;
        }
    }
    change = money - totalPrice ;
    // ---------------------------

    printf( "\n=== กำลังจ่ายสินค้า ===\n" ) ;
    printf( "คุณได้รับสินค้าเรียบร้อย\n" ) ;
    if ( change > 0 ) {
        printf( "เงินทอน: %d บาท\n" , change ) ;
    } else {
        printf( "ไม่มีเงินทอน\n" ) ;
    }

    printf( "\nต้องการรับบิลหรือไม่? (1=ใช่, 0=ไม่): " ) ;
    scanf( "%d" , &bill ) ;

    if ( bill == 1 ) {
        printf( "กำลังพิมพ์บิล...\n" ) ;
        printf( "=== บิลของคุณ ===\n" ) ;

        for ( int i = 1 ; i <= 7 ; i++ ) {
            if ( cart[i] > 0 ) {
                printf( "%s x %d %s = %d บาท\n" ,
                       nameList[i] , cart[i] , unit[i] , cart[i] * priceList[i] ) ;
            }
        }

        printf( "----------------\n" ) ;
        printf( "ยอดรวม: %d บาท\n" , totalPrice ) ;
        printf( "เงินที่จ่าย: %d บาท\n" , money ) ;
        printf( "เงินทอน: %d บาท\n" , change ) ;
        printf( "================\n" ) ;
    }

    printf( "\n=== ขอบคุณที่ใช้บริการ ตะพาบลอย ===\n" ) ;

    return 0 ;

}
