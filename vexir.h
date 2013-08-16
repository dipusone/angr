#ifndef __VEXIR_H
#define __VEXIR_H

#include "libvex.h"

// Some info required for translation
extern VexArchInfo         vai;
extern VexGuestExtents     vge;
extern VexTranslateArgs    vta;
extern VexTranslateResult  vtr;
extern VexAbiInfo	   vbi;
extern VexControl	   vc;

typedef struct
{
	IRSB **irsbs;
	unsigned int num_irsbs;
} vexed_block;

//
// Initializes VEX. This function must be called before vex_insn
// can be used. 
//
void vex_init();

//
// Translates assembly instructions and blocks into VEX
IRSB *vex_instruction(VexArch guest, unsigned char *insn_start, unsigned int insn_addr, int max_insns);
IRSB *vex_block_bytes(VexArch guest, unsigned char *instructions, unsigned int block_addr, unsigned int num_bytes);
IRSB *vex_block_inst(VexArch guest, unsigned char *instructions, unsigned int block_addr, unsigned int num_inst);
vexed_block *vex_bytes(VexArch guest, unsigned char *instructions, unsigned int block_addr, unsigned int num_bytes);

#endif
