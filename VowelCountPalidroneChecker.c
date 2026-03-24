/*
 * ================================================================
 * Program: String Operations in C
 * Description:
 *   This program takes a string input from the user and performs:
 *     1. Counts the number of vowels (a, e, i, o, u - case insensitive)
 *     2. Reverses the string
 *     3. Checks if the string is a palindrome
 *
 * Concepts Used:
 *   - Functions
 *   - Arrays (Strings)
 *   - Loops and conditionals
 *   - string.h library (strlen, strcspn)
 *   - ctype.h library (tolower)
 *
 * ================================================================
 */

#include <stdio.h>    // For input/output functions
#include <string.h>   // For string handling functions
#include <ctype.h>    // For character handling functions

/*
 * Function: countVowels
 * ---------------------
 * Counts the number of vowels in a given string.
 *
 * str: input string
 *
 * returns: number of vowels found
 */
int countVowels(char str[]) {
    int count = 0;

    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase for uniform comparison
        char ch = tolower(str[i]);

        // Check if character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

/*
 * Function: reverseString
 * -----------------------
 * Reverses the given string and stores it in another array.
 *
 * str: original string
 * reversed: array to store reversed string
 */
void reverseString(char str[], char reversed[]) {
    int len = strlen(str); // Get length of string

    // Copy characters from end to beginning
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }

    // Add null terminator to mark end of string
    reversed[len] = '\0';
}

/*
 * Function: isPalindrome
 * ----------------------
 * Checks whether a string is a palindrome.
 *
 * str: input string
 *
 * returns: 1 if palindrome, 0 otherwise
 */
int isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    // Compare characters from both ends moving toward center
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }

    return 1; // String is a palindrome
}

/*
 * Main Function
 * -------------
 * Handles user input and calls other functions
 */
int main() {
    char str[100];        // Array to store input string
    char reversed[100];  // Array to store reversed string

    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    // Call functions
    int vowels = countVowels(str);
    reverseString(str, reversed);
    int palindrome = isPalindrome(str);

    // Display results
    printf("\nNumber of vowels: %d\n", vowels);
    printf("Reversed string: %s\n", reversed);

    if (palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}