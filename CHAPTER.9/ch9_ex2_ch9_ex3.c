// function chline
#include <stdio.h>
void chline(char ch,int i ,int j); // function prototype
int main(void){
    char character = 'x';
    int col = 40;
    int raw = 11;
    chline(character, col, raw);
    return 0;
}
void chline(char ch, int i, int j){
    int a, b;
    for (a = 1; a <= j; a++){
        for (b = 1; b <= i; b++){
                printf("x");
        }
        printf("\n");
    }
}