#include "instruction.h"
#include <stdio.h>

const char* get_inst_type(const int ir) {
  // Loads
  if (get_opcode(ir)==OP_LB && get_funct3(ir)==FUNCT3_LB) 
    return "LB";
  else if (get_opcode(ir)==OP_LH && get_funct3(ir)==FUNCT3_LH) 
    return "LH";
  else if (get_opcode(ir)==OP_LW && get_funct3(ir)==FUNCT3_LW) 
    return "LW";
  else if (get_opcode(ir)==OP_LBU && get_funct3(ir)==FUNCT3_LBU) 
    return "LBU";
  else if (get_opcode(ir)==OP_LHU && get_funct3(ir)==FUNCT3_LHU) 
    return "LHU";
  // Stores
  else if (get_opcode(ir)==OP_SB && get_funct3(ir)==FUNCT3_SB) 
    return "SB";
  else if (get_opcode(ir)==OP_SH && get_funct3(ir)==FUNCT3_SH) 
    return "SH";
  else if (get_opcode(ir)==OP_SW && get_funct3(ir)==FUNCT3_SW) 
    return "SW";
  // Shifts
  else if (get_opcode(ir)==OP_SLL && get_funct3(ir)==FUNCT3_SLL &&
      get_funct7(ir)==FUNCT7_SLL) 
    return "SLL";
  else if (get_opcode(ir)==OP_SLLI && get_funct3(ir)==FUNCT3_SLLI &&
      get_funct7(ir)==FUNCT7_SLLI) 
    return "SLLI";
  else if (get_opcode(ir)==OP_SRL && get_funct3(ir)==FUNCT3_SRL &&
      get_funct7(ir)==FUNCT7_SRL) 
    return "SRL";
  else if (get_opcode(ir)==OP_SRLI && get_funct3(ir)==FUNCT3_SRLI &&
      get_funct7(ir)==FUNCT7_SRLI) 
    return "SRLI";
  else if (get_opcode(ir)==OP_SRA && get_funct3(ir)==FUNCT3_SRA &&
      get_funct7(ir)==FUNCT7_SRA) 
    return "SRA";
  else if (get_opcode(ir)==OP_SRAI && get_funct3(ir)==FUNCT3_SRAI &&
      get_funct7(ir)==FUNCT7_SRAI) 
    return "SRAI";
  // Arithmetic
  else if (get_opcode(ir)==OP_ADD && get_funct3(ir)==FUNCT3_ADD &&
      get_funct7(ir)==FUNCT7_ADD) 
    return "ADD";
  else if (get_opcode(ir)==OP_ADDI && get_funct3(ir)==FUNCT3_ADDI)
    return "ADDI";
  else if (get_opcode(ir)==OP_SUB && get_funct3(ir)==FUNCT3_SUB &&
      get_funct7(ir)==FUNCT7_SUB) 
    return "SUB";
  else if (get_opcode(ir)==OP_LUI)
    return "LUI";
  else if (get_opcode(ir)==OP_AUIPC)
    return "AUIPC";
  // Logical
  else if (get_opcode(ir)==OP_XOR && get_funct3(ir)==FUNCT3_XOR &&
      get_funct7(ir)==FUNCT7_XOR) 
    return "XOR";
  else if (get_opcode(ir)==OP_XORI && get_funct3(ir)==FUNCT3_XORI)
    return "XORI";
  else if (get_opcode(ir)==OP_OR && get_funct3(ir)==FUNCT3_OR &&
      get_funct7(ir)==FUNCT7_OR) 
    return "OR";
  else if (get_opcode(ir)==OP_ORI && get_funct3(ir)==FUNCT3_ORI)
    return "ORI";
  else if (get_opcode(ir)==OP_AND && get_funct3(ir)==FUNCT3_AND &&
      get_funct7(ir)==FUNCT7_AND) 
    return "AND";
  else if (get_opcode(ir)==OP_ANDI && get_funct3(ir)==FUNCT3_ANDI)
    return "ANDI";
  // Compare
  else if (get_opcode(ir)==OP_SLT && get_funct3(ir)==FUNCT3_SLT &&
      get_funct7(ir)==FUNCT7_SLT) 
    return "SLT";
  else if (get_opcode(ir)==OP_SLTI && get_funct3(ir)==FUNCT3_SLTI)
    return "SLTI";
  else if (get_opcode(ir)==OP_SLTU && get_funct3(ir)==FUNCT3_SLTU &&
      get_funct7(ir)==FUNCT7_SLTU) 
    return "SLTU";
  else if (get_opcode(ir)==OP_SLTIU && get_funct3(ir)==FUNCT3_SLTIU)
    return "SLTIU";
  // Branches
  else if (get_opcode(ir)==OP_BEQ && get_funct3(ir)==FUNCT3_BEQ)
    return "BEQ";
  else if (get_opcode(ir)==OP_BNE && get_funct3(ir)==FUNCT3_BNE)
    return "BNE";
  else if (get_opcode(ir)==OP_BLT && get_funct3(ir)==FUNCT3_BLT)
    return "BLT";
  else if (get_opcode(ir)==OP_BGE && get_funct3(ir)==FUNCT3_BGE)
    return "BGE";
  else if (get_opcode(ir)==OP_BLTU && get_funct3(ir)==FUNCT3_BLTU)
    return "BLTU";
  else if (get_opcode(ir)==OP_BGEU && get_funct3(ir)==FUNCT3_BGEU)
    return "BGEU";
  // Jump & Link
  else if (get_opcode(ir)==OP_JAL)
    return "JAL";
  else if (get_opcode(ir)==OP_JALR)
    return "JALR";
  else
    return "NOP";
}

int get_opcode(const int ir) {
  return ((unsigned int)ir & OP_MASK) >> OP_DIST;
}

int get_rs1(const int ir) {
  return ((unsigned int)ir & RS1_MASK) >> RS1_DIST;
}

int get_rs2(const int ir) {
  return ((unsigned int)ir & RS2_MASK) >> RS2_DIST;
}

int get_rd(const int ir) {
  return ((unsigned int)ir & RD_MASK) >> RD_DIST;
}

int get_funct3(const int ir) {
  return ((unsigned int)ir & FUNCT3_MASK) >> FUNCT3_DIST;
}

int get_funct7(const int ir) {
  return ((unsigned int)ir & FUNCT7_MASK) >> FUNCT7_DIST;
}

int get_imme_i(const int ir) {
  int result = ((unsigned int)ir & IMME_MASK) >> IMME_DIST;
  if (result & 0x00000800)
    result |= 0xFFFFF000;
  return result;
}

int get_imme_s(const int ir) {
  int funct7 = get_funct7(ir);
  int rd = get_rd(ir);
  int result = (funct7 << 5) + rd;
  if (result & 0x00000800)
    result |= 0xFFFFF000;
  return result;
}

int get_imme_u(const int ir) {
  // WARNING: This function doesn't use shift!!!
  return ir & 0xFFFFF000;
}

int get_imme_sb(const int ir) {
  int funct7 = get_funct7(ir);
  int rd = get_rd(ir);
  int result = 0;

  result |= ((int)((ir & 0x80000000)) >> 19);
  result |= ((ir & 0x00000080) << 4);
  result |= ((ir & 0x7E000000) >> 20);
  result |= ((ir & 0x00000F00) >> 7);
  return result;
}

int get_imme_uj(const int ir) {
  int result = 0;
  result |= (((int)(ir & 0x80000000)) >> 12);
  result |= ((ir & 0x000FF000));
  result |= ((ir & 0x00100000) >> 9);
  result |= ((ir & 0x7E000000) >> 20);
  result |= ((ir & 0x01E00000) >> 20);
  return result;
}

int execute_inst(State *state) {
  const char *inst_type;
  int rs1, rs2, rd, imme, value;
  int effective_addr = -1;

  state->ir = 
    ((unsigned char)state->mem[state->pc+3] << 0) | 
    ((unsigned char)state->mem[state->pc+2] << 8) |
    ((unsigned char)state->mem[state->pc+1] << 16 ) |
    ((unsigned char)state->mem[state->pc+0] << 24 );

  inst_type = get_inst_type(state->ir);
  rs1 = get_rs1(state->ir);
  rs2 = get_rs2(state->ir);
  rd  = get_rd(state->ir);

  // In most case, pc is not taken.
  state->pc += 4;

  // Change state
  // Loads
  if (!strcmp(inst_type,"LW")) {
  }
  //Stores
  else if (!strcmp(inst_type,"SB")) {
  }
  else if (!strcmp(inst_type,"SW")) {
  }
  // Shifts
  else if (!strcmp(inst_type,"SLLI")) {
  }
  else if (!strcmp(inst_type,"SRLI")) {
  }
  else if (!strcmp(inst_type,"SRAI")) {
  }
  // Arithmetic
  else if (!strcmp(inst_type,"ADD")) {
    state->regs[rd] = state->regs[rs1] + state->regs[rs2];
  }
  else if (!strcmp(inst_type,"ADDI")) {
    state->regs[rd] = state->regs[rs1] + get_imme_i(state->ir);
  }
  else if (!strcmp(inst_type,"SUB")) {
  }
  else if (!strcmp(inst_type,"LUI")) {
  }
  // Logical
  else if (!strcmp(inst_type,"XOR")) {
  }
  else if (!strcmp(inst_type,"OR")) {
  }
  else if (!strcmp(inst_type,"AND")) {
  }
  // Compare
  else if (!strcmp(inst_type,"SLT")) { // Not in testcase
  }
  // Branches
  else if (!strcmp(inst_type,"BEQ")) {
  }
  else if (!strcmp(inst_type,"BNE")) {
  }
  else if (!strcmp(inst_type,"BLT")) {
  }
  else if (!strcmp(inst_type,"BLTU")) {
  }
  // Jump & Link
  else if (!strcmp(inst_type,"JAL")) {
  }
  else if (!strcmp(inst_type,"JALR")) {
    imme = get_imme_i(state->ir);
    if (rd != 0) {
      // Register x0 can be used as the destination if the result is not required.
      state->regs[rd] = state->pc;
    }
    state->pc = ((state->regs[rs1] + imme) & 0xFFFFFFFE);
  }
  return effective_addr;
}

void print_state(const int prev_pc, const State *state, int effective_addr) {
  printf("---------------------------------------\n");
  printf("PC: 0x%08X\n",prev_pc);
  printf("IR: 0x%08X (Instruction: %s)\n\n",state->ir, get_inst_type(state->ir));
  printf("GPR:\n");
  for (int i=0; i<REG_SIZE; i+=4) {
    for (int j=0; j<4; j++)
      printf("[%02d] 0x%08x  ",i+j,state->regs[i+j]);
    printf("\n");
  }
  if (effective_addr != -1) {
    printf("MEM:\n");
    int base = effective_addr / 16 * 16;
    for (int i=-1; i<2; i++) {
      printf("0x%03X: ",base+16*i);
      for (int j=0; j<16; j++) {
        printf("%02hhX ", state->mem[base+16*i+j]);
      }
      printf("\n");
    }
  }
  printf("---------------------------------------\n");
}



void fprint_state(FILE *file, const int prev_pc, const State *state, int effective_addr) {
  fprintf(file,"------------------------------------------------------\n");
  fprintf(file, "PC: 0x%08X\n",prev_pc);
  fprintf(file, "IR: 0x%08X (Next Instruction: %s)\n\n",state->ir, get_inst_type(state->ir));
  fprintf(file, "GPR:\n");
  for (int i=0; i<REG_SIZE; i+=4) {
    for (int j=0; j<4; j++)
      fprintf(file, "[%02d] 0x%08X  ",i+j,state->regs[i+j]);
    fprintf(file, "\n");
  }
  if (effective_addr != -1) {
    fprintf(file, "MEM:\n");
    int base = effective_addr / 16 * 16;
    for (int i=-1; i<2; i++) {
      fprintf(file, "0x%03X: ",base+16*i);
      for (int j=0; j<16; j++) {
        fprintf(file, "%02hhX ", state->mem[base+16*i+j]);
      }
      fprintf(file, "\n");
    }
  }
  fprintf(file,"------------------------------------------------------\n");
}

