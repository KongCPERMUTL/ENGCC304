#include <iostream>
using namespace std ;

int main(void) {
    int category, choice, money, change ;
    int totalPrice = 0 ;
    int more = 0 ;
    int bill = 0 ;

    // สต็อกสินค้า (จำนวนชิ้น)
    int stock[7] = {5, 5, 5, 5, 5, 5, 5} ;
    // index: 1=โค้ก, 2=น้ำเขียว, 3=อเมริกาโน่, 4=ลาเต้,
    //        5=เมล็ดทานตะวัน, 6=ถั่วแปบ, 7=จิ้นส้มหมก

    int priceList[7] = {10, 12, 30, 35, 13, 20, 15} ;
    string nameList[7] = {
        "โค้ก", "น้ำเขียว", "อเมริกาโน่", "ลาเต้",
        "เมล็ดทานตะวัน", "ถั่วแปบ", "จิ้นส้มหมก"
    };

    cout << "=== เครื่องขายน้ำอัตโนมัติ ตะพาบลอย ===" << endl ;

    do {
        // --- เลือกประเภทสินค้า ---
        cout << "\nเลือกประเภทสินค้า:" << endl ;
        cout << "1. ประเภทน้ำ" << endl ;
        cout << "2. ประเภทขนม" << endl ;
        cout << "เลือก: " ;
        cin >> category ;

        if (category == 1) {
            // --- ประเภทน้ำ ---
            cout << "\n---- ประเภทน้ำ ----" << endl ;
            cout << "1. โค้ก          ราคา 10 บาท (เหลือ " << stock[1] << ")" << endl ;
            cout << "2. น้ำเขียว      ราคา 12 บาท (เหลือ " << stock[2] << ")" << endl ;
            cout << "3. อเมริกาโน่     ราคา 30 บาท (เหลือ " << stock[3] << ")" << endl ;
            cout << "4. ลาเต้         ราคา 35 บาท (เหลือ " << stock[4] << ")" << endl ;

            cout << "เลือกสินค้า (1-4): " ;
            cin >> choice ;

            if (choice < 1 || choice > 4) {
                cout << "เลือกไม่ถูกต้อง!" << endl ;
                continue ;
            }

        } else if (category == 2) {
            // --- ประเภทขนม ---
            cout << "\n---- ประเภทขนม ----" << endl ;
            cout << "5. เมล็ดทานตะวัน ราคา 13 บาท (เหลือ " << stock[5] << ")" << endl ;
            cout << "6. ถั่วแปบ       ราคา 20 บาท (เหลือ " << stock[6] << ")" << endl ;
            cout << "7. จิ้นส้มหมก    ราคา 15 บาท (เหลือ " << stock[7] << ")" << endl ;

            cout << "เลือกสินค้า (5-7): " ;
            cin >> choice ; 

            if (choice < 5 || choice > 7) {
                cout << "เลือกไม่ถูกต้อง!" << endl ;
                continue ;
            }

        } else {
            cout << "เลือกประเภทไม่ถูกต้อง!" << endl ;
            continue ;
        }

        // --- ตรวจสอบสต็อก ---
        if (stock[choice] <= 0) {
            cout << "ขออภัย! " << nameList[choice] << " หมดสต็อก กรุณาเลือกใหม่" << endl ;
            continue ; // กลับไปเลือกประเภทสินค้าใหม่
        }

        // --- เพิ่มสินค้าลงตะกร้า ---
        stock[choice]--;
        totalPrice += priceList[choice] ;
        cout << "คุณเลือก: " << nameList[choice] << " (ราคา " << priceList[choice] << " บาท)" << endl;

        // --- ถามว่าจะเลือกเพิ่มไหม ---
        cout << "ต้องการเลือกสินค้าเพิ่มเติมหรือไม่? (1=ใช่, 0=ไม่): " ;
        cin >> more ;

    } while (more == 1) ;

    // --- รับเงินรวม ---
    cout << "\nราคารวมทั้งหมด: " << totalPrice << " บาท" << endl ;
    cout << "กรุณาหยอดเงิน: " ;
    cin >> money ;

    if (money < totalPrice) {
        cout << "จำนวนเงินไม่พอ! กรุณาหยอดเพิ่มครั้งหน้า" << endl ;
        return 0 ;
    }

    change = money - totalPrice ;

    // --- จ่ายสินค้า ---
    cout << "\n=== กำลังจ่ายสินค้า ===" << endl ;
    cout << "คุณได้รับสินค้าเรียบร้อย" << endl ;
    if (change > 0) {
        cout << "เงินทอน: " << change << " บาท" << endl ;
    } else {
        cout << "ไม่มีเงินทอน" << endl ;
    }

    // --- ถามว่าต้องการรับบิลไหม ---
    cout << "\nต้องการรับบิลหรือไม่? (1=ใช่, 0=ไม่): " ;
    cin >> bill ;

    if (bill == 1) {
        cout << "กำลังพิมพ์บิล..." << endl ;
        cout << "=== บิลของคุณ ===" << endl ;
        cout << "ยอดรวม: " << totalPrice << " บาท" << endl ;
        cout << "เงินที่จ่าย: " << money << " บาท" << endl ;
        cout << "เงินทอน: " << change << " บาท" << endl ;
        cout << "================" << endl ;
    }

    // --- จบการทำงาน ---
    cout << "\n=== ขอบคุณที่ใช้บริการ ตะพาบลอย ===" << endl ;
    return 0 ;
}
