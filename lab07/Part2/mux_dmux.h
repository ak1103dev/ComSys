#include "systemc.h"

SC_MODULE(mux1to32) {
	sc_in<sc_uint<32> > input;
	sc_in<sc_uint<5> > select;
	sc_out<sc_uint<32> > out[32];

	sc_uint<32> a, b;

	void p1() {
		a = input.read();
		b = select.read();
		out[b].write(a);
	}

	SC_CTOR(mux1to32) {
		SC_METHOD(p1);
		sensitive << input;
	}
};

SC_MODULE(dmux32to1) {
	sc_in<sc_uint<32> > in[32];
	sc_in<sc_uint<5> > select;
	sc_out<sc_uint<32> > output;

	sc_uint<32> a, b;

	void p1() {
		b = select.read();
		output.write(in[b].read());
	}

	SC_CTOR(dmux32to1) {
		SC_METHOD(p1);
		for(int i = 0; i < 32; ++i) {
			sensitive << in[i];
		}
	}
};
