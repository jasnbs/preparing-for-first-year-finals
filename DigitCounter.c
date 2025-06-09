#include <stdio.h>

int count_digit_occurrences(int number, int c) {
    int count = 0;
    while(number > 0) {
        int digit = number % 10;
        if(digit == c) {
            count++;
        }
        number /= 10;
    }
    return count;
}

void find_and_print_numbers(int a, int b, int c, int d) {
    int total_count = 0;
    printf("\nNumbers in range [%d,%d] containing digit %d exactly %d times:\n", 
           a, b, c, d);
    for(int num = a; num <= b; num++) {
        int occurrences = count_digit_occurrences(num, c);
        if(occurrences == d) {
            printf("%d ", num);
            total_count++;
        }
    }
    printf("\nTotal counts: %d\n", total_count);
}

int main() {
    int a, b;
    do {
        printf("Enter two natural numbers a and b (a < b): ");
        scanf("%d %d", &a, &b);
    } while(a >= b || a <= 0 || b <= 0);
    
    int c, d;
    do {
        printf("Enter digit c (1-9): ");
        scanf("%d", &c);
        printf("Enter count d (0-9): ");
        scanf("%d", &d);
    } while(c >= 10 || c <= 0 || d < 0 || d >= 10);
    
    find_and_print_numbers(a, b, c, d);
    
    printf("\nPress any key to exit...");
    return 0;
}