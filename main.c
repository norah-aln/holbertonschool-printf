#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2;

    printf("=== Testing _printf ===\n");
    
    /* Test Task 0: c, s, % */
    len = _printf("Character: [%c]\n", 'H');
    len2 = printf("Character: [%c]\n", 'H');
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    len = _printf("String: [%s]\n", "Hello World!");
    len2 = printf("String: [%s]\n", "Hello World!");
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    len = _printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    /* Test Task 1: d, i */
    printf("=== Testing Task 1 (d, i) ===\n");
    len = _printf("Positive: [%d]\n", 123);
    len2 = printf("Positive: [%d]\n", 123);
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    len = _printf("Negative: [%i]\n", -456);
    len2 = printf("Negative: [%i]\n", -456);
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    len = _printf("Zero: [%d]\n", 0);
    len2 = printf("Zero: [%d]\n", 0);
    printf("Our len: %d, Standard len: %d\n\n", len, len2);

    return (0);
}
