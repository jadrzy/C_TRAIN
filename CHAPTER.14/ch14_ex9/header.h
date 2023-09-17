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
void show_num(struct seat *pts, char *ptr);
void show_list(struct seat *pts, char *ptr);
void show_alp(struct seat *pts, char *ptr);
void assign(struct seat *pts, char *ptr);
void delete(struct seat *pts, char *ptr);
void save(struct seat *pts, char *ptr);
void return_to_main(struct seat *pts, char *ptr);

// EXERCISE 9 EXPANSION
// menu function
int c_gets_flight(void);