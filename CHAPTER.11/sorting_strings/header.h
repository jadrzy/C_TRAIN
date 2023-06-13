#define LENGHT 40
#define LIMIT 2
#define ASTERISKS "*****************************************"
#define PLHOLDER "Press enter..."

//action functions
char menu(int *n);
char input_validation(void);//FUNCTION IS PART OF menu()
void addstring(char (*array)[LENGHT], int *n);
void display(char (*array)[LENGHT]);
void deletestring(char (*array)[LENGHT], int *n, char s[4]);//3'RD ARGUMENT ALLOWS TO SWITCH BETWEEN TWO MODES (CLEAR ALL AND CLEAR ONE)
int getrow(void);//FUNCTION IS PART OF deletestring() CLEAR ONE MODE

//info functions
void intro(void);
void information(void);