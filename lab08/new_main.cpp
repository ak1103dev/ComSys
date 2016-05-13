#include <systemc.h>

#include "setting.h"
#include "check.h"
#include "mips_reg.h"
#include "alu.h"

int sc_main(int argc, char* argv[]) {

    sc_signal<sc_uint<N_BIT_REG> > write_data, src1_data, src2_data;//din, dout;
    sc_signal<bool> reset, ready;
    sc_signal<bool>  enable, rw, clr;
    sc_signal<sc_uint<BIT_ADDR> > dst_addr, src1_addr, src2_addr;//addr;
	sc_signal<sc_uint<4> > opcode;
	sc_signal<sc_uint<N_BIT_REG> > result;
	sc_signal<bool> zflag, oflag;

    sc_clock clk("clk",10,SC_NS,0.5);

    check CHECK("checker");
    CHECK.clk(clk);
    CHECK.enable(enable);
    CHECK.rw(rw);
    CHECK.clr(clr);
    CHECK.src1_addr(src1_addr);
    CHECK.src2_addr(src2_addr);
    CHECK.dst_addr(dst_addr);
    CHECK.write_data(write_data);
    CHECK.src1_data(src1_data);
    CHECK.src2_data(src2_data);

    mips_reg MIPSREG("mips");
    MIPSREG.clk(clk);
    MIPSREG.enable(enable);
    MIPSREG.rw(rw);
    MIPSREG.clr(clr);
    MIPSREG.src1_addr(src1_addr);
    MIPSREG.src2_addr(src2_addr);
    MIPSREG.dst_addr(dst_addr);
    MIPSREG.write_data(write_data);
    MIPSREG.src1_data(src1_data);
    MIPSREG.src2_data(src2_data);
    MIPSREG.reset(reset);

	alu ALU("alu");
	ALU.ain(src1_data);
	ALU.bin(src2_data);
	ALU.opcode(opcode);
	ALU.result(result);
	ALU.zflag(zflag);
	ALU.oflag(oflag);

    sc_start(SC_ZERO_TIME);

	clr = 0;
    sc_start(100 , SC_NS);
	clr = 1;
    sc_start(100 , SC_NS);

	// write 0 at $8 #i
    enable =0, rw=1, dst_addr = 8, write_data = 0;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);

	// write 0 at $9 #sum
    enable =0, rw=1, dst_addr = 9, write_data = 0;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);

	// write 100 at $10 #N
    enable =0, rw=1, dst_addr = 10, write_data = 100;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);

	// write 1 at $11
    enable =0, rw=1, dst_addr = 11, write_data = 1;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);

	//read $8, $10
    enable=0, rw=0, src1_addr = 8, src2_addr = 10;
	opcode = 1;
    sc_start(100 , SC_NS);
	enable=1;
    sc_start(100 , SC_NS);

	// $8 < $10
	while(!zflag.read()) {
		//read $9, $8
		enable=0, rw=0, src1_addr = 9, src2_addr = 8;
		opcode = 0;
		sc_start(100 , SC_NS);
		enable=1;
		sc_start(100 , SC_NS);

		// write result at $9
		enable =0, rw=1, dst_addr = 9, write_data = result.read();
		sc_start(100 , SC_NS);
		enable =1;
		sc_start(100 , SC_NS);

		//read $8, $11
		enable =0, rw=0, src1_addr = 8, src2_addr = 11;
		opcode = 0;
		sc_start(100 , SC_NS);
		enable=1;
		sc_start(100 , SC_NS);

		// write result at $8
		enable =0, rw=1, dst_addr = 8, write_data = result.read();
		sc_start(100 , SC_NS);
		enable =1;
		sc_start(100 , SC_NS);

		//read $8, $10
		enable=0, rw=0, src1_addr = 8, src2_addr = 10;
		opcode = 1;
		sc_start(100 , SC_NS);
		enable=1;
		sc_start(100 , SC_NS);
	}
	//read $8, $9
	enable=0, rw=0, src1_addr = 8, src2_addr = 9;
	opcode = 0;
	sc_start(100 , SC_NS);
	enable=1;
	sc_start(100 , SC_NS);

/*
    enable =0, rw=1, dst_addr = 1, write_data = 27, clr=1;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);
    rw=0, src1_addr = 1, src2_addr = 2, write_data = 27;
    sc_start(100 , SC_NS);

    enable =0, rw=1;
    sc_start(100 , SC_NS);
    enable=1 , dst_addr = 2, write_data = 25;
    sc_start(100 , SC_NS);
    rw=0; src1_addr = 1, src2_addr = 2;
    sc_start(100 , SC_NS);

    enable =0, rw=1;
    sc_start(100 , SC_NS);
    enable=1 , addr = 5, din = 3;
    sc_start(100 , SC_NS);
    rw=0;
    sc_start(100 , SC_NS);
	*/

    return 0;                           // Return OK, no errors.
}                                       // no ;
