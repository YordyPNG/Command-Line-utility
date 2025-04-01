# Command-Line-utility-tool

This is a program which is a command-line utility that performs various operations on an array of integers: printing the elements, calculating the sum, finding the maximum value, and printing the prime numbers. It takes command-line arguments to specify the desired operation, the array size and the array elements. To provide the command line arguments the program must be run from the terminal of VS Code.

Command-Line Arguments:
1. The program accepts command-line arguments to specify the operation and array elements.
2. The first argument is the option (-p, -s, -m, or -c).
3. The second argument is the size of the array.
4. The remaining arguments (if provided) are the array elements.

Program's functions:
1. Print Array Elements (-p) : This option prints all the elements of the input array in the order on the command line. in reverse order
2. Calculate Sum of Array Elements (-s) : This option calculates the sum of all elements in the input array.
3. Find Maximum Value (-m) : This option finds the maximum value among all elements in the input array.
4. Print Prime Numbers (-c) : This option prints all the prime numbers present in the input array or NONE to denote there are no prime numbers.
5. Program dynamically allocates memory for the input array using malloc. This allows it to handle arrays of different sizes without a fixed limit.
6. The program checks if the minimum required arguments are provided. If not, it prints the usage information and exits with an error code.
7. If fewer array elements are provided than the specified array size, the remaining elements are initialized to 0.
