#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void){
    struct book library[MAXBKS];
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
    && library[count].title[0] != '\0'){
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0){
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        // sorting by title
        int *ptr;
        int index;
        ptr = (int*) malloc(count * sizeof(int));                           // to track indices
        for (int i = 0; i < count; i++, ptr++)                              // assigning numbers of indices
            *ptr = i;
        printf("\nHere is the list sorted by titles:\n");
        for (int j = 0; j < count; j++){
            index = 0;
            while (*(ptr + index) == -1)
                index++;
            for (int i = 0; i < count - 1; i++){                            // more than 1 book is needed to sort
                if (strcmp(library[index].title, library[i + 1].title) > 0 && *(ptr + i + 1) != -1)
                    index = i + 1;                                          // save index when compared string has bigger value 
            }    
            *(ptr + index) = -1;                                            // change status of used index
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        }
        // sorting by value
        for (int i = 0; i < count; i++, ptr++)                              
            *ptr = i;
        printf("\nHere is the list sorted by prices:\n");
        for (int j = 0; j < count; j++){
            index = 0;
            while (*(ptr + index) == -1)
                index++;
            for (int i = 0; i < count - 1; i++){                            
                if (library[index].value > library[i + 1].value && *(ptr + i + 1) != -1)    // strings replaced with ints
                    index = i + 1;                                          
            }    
            *(ptr + index) = -1;                                            
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
        }
        free(ptr);
    }
    else
        printf("No books? Too bad.\n");
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