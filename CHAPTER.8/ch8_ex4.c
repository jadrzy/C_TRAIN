/* script counts average number of letters in entered words */
/* digits are counted as letters */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
int main(void){
    bool new_word = false;
    char ch;
    int words = 0, letters = 0;
    float average = 0.0;
    while((ch = getchar()) != EOF){
        /* isalnum checks if ch is a letter or number */
        if (isalnum(ch) && new_word == false){
            new_word = true;
            letters++;
        }else if (isalnum(ch) && new_word == true){
            letters++;
        }else{
            sleep(0);
        }
        /* setting tab and newline as space */
        ch == '\n' ? ch = ' ' : sleep(0);
        ch == '\t' ? ch = ' ' : sleep(0);  
        /* incrementing words when conditions are met */
        if (ch == ' ' && (new_word == true)){
            words++;
            new_word = false;
        }
    }
    /* protection form dividing by 0 */
    if (words == 0)
        average = 0.0;
    else
        average = (float) letters / (float) words;
    printf("Average number of letters in entered words is %0.2f\n"
    , average);
    return 0;
}