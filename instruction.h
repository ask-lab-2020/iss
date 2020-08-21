#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
#include <stdio.h>
#include <string.h>

// Resource configuration
#define WORD     (4)
#define REG_SIZE (32)
#define MEM_SIZE (1<<12)

// Bit mask
#define OP_MASK     0x0000007F
#define RD_MASK     0x00000F80
#define FUNCT3_MASK 0x00007000
#define RS1_MASK    0x000F8000
#define RS2_MASK    0x01F00000
#define FUNCT7_MASK 0xFE000000
#define IMME_MASK   0xFFF00000

// Bit distance
#define OP_DIST     0
#define RD_DIST     7
#define FUNCT3_DIST 12
#define RS1_DIST    15
#define RS2_DIST    20
#define FUNCT7_DIST 25
#define IMME_DIST   20 

// Loads
#define OP_LB       0x03
#define FUNCT3_LB   0x0

#define OP_LH       0x03
#define FUNCT3_LH   0x1

#define OP_LW       0x03
#define FUNCT3_LW   0x2

#define OP_LBU      0x03
#define FUNCT3_LBU  0x4

#define OP_LHU      0x03
#define FUNCT3_LHU  0x5

// Stores
#define OP_SB       0x23
#define FUNCT3_SB   0x0

#define OP_SH       0x23
#define FUNCT3_SH   0x1

#define OP_SW       0x23
#define FUNCT3_SW   0x2

// Shifts
#define OP_SLL      0x33
#define FUNCT3_SLL  0x1
#define FUNCT7_SLL  0x00

#define OP_SLLI     0x13
#define FUNCT3_SLLI 0x1
#define FUNCT7_SLLI 0x00

#define OP_SRL      0x33
#define FUNCT3_SRL  0x5
#define FUNCT7_SRL  0x00

#define OP_SRLI     0x13
#define FUNCT3_SRLI 0x5
#define FUNCT7_SRLI 0x00

#define OP_SRA      0x33
#define FUNCT3_SRA  0x5
#define FUNCT7_SRA  0x20

#define OP_SRAI     0x13
#define FUNCT3_SRAI 0x5
#define FUNCT7_SRAI 0x20

// Arithmetic
#define OP_ADD      0x33
#define FUNCT3_ADD  0x0
#define FUNCT7_ADD  0x00

#define OP_ADDI     0x13
#define FUNCT3_ADDI 0x0

#define OP_SUB      0x33
#define FUNCT3_SUB  0x0
#define FUNCT7_SUB  0x20

#define OP_LUI      0x37

#define OP_AUIPC    0x17

// Logical
#define OP_XOR      0x33
#define FUNCT3_XOR  0x4
#define FUNCT7_XOR  0x0

#define OP_XORI     0x13
#define FUNCT3_XORI 0x4

#define OP_OR       0x33
#define FUNCT3_OR   0x6
#define FUNCT7_OR   0x00

#define OP_ORI      0x13
#define FUNCT3_ORI  0x6

#define OP_AND      0x33
#define FUNCT3_AND  0x7
#define FUNCT7_AND  0x00

#define OP_ANDI     0x13
#define FUNCT3_ANDI 0x7

// Compare
#define OP_SLT      0x33
#define FUNCT3_SLT  0x2
#define FUNCT7_SLT  0x00

#define OP_SLTI     0x13
#define FUNCT3_SLTI 0x2

#define OP_SLTU     0x33
#define FUNCT3_SLTU 0x3
#define FUNCT7_SLTU 0x00

#define OP_SLTIU    0x13
#define FUNCT3_SLTIU 0x3

// Branches
#define OP_BEQ      0x63
#define FUNCT3_BEQ  0x0

#define OP_BNE      0x63
#define FUNCT3_BNE  0x1

#define OP_BLT      0x63
#define FUNCT3_BLT  0x4

#define OP_BGE      0x63
#define FUNCT3_BGE  0x5

#define OP_BLTU     0x63
#define FUNCT3_BLTU 0x6

#define OP_BGEU     0x63
#define FUNCT3_BGEU 0x7

// Jump & Link
#define OP_JAL      0x6F

#define OP_JALR     0x67

typedef struct{
  int  pc;
  int  ir;
  int  regs[REG_SIZE];
  char mem[MEM_SIZE];
}State;

const char* get_inst_type(const int ir);
int get_opcode(const int ir);
int get_rs1(const int ir);
int get_rs2(const int ir);
int get_rd(const int ir);
int get_funct3(const int ir);
int get_funct7(const int ir);
int get_imme_i(const int ir);
int get_imme_s(const int ir);
int get_imme_u(const int ir);
int get_imme_sb(const int ir);
int get_imme_uj(const int ir);

int execute_inst(State *state);
void print_state(const int prev_pc, const State *state, int effective_addr);
void fprint_state(FILE *stream, const int prev_pc, const State *state, int effective_addr);

#endif
