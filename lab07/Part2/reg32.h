#include "reg.h"
#include "divide_compound.h"
#define L 32

SC_MODULE(reg32) {
	sc_in<bool>  clk;
	sc_in<sc_uint<L> > din;
	sc_out<sc_uint<L> > dout;
    sc_in<bool> rw;
    sc_in<bool> enable;
    sc_in<bool> clear;

	sc_signal<sc_uint<L/2> > d1, d2, q1, q2;

	divide div;
	compound comp;
	reg reg1;
	reg reg2;

	SC_CTOR(reg32) : div("div"), comp("comp"), reg1("reg1"), reg2("reg2") {

		sensitive << clk.pos();

		div.input(din);
		div.out1(d1);
		div.out2(d2);

		comp.in1(q1);
		comp.in2(q2);
		comp.output(dout);

		reg1.clk(clk);
		reg1.enable(enable);
		reg1.din(d1);
		reg1.dout(q1);
		reg1.rw(rw);
		reg1.clear(clear);

		reg2.clk(clk);
		reg2.enable(enable);
		reg2.din(d2);
		reg2.dout(q2);
		reg2.rw(rw);
		reg2.clear(clear);
	}
};
