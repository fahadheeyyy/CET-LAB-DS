#include <stdio.h>

typedef unsigned int Set;


void printBitString(Set s, int n) {
    printf("Elements: ");
    for (int i = n - 1; i >= 0; i--) printf("%2d ", i);
    printf("\nBits:     ");
    for (int i = n - 1; i >= 0; i--) printf(" %d ", (s >> i) & 1);
    printf("\n");
}

void printSet(Set s, int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (s & (1U << i))
            printf("%d ", i);
    }
    printf("}\n");
}

int main() {
    int n = 9; 
    // Set A = 0b10101010;
    // Set B = 0b10111000; 
    int A=0b10101010;
    int B=0b10111000;

    printf("Set A = "); printSet(A, n);
    printBitString(A, n);

    printf("\nSet B = "); printSet(B, n);
    printBitString(B, n);

    Set U = ((A) | (B));
    Set I = ((A) & (B));
    Set D = ((A) & ~(B));

    printf("\nA ∪ B = "); printSet(U, n);
    printBitString(U, n);

    printf("\nA ∩ B = "); printSet(I, n);
    printBitString(I, n);

    printf("\nA - B = "); printSet(D, n);
    printBitString(D, n);

    return 0;
}
