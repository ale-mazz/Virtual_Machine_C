#define MEMSIZE (1<<16)

struct virtual_machine {
    unsigned char stack[MEMSIZE];
    int reg[32];
    /*
    unsigned int sp;
    unsigned int ip;
     */
};
typedef struct virtual_machine VM;

void print_input(int *input_array);

//int execute (FILE *fp, VM mem);
int input_to_array(char *input_name, int **input_array);