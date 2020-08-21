#include <stdio.h>
#include <stdlib.h>
#include "instruction.h"

int match_breakpoint(int pc, int breakpoint[], int breakpoint_num);

int main(int argc, char **argv) {
  FILE *file;
  char com[2];
  int file_len, effective_addr, prev_pc;
  int breakpoint[10], breakpoint_num=0, bp;

  if (argc < 3) {
    printf("Invalid argument. The minimum nubmer of argument is 2.\n");
    return 0;
  }

  // State initialize
  State *state = (State*)malloc(sizeof(State));
  state->pc = 0;
  state->regs[2] = 0x000007FC;
  state->regs[3] = 0x00000000;

  // File open and get instructions
  file = fopen(argv[1], "rb");
  fseek(file, 0L, SEEK_END);
  file_len = ftell(file);
  rewind(file);
  for (int i=0; i<file_len; i++)
    state->mem[(i/4)*4 + 3 - (i%4)] = fgetc(file);
  fclose(file);

    
  printf("*******************************************\n");
  printf("           RV32I ISS Project               \n");
  printf("*******************************************\n");

  print_state(prev_pc, state, effective_addr);

  while (1) {
    if (state->ir==0x00008067 && state->regs[1]==0x0c)
      break;
    printf("Command: ");
    scanf("%s",com);
    if (com[0] == 's') {
      prev_pc = state->pc;
      effective_addr = execute_inst(state);
      print_state(prev_pc, state, effective_addr);
    } else if (com[0] == 'r') {
      while (1) {
        if (state->ir==0x00008067 && state->regs[1]==0x0c)
          break;
        prev_pc = state->pc;
        effective_addr = execute_inst(state);
      }
    } else if (com[0] == 'b') {
      scanf("%x",&bp);
      if (breakpoint_num == 10) {
        printf("Cannot create more than 10 breakpoints.\n");
      }
      else if (bp % WORD != 0) {
        printf("Breakpoint must be aligned.\n");
      }
      else {
        printf("Set breakpoint to %X.\n", bp);
        breakpoint[breakpoint_num++] = bp;
        printf("----- Created breakpoints -----\n");
        for (int i=0; i<breakpoint_num; i++)
          printf("BP[%d]: %X\n", i, breakpoint[i]);
        printf("-------------------------------\n");
      }
    } else if (com[0] == 'j') {
      do {
        if (state->ir==0x00008067 && state->regs[1]==0x0c)
          break;
        prev_pc = state->pc;
        effective_addr = execute_inst(state);
      } while (!match_breakpoint(state->pc, breakpoint, breakpoint_num));
      if (state->ir==0x00008067 && state->regs[1]==0x0c)
        break;
      prev_pc = state->pc;
      effective_addr = execute_inst(state);
      print_state(prev_pc, state, effective_addr);
    } else {
      printf("Invalid command.\n");
    }
  }

  // Print last state
  print_state(prev_pc, state, effective_addr);
  // Dump output file
  file = fopen(argv[2], "w");
  fprint_state(file, prev_pc, state, effective_addr);

  fprintf(file,"       ");
  for (int i=0; i<16; i++)
    fprintf(file,"%2d ",i);
  fprintf(file,"\n");
  fprintf(file,"------------------------------------------------------\n");
  for (int i=0; i<MEM_SIZE; i+=16) {
    fprintf(file,"0x%03X: ",i);
    for (int j=0; j<16; j++)
      fprintf(file,"%02hhX ",state->mem[i+ ((j/4)*4 + 3 - (j%4))]);  // 
    fprintf(file,"\n");
  }
  fclose(file);
  free(state);
  return 0;
}

int match_breakpoint(int pc, int breakpoint[], int breakpoint_num) {
  for (int i=0; i<breakpoint_num; i++)
    if (breakpoint[i] == pc)
      return 1;
  return 0;
}
