#include <stdio.h>
struct names {
    char fname[20];
    char mname[20];
    char lname[20];
};
struct data {
    char social_security[12];
    struct names data; 
};
void pritningA(struct data arr[]);
void pritningB(char fname[20], char mname[20], char lname[20], char security[12]);
int main(void){
    struct data array[5] = {
        {"595-15-9100", "Eryn", "Cherish", "Perry"},
        {"523-69-2257", "Osian", "Jaiden", "Kirk"},
        {"146-10-6161", "Keenan", "Campbell", "Flores"},
        {"683-22-5821", "Margie", "Makayla", "Riddle"},
        {"400-55-6569", "Asa", "Mariyah", "Blaese"}
    };
    pritningA(array);
    printf("\n");
    for (int i = 0; i < 5; i++)
        pritningB(array[i].data.fname, array[i].data.mname,
        array[i].data.lname, array[i].social_security);
    return 0;
}
void pritningA(struct data arr[]){
    for (int i = 0; i < 5; i++)
        printf("%s, %s %c. --- %s\n", arr[i].data.lname, arr[i].data.fname,
        arr[i].data.mname[0], arr[i].social_security);
        
}
void pritningB(char fname[20], char mname[20], char lname[20], char security[12]){
        printf("%s, %s %c. --- %s\n", lname, fname, mname[0], security);
}