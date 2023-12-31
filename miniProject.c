#include <stdio.h>
#include <math.h>
#include <string.h>

// Defining functions
int power(int base, int power);

int main()
{
    // Defining strings for the numbers
    char digits[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char special[9][10] = {"eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char tens[9][8] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char denominations[4][9] = {"and", "hundred", "thousand", "million"};
    char writtenNumber[150];

    // Defining integer and integer string for input
    unsigned long int input;
    int separatedInput[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // This is predefined so that numbers with less digits can be used in the function readArray
    int is_empty[3] = {0, 0, 0}; // This is used to check if a row of the 2d array is a set of all 0s

    // Getting the number to convert
    printf("Enter a number to convert: ");
    scanf("%d", &input);

    // Converting the integer to an integer array
    int numLength = log10(input) + 1;
    printf("The length of the number %d has %d digits.\n", input, numLength); // Trouble shooting test

    for (int i = 3; i > 0; i--)
    {
        for (int j = 3; j > 0; j--)
        {
            separatedInput[i - 1][j - 1] = input / power(10, 10 - i * 3 - j + 3 - 1) % 10;
        }
        if (separatedInput[i - 1][0] == 0 && separatedInput[i - 1][1] == 0 && separatedInput[i - 1][2] == 0)
        {
            is_empty[i - 1] = 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (is_empty[i] == 1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0 && separatedInput[i][j] !=0)
                {
                    strcat(writtenNumber, digits[separatedInput[i][j] - 1]);
                    strcat(writtenNumber, " ");
                    strcat(writtenNumber, denominations[1]);
                }
                else if (j == 1)
                {
                    if (separatedInput[i][j] == 1)
                    {
                        strcat(writtenNumber, special[separatedInput[i][j] - 1]);
                    }
                    else if (separatedInput[i][j] == 0 && separatedInput[i][j - 1] != 0)
                    {
                        strcat(writtenNumber, denominations[0]);
                    }
                    else
                    {
                        strcat(writtenNumber, tens[separatedInput[i][j] - 1]);
                    }
                }
                else
                {
                    if (separatedInput[i][j] != 0)
                    {
                        strcat(writtenNumber, digits[separatedInput[i][j] - 1]);
                    }
                }
                strcat(writtenNumber, " ");
            }

            if (i == 0)
            {
                strcat(writtenNumber, denominations[3]);
            }
            else if (i == 1)
            {
                strcat(writtenNumber, denominations[2]);
            }
            strcat(writtenNumber, " ");
        }
    }

    printf("The number you entered, %d is written as:\n%s", input, writtenNumber);
}

// Power function the finds the power of a number as an integer rather than built in function that returns a double
int power(int base, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result = result * base;
    }
    return result;
}
