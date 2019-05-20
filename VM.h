#define MEMSIZE (1<<16)
struct virtual_machine {
    unsigned char stack[MEMSIZE];
    int reg[32];
    unsigned int sp=0;
    unsigned int ip=0;
}
typedef struct virtual_machine VM;
void print_input (FILE *fp);
int execute (FILE *fp, VM mem);