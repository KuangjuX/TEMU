#include "helper.h"
#include "all-instr.h"

typedef void (*op_fun)(uint32_t);
static make_helper(_2byte_esc);

Operands ops_decoded;
uint32_t instr;
	

/* TODO: Add more instructions!!! */

op_fun opcode_table [64] = {
/* 0x00 */	_2byte_esc, inv, inv, inv,
/* 0x04 */	inv, bne, inv, inv,
/* 0x08 */	addi, inv, inv, inv,
/* 0x0c */	inv, ori, inv, lui,
/* 0x10 */	inv, inv, temu_trap, inv,
/* 0x14 */	inv, inv, inv, inv,
/* 0x18 */	inv, inv, inv, inv,
/* 0x1c */	inv, inv, inv, inv,
/* 0x20 */	inv, inv, inv, inv,
/* 0x24 */	inv, inv, inv, inv,
/* 0x28 */	inv, inv, inv, inv,
/* 0x2c */	inv, inv, inv, inv,
/* 0x30 */	inv, inv, inv, inv,
/* 0x34 */	inv, inv, inv, inv,
/* 0x38 */	inv, inv, inv, inv,
/* 0x3c */	inv, inv, inv, inv
};

op_fun _2byte_opcode_table [64] = {
/* 0x00 */	bad_temu_trap, inv, inv, inv, 
/* 0x04 */	inv, inv, inv, inv, 
/* 0x08 */	inv, inv, inv, inv, 
/* 0x0c */	inv, inv, inv, inv, 
/* 0x10 */	inv, inv, inv, inv, 
/* 0x14 */	inv, inv, inv, inv, 
/* 0x18 */	inv, inv, inv, inv, 
/* 0x1c */	inv, inv, inv, inv, 
/* 0x20 */	inv, inv, inv, inv, 
/* 0x24 */	and, inv, inv, inv,
/* 0x28 */	inv, inv, inv, inv, 
/* 0x2c */	inv, inv, inv, inv, 
/* 0x30 */	inv, inv, inv, inv, 
/* 0x34 */	inv, inv, inv, inv,
/* 0x38 */	inv, inv, inv, inv, 
/* 0x3c */	inv, inv, inv, inv
};

make_helper(exec) {
	// 此时需要去判断地址错例外
	if(pc & 0x3) {
		// 最后两位应为0
		// 触发地址错例外
		cpu.cp0.cause.ExcCode = AdEL;
		if(cpu.cp0.status.EXL == 0) {
			// 当cp0.status.EXL为0时，更新cp0.EPC
			// EXL为0时表示 Normal level
			cpu.cp0.EPC = pc;
			pc = TRAP_ADDR;
			cpu.cp0.status.EXL = 1;
		}
		return;
	}
	instr = instr_fetch(pc, 4);
	ops_decoded.opcode = instr >> 26;
	fprintf(stdout, "opcode: 0x%02x\n", ops_decoded.opcode);
	opcode_table[ ops_decoded.opcode ](pc);
}

static make_helper(_2byte_esc) {
	ops_decoded.func = instr & FUNC_MASK;
	// fprintf(stdout, "func: 0x%02x\n", ops_decoded.func);
	_2byte_opcode_table[ops_decoded.func](pc); 
}
