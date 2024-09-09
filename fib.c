#include <stdio.h>
#include <stdlib.h>  

int fibonacci_sequence(int userInput, char input) {
    int number1 = 0;
    int number2 = 1;
    int result = 0;

    if (userInput == 0) {
        return 0;
    } else if (userInput == 1) {
        return 1;
    }

    if (input == 'i') {
        for (int i = 2; i <= userInput; i++) {
            result = number1 + number2;
            number1 = number2;
            number2 = result;
        }
        return number2;  
    } else if (input == 'r') {
        if (userInput <= 1) {
            return userInput;
        }
        return fibonacci_sequence(userInput - 1, input) + fibonacci_sequence(userInput - 2, input);
    }
    return -1;  
}

int main(int argc, char *argv[]) {
    int userInput;              
    char input = argv[2][0]; 
    char *fileName = argv[3]; 
    sscanf(argv[1], "%d", &userInput);

    FILE *fptr;
    int fileNumber;

    fptr = fopen(fileName, "r");

    if (fptr == NULL) {
        printf("File does not exist: %s\n", fileName);
        return 1;
    }

    fscanf(fptr, "%d", &fileNumber);
    fclose(fptr);

    userInput += fileNumber;
    userInput -= 1;

    int result = fibonacci_sequence(userInput, input);

    printf("%d\n", result);

    return 0;
}