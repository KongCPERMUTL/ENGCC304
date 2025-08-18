#include <stdio.h>

int main(void) {
    int category, choice, money, change;
    int totalPrice = 0;
    int more = 0;
    int bill = 0;

    // สต็อกสินค้า (จำนวนชิ้น)
    int stock[7] = {5, 5, 5, 5, 5, 5, 5};
    // index: 1=โค้ก, 2=น้ำเขียว, 3=อเมริกาโน่, 4=ลาเต้, 5=เมล็ดทานตะวัน, 6=ถั่วแปบ, 7=จิ้นส้มหมก

    int priceList[7] = {10, 12, 30, 35, 13, 20, 15} ;
    char *nameList[7] = {
        "โค้ก", "น้ำเขียว", "อเมริกาโน่", "ลาเต้",
        "เมล็ดทานตะวัน", "ถั่วแปบ", "จิ้นส้มหมก"
    };

    printf("=== เครื่องขายน้ำอัตโนมัติ ตะพาบลอย ===\n") ;

    do {
        // --- เลือกประเภทสินค้า ---
        printf("\nเลือกประเภทสินค้า:\n") ;
        printf("1. ประเภทน้ำ\n") ;
        printf("2. ประเภทขนม\n") ;
        printf("เลือก: ") ;
        scanf("%d", &category) ;

        if (category == 1) {
            // --- ประเภทน้ำ ---
            printf("\n---- ประเภทน้ำ ----\n") ;
            printf("1. โค้ก          ราคา 10 บาท (เหลือ %d)\n", stock[1]) ;
            printf("2. น้ำเขียว      ราคา 12 บาท (เหลือ %d)\n", stock[2]) ;
            printf("3. อเมริกาโน่     ราคา 30 บาท (เหลือ %d)\n", stock[3]) ;
            printf("4. ลาเต้         ราคา 35 บาท (เหลือ %d)\n", stock[4]) ;

            printf("เลือกสินค้า (1-4): ") ;
            scanf("%d", &choice) ;

            if (choice < 1 || choice > 4) {
                printf("เลือกไม่ถูกต้อง!\n") ;
                continue;
            }

        } else if (category == 2) {
            // --- ประเภทขนม ---
            printf("\n---- ประเภทขนม ----\n");
            printf("5. เมล็ดทานตะวัน ราคา 13 บาท (เหลือ %d)\n", stock[5]) ;
            printf("6. ถั่วแปบ       ราคา 20 บาท (เหลือ %d)\n", stock[6]) ;
            printf("7. จิ้นส้มหมก    ราคา 15 บาท (เหลือ %d)\n", stock[7]) ;

            printf("เลือกสินค้า (5-7): ") ;
            scanf("%d", &choice) ;

            if (choice < 5 || choice > 7) {
                printf("เลือกไม่ถูกต้อง!\n") ;
                continue ;
            }

        } else {
            printf("เลือกประเภทไม่ถูกต้อง!\n") ;
            continue ;
        }

        // --- ตรวจสอบสต็อก ---
        if (stock[choice] <= 0) {
            printf("ขออภัย! %s หมดสต็อก กรุณาเลือกใหม่\n", nameList[choice])  ;
            continue; // กลับไปเลือกประเภทสินค้าใหม่
        }

        // --- เพิ่มสินค้าลงตะกร้า ---
        stock[choice]--;
        totalPrice += priceList[choice] ;
        printf("คุณเลือก: %s (ราคา %d บาท)\n", nameList[choice], priceList[choice]) ;

        // --- ถามว่าจะเลือกเพิ่มไหม ---
        printf("ต้องการเลือกสินค้าเพิ่มเติมหรือไม่? (1=ใช่, 0=ไม่): ") ;
        scanf("%d", &more) ;

    } while (more == 1) ;

    // --- รับเงินรวม ---
    printf("\nราคารวมทั้งหมด: %d บาท\n", totalPrice) ;
    printf("กรุณาหยอดเงิน: ") ;
    scanf("%d", &money) ;

    if (money < totalPrice) {
        printf("จำนวนเงินไม่พอ! กรุณาหยอดเพิ่มครั้งหน้า\n") ;
        return 0 ;
    }

    change = money - totalPrice ;

    // --- จ่ายสินค้า ---
    printf("\n=== กำลังจ่ายสินค้า ===\n") ;
    printf("คุณได้รับสินค้าเรียบร้อย\n") ;
    if (change > 0) {
        printf("เงินทอน: %d บาท\n", change) ;
    } else {
        printf("ไม่มีเงินทอน\n") ;
    }

    // --- ถามว่าต้องการรับบิลไหม ---
    printf("\nต้องการรับบิลหรือไม่? (1=ใช่, 0=ไม่): ") ;
    scanf("%d", &bill) ;

    if (bill == 1) {
        printf("กำลังพิมพ์บิล...\n") ;
        printf("=== บิลของคุณ ===\n") ;
        printf("ยอดรวม: %d บาท\n", totalPrice) ;
        printf("เงินที่จ่าย: %d บาท\n", money) ;
        printf("เงินทอน: %d บาท\n", change) ;
        printf("================\n") ;
    }

    // --- จบการทำงาน ---
    printf("\n=== ขอบคุณที่ใช้บริการ ตะพาบลอย ===\n") ;
    return 0 ;
}
