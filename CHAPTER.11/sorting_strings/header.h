#define LENGHT 40
#define LIMIT 20
#define ASTERISKS "*****************************************"
#define PLHOLDER "Press enter..."

//action functions
char menu(int *n);
char input_validation(void);
void addstring(char (*array)[LENGHT], int *n);
void display(char (*array)[LENGHT]);

//info functions
void intro(void);
void information(void);