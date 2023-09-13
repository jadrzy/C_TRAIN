#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void){
    struct book library[MAXBKS]; 
    struct book placeholder;
    char decision[7];
    int count = 0;
    int index;
    FILE * pbooks;
    int size = sizeof (struct book);
    if ((pbooks = fopen("book.dat", "rb")) == NULL){
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&placeholder, size, 1, pbooks) == 1){
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", placeholder.title,
        placeholder.author, placeholder.value);
        printf("Enter empty line to accept else enter \"edit\" or \"delete\":\n");
        while (s_gets(decision, 7) != NULL){
            if (strcmp(decision, "delete") == 0){
                printf("Book deleted\n");
                break;
            }
            else if (strcmp(decision, "edit") == 0){
                puts("Enter the next title.");
                puts("Press [enter] at the start of a line to stop.");
                s_gets(placeholder.title, MAXTITL);
                puts("Now enter the author.");
                s_gets(placeholder.author, MAXAUTL);
                puts("Now enter the value.");
                scanf("%f", &placeholder.value);
                while (getchar() != '\n')
                    continue;
                library[count] = placeholder;
                count++;
                break;
            }
            else if (decision[0] != '\n'){
                library[count] = placeholder;
                count++;
                break;
            }
            else{
                printf("Error. Wrong input.\n");
                printf("Enter empty line to accept else enter \"edit\" or \"delete\":\n");
            }
        }
    }
    if (count == MAXBKS){
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    fclose(pbooks);
    if ((pbooks = fopen("book.dat", "wb")) == NULL){
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks);
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
    && library[count].title[0] != '\0'){
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    if (count > 0){
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
            library[index].author, library[index].value);
        rewind(pbooks);
        fwrite(&library, size, count, pbooks);
    }
    else
    puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }   
    return ret_val;
}