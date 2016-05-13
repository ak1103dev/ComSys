#include <systemc.h>
#define N 16

SC_MODULE(alu) {
	sc_in<sc_uint<N> > ain, bin;
	sc_in<sc_uint<4> > opcode;
	sc_out<sc_uint<N> > result;
	sc_out<bool> zflag, oflag;

	bool zero, overflow;
	sc_uint<N> res;

	sc_int<N> add(sc_int<N> a, sc_int<N> b) {
		return a + b;
	}
	sc_int<N> slt(sc_int<N> a, sc_int<N> b) {
		if (a < b)
			return 1;
		else
			return 0;
	}


	void p1() {
		sc_int<N> a, b;
		a = ain.read();
		b = bin.read();
		switch(opcode.read()) {
			case 0:
				res = add(a, b);
				overflow = (a[15] || b[15] || res[15]) & (!a[15] || !b[15] || !res[15]);
				break;
			case 1:
				res = slt(a, b);
				break;
		}
		result.write(res);
		oflag.write(overflow);
		zflag.write(res == 0);
	}

	SC_CTOR(alu) {
		SC_METHOD(p1);
		sensitive << ain << bin << opcode;
	}
};

