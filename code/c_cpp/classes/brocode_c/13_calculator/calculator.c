#include <stdio.h>

int main() {
    char operator;
    double num1;
    double num2;
    double result;
    char confirm;

    printf("\nEnter an operator (+ - * /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("The equation is [%lf %c %lf]\n", num1, operator, num2);
    printf("Is that correct? (y/n): ");
    scanf(" %c", &confirm);

    switch(confirm) {
        case 'y':
            switch(operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                printf("%c is not a valid operator\n");
            }

            printf("Answer: %lf\n", result);
            break;
        case 'n':
            printf("Please remake your equation\n");
            break;
        default: 
            printf("Please type 'y' or 'n'\n");
            break;
    }

    return 0;
}