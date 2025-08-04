//reference https://www.programiz.com/c-programming/examples/calculator-switch-case

#include <stdio.h> //Library that allows for printf() and scanf() 
// forum that describes the %'s https://stackoverflow.com/questions/210590/why-does-scanf-need-lf-for-doubles-when-printf-is-okay-with-just-f

int main() {
    char operator;
    double firstInput, secondInput;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands in x y format ");
    scanf("%lf %lf", &firstInput, &secondInput);
  switch (operator) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf", firstInput, secondInput, firstInput + secondInput);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf", firstInput, secondInput, firstInput - secondInput);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf", firstInput, secondInput, firstInput * secondInput);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf", firstInput, secondInput, firstInput / secondInput);
      break;
    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }

  return 0;
}