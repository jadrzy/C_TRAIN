#include <stdbool.h>    // for boolean type
#define MAXSEAT 12
#define MAXNAME 15
// STRUCTURES
struct id {
    char fname[MAXNAME];
    char lname[MAXNAME];
};
struct seat{
    int number;
    bool empty;
    struct id person;
};
// PROTOTYPES
// menu function
int c_gets(void);       
//functions from the menu
void show_num(struct seat *pts);
void show_list(struct seat *pts);
void show_alp(struct seat *pts);
void assign(struct seat *pts);
void delete(struct seat *pts);
void save_quit(struct seat *pts);
