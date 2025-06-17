#include <stdio.h>
#include <stdlib.h>

// [1] Hàm hoán vị truyền tham trị
void HoanViThamTri(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// [2] Hàm hoán vị truyền tham biến (sử dụng con trỏ)
void HoanViThamChieu(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    // [1] Truyền tham trị
    int x1 = 5, y1 = 10;
    printf("Truyen tham tri:\n");
    printf("Truoc khi hoan vi: x1=%d, y1=%d\n", x1, y1);
    HoanViThamTri(x1, y1); // Gọi hàm hoán vị truyền tham trị
    printf("Sau khi hoan vi: x1=%d, y1=%d\n\n", x1, y1);

    // [2] Truyền tham biến (sử dụng con trỏ)
    int x2 = 5, y2 = 10;
    printf("Truyen tham chieu (su dung con tro):\n");
    printf("Truoc khi hoan vi: x2=%d, y2=%d\n", x2, y2);
    HoanViThamChieu(&x2, &y2); // Gọi hàm hoán vị truyền tham chiếu
    printf("Sau khi hoan vi: x2=%d, y2=%d\n\n", x2, y2);

    // [3] Biến tham chiếu (không hỗ trợ trong C, chỉ hỗ trợ trong C++)
    // Trong C, chúng ta sử dụng con trỏ để mô phỏng tham chiếu
    int x3 = 5;
    int* y3 = &x3; // y3 là con trỏ trỏ đến x3
    printf("Bien tham chieu (su dung con tro):\n");
    printf("x3: Addr=%p, Val=%d\n", (void*)&x3, x3);
    printf("y3: Addr=%p, Val=%p, ValRef=%d\n", (void*)&y3, (void*)y3, *y3);

    return 0;
}