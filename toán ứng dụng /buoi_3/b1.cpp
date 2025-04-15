#include <stdio.h>

void check_modular_properties(int x, int y, int m) {
    int left, right;

    left = (x + y) % m;
    right = ((x % m) + (y % m)) % m;
    printf("\n(%d + %d) mod %d = (%d mod %d + %d mod %d) mod %d => %s",
           x, y, m, x, m, y, m, m, (left == right) ? "True" : "False");

    left = (x - y) % m;
    right = ((x % m) - (y % m)) % m;
    printf("\n(%d - %d) mod %d = (%d mod %d - %d mod %d) mod %d => %s",
           x, y, m, x, m, y, m, m, (left == right) ? "True" : "False");

    left = (x * y) % m;
    right = ((x % m) * (y % m)) % m;
    printf("\n(%d * %d) mod %d = (%d mod %d * %d mod %d) mod %d => %s\n",
           x, y, m, x, m, y, m, m, (left == right) ? "True" : "False");
}

int main() {
    int x, y, m;
    
    printf("Enter number 1: ");
    scanf("%d", &x);
    printf("Enter number 2: ");
    scanf("%d", &y);
    printf("Enter divisor: ");
    scanf("%d", &m);
    
    check_modular_properties(x, y, m);
    
    return 0;
}