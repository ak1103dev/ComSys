#include "reg32.h"
#include "mux_dmux.h"
#define L 32

SC_MODULE(register_file) {
	sc_in<bool>  clk;
	sc_in<sc_uint<L> > din;
	sc_out<sc_uint<L> > dout;
    sc_in<bool> rw;
    sc_in<bool> enable;
    sc_in<bool> clear;
	sc_in<sc_uint<5> > addr;

	sc_signal<sc_uint<L> > dd[32], qq[32];

	reg32 R1;
	reg32 R2;
	reg32 R3;
	reg32 R4;
	reg32 R5;
	reg32 R6;
	reg32 R7;
	reg32 R8;

	reg32 R9;
	reg32 R10;
	reg32 R11;
	reg32 R12;
	reg32 R13;
	reg32 R14;
	reg32 R15;
	reg32 R16;

	reg32 R17;
	reg32 R18;
	reg32 R19;
	reg32 R20;
	reg32 R21;
	reg32 R22;
	reg32 R23;
	reg32 R24;

	reg32 R25;
	reg32 R26;
	reg32 R27;
	reg32 R28;
	reg32 R29;
	reg32 R30;
	reg32 R31;
	reg32 R32;

	mux1to32 mux;
	dmux32to1 dmux;

	SC_CTOR(register_file) : R1("1"), R2("2"), R3("3"), R4("4"), R5("5"), R6("6"), R7("7"), R8("8"), R9("9"), R10("10"), R11("11"),
		R12("12"),
		R13("13"),
		R14("14"),
		R15("15"),
		R16("16"),
		R17("17"),
		R18("18"),
		R19("19"),
	   	R20("20"),
		R21("21"),
		R22("22"),
		R23("23"),
		R24("24"),
		R25("25"),
		R26("26"),
		R27("27"),
		R28("28"),
		R29("29"),
	   	R30("30"),
	   	R31("31"),
	   	R32("32"),
		mux("mux"), dmux("dmux") {

			mux.input(din);
			mux.select(addr);
			for(int z = 0; z < 32; z++) {
				mux.out[z](dd[z]);
			}

			for(int z = 0; z < 32; z++) {
				dmux.in[z](qq[z]);
			}
			dmux.select(addr);
			dmux.output(dout);

		R1.clk(clk);
		R1.din(dd[0]);
		R1.dout(qq[0]);
		R1.rw(rw);
		R1.enable(enable);
		R1.clear(clear);

		R2.clk(clk);
		R2.din(dd[1]);
		R2.dout(qq[1]);
		R2.rw(rw);
		R2.enable(enable);
		R2.clear(clear);

		R3.clk(clk);
		R3.din(dd[2]);
		R3.dout(qq[2]);
		R3.rw(rw);
		R3.enable(enable);
		R3.clear(clear);

		R4.clk(clk);
		R4.din(dd[3]);
		R4.dout(qq[3]);
		R4.rw(rw);
		R4.enable(enable);
		R4.clear(clear);
//////////////////////////////////////////////////////
		R5.clk(clk);
		R5.din(dd[4]);
		R5.dout(qq[4]);
		R5.rw(rw);
		R5.enable(enable);
		R5.clear(clear);

		R6.clk(clk);
		R6.din(dd[5]);
		R6.dout(qq[5]);
		R6.rw(rw);
		R6.enable(enable);
		R6.clear(clear);

		R7.clk(clk);
		R7.din(dd[6]);
		R7.dout(qq[6]);
		R7.rw(rw);
		R7.enable(enable);
		R7.clear(clear);

		R8.clk(clk);
		R8.din(dd[7]);
		R8.dout(qq[7]);
		R8.rw(rw);
		R8.enable(enable);
		R8.clear(clear);
////////////////////////////////////////////////////////////
		R9.clk(clk);
		R9.din(dd[8]);
		R9.dout(qq[8]);
		R9.rw(rw);
		R9.enable(enable);
		R9.clear(clear);

		R10.clk(clk);
		R10.din(dd[9]);
		R10.dout(qq[9]);
		R10.rw(rw);
		R10.enable(enable);
		R10.clear(clear);

		R11.clk(clk);
		R11.din(dd[10]);
		R11.dout(qq[10]);
		R11.rw(rw);
		R11.enable(enable);
		R11.clear(clear);

		R12.clk(clk);
		R12.din(dd[11]);
		R12.dout(qq[11]);
		R12.rw(rw);
		R12.enable(enable);
		R12.clear(clear);
//////////////////////////////////////////////////////////
		R13.clk(clk);
		R13.din(dd[12]);
		R13.dout(qq[12]);
		R13.rw(rw);
		R13.enable(enable);
		R13.clear(clear);

		R14.clk(clk);
		R14.din(dd[13]);
		R14.dout(qq[13]);
		R14.rw(rw);
		R14.enable(enable);
		R14.clear(clear);

		R15.clk(clk);
		R15.din(dd[14]);
		R15.dout(qq[14]);
		R15.rw(rw);
		R15.enable(enable);
		R15.clear(clear);

		R16.clk(clk);
		R16.din(dd[15]);
		R16.dout(qq[15]);
		R16.rw(rw);
		R16.enable(enable);
		R16.clear(clear);
//////////////////////////////////////////////////////////////
		R17.clk(clk);
		R17.din(dd[16]);
		R17.dout(qq[16]);
		R17.rw(rw);
		R17.enable(enable);
		R17.clear(clear);

		R18.clk(clk);
		R18.din(dd[17]);
		R18.dout(qq[17]);
		R18.rw(rw);
		R18.enable(enable);
		R18.clear(clear);

		R19.clk(clk);
		R19.din(dd[18]);
		R19.dout(qq[18]);
		R19.rw(rw);
		R19.enable(enable);
		R19.clear(clear);

		R20.clk(clk);
		R20.din(dd[19]);
		R20.dout(qq[19]);
		R20.rw(rw);
		R20.enable(enable);
		R20.clear(clear);
/////////////////////////////////////////////////////
		R21.clk(clk);
		R21.din(dd[20]);
		R21.dout(qq[20]);
		R21.rw(rw);
		R21.enable(enable);
		R21.clear(clear);

		R22.clk(clk);
		R22.din(dd[21]);
		R22.dout(qq[21]);
		R22.rw(rw);
		R22.enable(enable);
		R22.clear(clear);

		R23.clk(clk);
		R23.din(dd[22]);
		R23.dout(qq[22]);
		R23.rw(rw);
		R23.enable(enable);
		R23.clear(clear);

		R24.clk(clk);
		R24.din(dd[23]);
		R24.dout(qq[23]);
		R24.rw(rw);
		R24.enable(enable);
		R24.clear(clear);
///////////////////////////////////////////////////////////
		R25.clk(clk);
		R25.din(dd[24]);
		R25.dout(qq[24]);
		R25.rw(rw);
		R25.enable(enable);
		R25.clear(clear);

		R26.clk(clk);
		R26.din(dd[25]);
		R26.dout(qq[25]);
		R26.rw(rw);
		R26.enable(enable);
		R26.clear(clear);

		R27.clk(clk);
		R27.din(dd[26]);
		R27.dout(qq[26]);
		R27.rw(rw);
		R27.enable(enable);
		R27.clear(clear);

		R28.clk(clk);
		R28.din(dd[27]);
		R28.dout(qq[27]);
		R28.rw(rw);
		R28.enable(enable);
		R28.clear(clear);
////////////////////////////////////////////////////////////
		R29.clk(clk);
		R29.din(dd[28]);
		R29.dout(qq[28]);
		R29.rw(rw);
		R29.enable(enable);
		R29.clear(clear);

		R30.clk(clk);
		R30.din(dd[29]);
		R30.dout(qq[29]);
		R30.rw(rw);
		R30.enable(enable);
		R30.clear(clear);

		R31.clk(clk);
		R31.din(dd[30]);
		R31.dout(qq[30]);
		R31.rw(rw);
		R31.enable(enable);
		R31.clear(clear);

		R32.clk(clk);
		R32.din(dd[31]);
		R32.dout(qq[31]);
		R32.rw(rw);
		R32.enable(enable);
		R32.clear(clear);

		sensitive << clk.pos();
	}

};
