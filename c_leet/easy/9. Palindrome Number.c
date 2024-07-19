#include <stdbool.h>
#include <stdio.h>

/*
Given an integer x, return true if x is a palindrome, and false otherwise.
 */
bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }

    int t = x;
    int rev = 0;
    while (x > 0){
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == t;
}


int main() {
    int x = 120;
    printf("\nX: %d\n", x);
    printf("X is a palindrome: %s\n", isPalindrome(x)? "true":"false");
    return 0;
}