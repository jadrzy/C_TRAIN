#include <stdio.h>
#define CSIZE 4             // size of array of structures
#define GSIZE 3             // size of grade array 

struct name {
    char fname[20];
    char sname[20];
};
struct student {
    struct name names;
    float grade[GSIZE];
    float average;
};

void get_grades(struct student *pts);                       // functions do not return arguments
void calc_av(struct student *pts);                          // instead they work with pointers
void print_struct(struct student *pts);

int main(void){
    struct student students[CSIZE] = {
        {"Jan", "Wojciech"},
        {"Hubert", "Marek"},
        {"Jurek", "Marcin"},
        {"Grzegorz", "Sebastian"}
    };
    get_grades(&students[0]);
    calc_av(&students[0]);
    print_struct(&students[0]);
    return 0;
}

void get_grades(struct student *pts){
    for (int i = 0; i < CSIZE; i++, pts++){
        printf("Enter %s %s grades:\n", pts->names.fname, pts->names.sname);
        for (int j = 0; j < GSIZE; j++){
            while (scanf("%f", &pts->grade[j]) != 1)
                while (getchar() != '\n');                  // cleans buffer in case of wrong input
        }
        while (getchar() != '\n');                          // cleans buffer after reading input
    }
}
void calc_av(struct student *pts){
    for (int i = 0; i < CSIZE; i++, pts++){    
        float result = 0;
        for (int j = 0; j < GSIZE; j++){                    // sum of all grades
            result += pts->grade[j]; 
        }
        pts->average = result / GSIZE;                      // saving average into structure
    }
}
void print_struct(struct student *pts){
    for (int i = 0; i < CSIZE; i++, pts++){    
        printf("Names:      %s %s\n", 
        pts->names.fname, pts->names.sname);
        printf("Grades:     ");
        for (int j = 0; j < GSIZE; j++){                   
            printf("%1.1f ", pts->grade[j]);
        }   
        printf("\nAverage:    %1.1f\n", pts->average);                  
    }
}