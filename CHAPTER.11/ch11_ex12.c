#include <stdio.h>
#include <ctype.h>
#include <string.h>
char *gets(char *st, int n);
void counter(char *st);

int main(int argc, char** argv){
    char array[100];
    puts(gets(array, 100));
    counter(array);
}
char *gets(char *st, int n){
    char *ret_val;
    ret_val = fgets(st, n, stdin);        
    st[strcspn(st, "\n")] = '\0'; // NEWLINE IS REPLACED WITH \0
    return ret_val;
}
// FUNCTON COUNTS WORDS, LETTERS, DIGITS AND PUNCTUATIONS IN A STRING
// PUNCTUATIONS ARE NOT COUNTED AS WORDS
void counter(char *st){
    int words = 0, newWord = 0,
        ucLetters = 0,
        lcLetters = 0, 
        punctuations = 0, 
        digits = 0;
    for (int i = 0; i < strlen(st) + 1; i++){ // + 1 SO THAT THE LAST WORD IS COUNTED
        if (isalnum(st[i])){                           // |
            if (newWord == 0) // BEGINING OF A WORD    // |
                newWord = 1;                           // | WHEN
            if (isupper(st[i])) // UC LETTERS COUNTER  // | CHARACTER
                ucLetters++;                           // | IS
            if (islower(st[i])) // LC LETTERS COUNTER  // | ALPHANUMERIC
                lcLetters++;                           // |
            if (isdigit(st[i])) // DIGITS COUNTER      // |
                digits++;                              // |
        }
        if (isalnum(st[i]) == 0){                      // |
            if (newWord == 1){ // END OF A WORD        // | WHEN
                words++;                               // | CHARACTER
                newWord = 0;                           // | IS
            }                                          // | NOT
            if (ispunct(st[i])) // PUNCTUATION COUNTER // | ALPHANUMERIC
                punctuations++;                        // |
        }
    }
    printf("Words:\t\t\t%d\n", words);
    printf("Uppercase letters:\t%d\n", ucLetters);
    printf("Lowercase letters:\t%d\n", lcLetters);
    printf("Punctuations:\t\t%d\n", punctuations);
    printf("Digits:\t\t\t%d\n", digits);
}