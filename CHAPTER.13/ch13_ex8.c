// program takes character and filenames as arguments
// program counts inserted characters in each file and prints results 
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h> // for strchr()
#define LENGHT 256
int count_char(char *file_name, char ch);
int main(int argc, char ** argv){
    if (argc < 2){ // command-line validation
        fprintf(stderr, "Usage %s <character> <optional.filename1> <optional.filename2>...\n", argv[0]); 
        exit(EXIT_FAILURE);
    }
    char ch = *argv[1]; // character from input    
    if (argc == 2){ // if no filenames were given program takes standard input 
        int count = 0;
        char string[LENGHT];
        char *ptr;
        printf("No filenames were given.\n");
        printf("Please enter string:\n");
        fgets(string ,LENGHT, stdin);
        if ((ptr = strchr(string,'\n')) != NULL)
            *ptr = '\0';
            for (int i = 0; string[i] != '\0' && i < LENGHT; i++)
                if (string[i] == ch)
                    count++;
        printf("In inserted string character %c is present %d times\n", ch, count);  
    }
    else{ // program proceeds to open files and count characters
        for(int i = 2; i < argc; i++)
            count_char(argv[i], ch);
    }
    return 0;
}

int count_char(char *file_name, char ch){
    int count = 0;
    FILE *pf;
    if ((pf = fopen(file_name, "r")) == NULL)
        fprintf(stderr,"In file %s \t\tError opening file\n", file_name);    
    else{
        char buffer[LENGHT];
        while (fread(buffer, sizeof(char), LENGHT, pf) != 0)
            for (int i = 0; buffer[i] != '\0' && i < LENGHT; i++)
                if (buffer[i] == ch)
                    count++;
        printf("In file %s \t\tcharacter %c is present %d times\n",
        file_name, ch, count);  
        fclose(pf);
        return count;
    }
}
