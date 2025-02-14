#include <stdint.h>
/*shift the bit 16 to the left to represent 2^16 efficiently
to calculate 2^16 using POW would require math.h, floating point conversion, function calls
and reconvert back. It is much slower than simply using bit operations*/
#define MAX_MEMORY (1 << 16)
uint16_t memory[MAX_MEMORY];

/*Using the LC-3, it has 10 total registers and each storing 16 bits*/
enum
{
    R_R0 =0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, //the program counter - an unsigned int that tells us where the program currently is
    R_COND, //condition flag register - tells info about the previous calculations
    R_COUNT
};

enum
{
    OP_BR = 0,
    OP_ADD, //addin
    OP_LD, //loading
    OP_ST, //storing
    OP_JSR, //jump register
    OP_AND, //bitwise and
    OP_LDR, //load register
    OP_STR, //store register
    OP_RTI, //
    OP_NOT, //bitwise not
    OP_LDI, //load indirectly
    OP_STI, //store indirectly
    OP_JMP, //jump
    OP_RES, //reserved
    OP_LEA, //load effective address
    OP_TRAP //execute trap 
};
uint16_t reg[R_COUNT];