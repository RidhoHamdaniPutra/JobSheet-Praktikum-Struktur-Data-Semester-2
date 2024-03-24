/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>

// Existing structs
struct complex {
    int img;
    float real;
};

struct number {
    struct complex comp;
    int integers;
};

// Level 1
struct Level1 {
    int data1;
    float data2;
};

// Level 2
struct Level2 {
    int data3;
    char data4;
    struct Level1 level1;
};

// Level 3
struct Level3 {
    double data5;
    struct Level2 level2;
    struct number num;
};

// Level 4
struct Level4 {
    long data6;
    struct Level3 level3;
};

// Level 5
struct Level5 {
    char data7;
    struct Level4 level4;
    struct complex comp;
};

int main() {
    struct Level5 nested;

    // Mengisi data
    nested.data7 = 'A';
    nested.level4.data6 = 12345;
    nested.level4.level3.data5 = 3.14159;
    nested.level4.level3.level2.data3 = 42;
    nested.level4.level3.level2.data4 = 'B';
    nested.level4.level3.level2.level1.data1 = 10;
    nested.level4.level3.level2.level1.data2 = 2.718;
    nested.level4.level3.num.integers = 100;
    nested.level4.level3.num.comp.img = 5;
    nested.level4.level3.num.comp.real = 1.618;
    nested.comp.img = 3;
    nested.comp.real = 2.718;

    // Menampilkan nilai
    printf("Level 5 data: %c\n", nested.data7);
    printf("Level 4 data: %ld\n", nested.level4.data6);
    printf("Level 3 data: %f, %d, %d, %f\n", nested.level4.level3.data5, nested.level4.level3.num.integers, nested.level4.level3.num.comp.img, nested.level4.level3.num.comp.real);
    printf("Level 2 data: %d, %c\n", nested.level4.level3.level2.data3, nested.level4.level3.level2.data4);
    printf("Level 1 data: %d, %f\n", nested.level4.level3.level2.level1.data1, nested.level4.level3.level2.level1.data2);
    printf("Complex data: %d, %f\n", nested.comp.img, nested.comp.real);

    return 0;
}
