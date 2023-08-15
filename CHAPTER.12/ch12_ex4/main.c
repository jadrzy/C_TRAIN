#include <stdio.h>
int function (void);
int main(int argc, char** argv){
    for (int i = 0; i < 5; i++){
        printf("%d\n", function());
    }
    return 0;
}