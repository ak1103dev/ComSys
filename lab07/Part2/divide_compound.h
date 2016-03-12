#include "systemc.h"

SC_MODULE(divide) {
	sc_in<sc_uint<32> > input;
	sc_out<sc_uint<16> > out1, out2;

	sc_uint<32> a;

	void p1() {
		a = input.read();
		out1.write(a(15, 0));
		out2.write(a(31, 16));
	}

	SC_CTOR(divide) {
		SC_METHOD(p1);
		sensitive << input;
	}
};

SC_MODULE(compound) {
	sc_in<sc_uint<16> > in1, in2;
	sc_out<sc_uint<32> > output;

	sc_uint<32> a;

	void p1() {
		a(15, 0) = in1.read();
		a(31, 16) = in2.read();
		output.write(a);
	}

	SC_CTOR(compound) {
		SC_METHOD(p1);
		sensitive << in1 << in2;
	}
};
