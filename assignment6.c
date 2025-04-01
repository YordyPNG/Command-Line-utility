#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes (these are like shortcuts to what the program can do)
void printArray(int *array, int size);
int calculateSum(int *array, int size);
int findMax(int *array, int size);
void printPrimes(int *array, int size);
bool isPrime(int number);

int main(int argc, char *argv[]) {
    // If not enough arguments are given, show the instructions
    if (argc < 3) {
        printf("Usage: %s <option> <array_size> [array_elements...]\n", argv[0]);
        printf("Options:\n");
        printf("  -p: Print array elements\n");
        printf("  -s: Calculate the sum of array elements\n");
        printf("  -m: Find the maximum value in the array\n");
        printf("  -c: Print the prime numbers in the array\n");
        return 1;
    }

    // Get the user's choice (option) and array size
    char *option = argv[1];
    int size = atoi(argv[2]); // Turn the array size from a string into a number

    // Make sure the size is valid
    if (size <= 0) {
        printf("Error: Array size must be a positive number. >:O\n");
        return 1;
    }

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) { // Check if memory allocation worked
        printf("Error: Could not allocate memory. >>:#\n");
        return 1;
    }

    // Fill the array with values or set missing ones to 0
    for (int i = 0; i < size; i++) {
        if (i + 3 < argc) { // Check if there's a number provided
            array[i] = atoi(argv[i + 3]);
        } else {
            array[i] = 0; // Fill in missing numbers with 0
        }
    }

    // Check the option and do the right thing
    if (strcmp(option, "-p") == 0) {
        printArray(array, size);
    } else if (strcmp(option, "-s") == 0) {
        int sum = calculateSum(array, size);
        printf("Sum of array elements: %d :D\n", sum);
    } else if (strcmp(option, "-m") == 0) {
        int max = findMax(array, size);
        printf("Maximum value in the array: %d ;)\n", max);
    } else if (strcmp(option, "-c") == 0) {
        printPrimes(array, size);
    } else {
        printf("Error: '%s' is not a valid option.\n", option);
    }

    // Free the memory we allocated
    free(array);

    return 0;
}

// This function prints the array elements
void printArray(int *array, int size) {
    printf("Array elements:");
    for (int i = 0; i < size; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
}

// This function adds up all the numbers in the array
int calculateSum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// This function finds the biggest number in the array
int findMax(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// This function prints all the prime numbers in the array
void printPrimes(int *array, int size) {
    bool foundPrime = false;
    printf("Prime numbers in the array:");
    for (int i = 0; i < size; i++) {
        if (isPrime(array[i])) {
            printf(" %d", array[i]);
            foundPrime = true;
        }
    }
    if (!foundPrime) {
        printf(" None :(");
    }
    printf("\n");
}

// This function checks if a number is prime
bool isPrime(int number) {
    if (number <= 1) return false; // Numbers <= 1 are not prime
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false; // Not prime if divisible by i
    }
    return true; // It's a prime number
}