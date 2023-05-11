# include <stdio.h>
void larger_of(double *number1, double *number2);
int main(void){
    double x = -1212.33;
    double y = -0.111;
    larger_of(&x, &y);
    printf("number1: %g\nnumber2: %g\n", x, y);
    return 0;
}
void larger_of(double *number1, double *number2){
    (*number1 > *number2) ? (*number2 = *number1) : (*number1 = *number2);
}