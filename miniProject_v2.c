#include <stdio.h>
#include <math.h>
#include <string.h>

// Defining functions
int power(int base, int power);

int main()
{
    // Defining strings for the numbers
    char digits[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char special[10][10] = {"ten", "eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char tens[8][8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char denominations[4][9] = {"and", "million", "thousand", "hundred"};
    char writtenNumber[150] = "";

    // Defining integer and integer string for input
    unsigned long int input;
    int separatedInput[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // This is predefined so that numbers with less digits can be used in the function readArray
    
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
    }
    for (int i = 0; i < 3; i++)
    {
        if (separatedInput[i][0] == 0 && separatedInput[i][1] == 0 && separatedInput[i][2] == 0)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                switch (j)
                {
                case 0:
                    if (separatedInput[i][j] != 0)
                    {
                        strcat(writtenNumber, digits[separatedInput[i][j] - 1]);
                        strcat(writtenNumber, " ");
                        if (i != 3)
                        {
                            strcat(writtenNumber, denominations[3]);
                            strcat(writtenNumber, " ");
                        }
                    }
                    break;
                case 1:
                    if (separatedInput[i][j] == 1)
                    {
                        strcat(writtenNumber, special[separatedInput[i][j + 1]]);
                    }
                    else if (separatedInput[i][j] != 0)
                    {
                        strcat(writtenNumber, tens[separatedInput[i][j] - 2]);
                    }

                    strcat(writtenNumber, " ");
                    break;
                case 2:
                    if (separatedInput[i][j] != 0)
                    {
                        strcat(writtenNumber, digits[separatedInput[i][j] - 1]);
                        strcat(writtenNumber, " ");
                    }
                    break;
                }
            }
            if (i != 2)
            {
                strcat(writtenNumber, denominations[i + 1]);
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
