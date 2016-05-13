#include <systemc.h>
#define N 16

SC_MODULE(alu) {
	sc_in<sc_int<N> > ain, bin;
	sc_in<sc_uint<4> > opcode;
	sc_out<sc_int<N> > result;
	sc_out<bool> zflag, oflag;

	bool zero, overflow;
	sc_int<N> res;

/*
    bool co0, co1, co2, co3;
    sc_uint<4> sum_s;

    bool fulladder(bool a, bool b, bool cif, bool& cof) {
		bool sumr;
		sumr =(a ^ b) ^ cif;
		cof=(a & b) | ((a ^ b) & cif);
		return sumr;
    }

    void p1() {
		sum_s[0]=fulladder(ain.read()[0],bin.read()[0],ci.read(), co0);
		sum_s[1]=fulladder(ain.read()[1],bin.read()[1],co0,co1);
		sum_s[2]=fulladder(ain.read()[2],bin.read()[2],co1,co2);
		sum_s[3]=fulladder(ain.read()[3],bin.read()[3],co2,co3);

		sum.write(sum_s);
		co.write(co3);

		zflag = (!(sum_s[0] | sum_s[1] | sum_s[2] | sum_s[3] | co3));
		oflag = (co3);

		if (zflag.read()==true) {
			cout << "zero value" << endl;
		}
		if (oflag.read() == true){
			cout << "overflow value" << endl;
		}
		cout << endl;
    }
	*/
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

