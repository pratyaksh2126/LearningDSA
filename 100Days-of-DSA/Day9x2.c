#include <stdio.h>

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;

    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("true");
    else
        printf("false");

    return 0;
}
