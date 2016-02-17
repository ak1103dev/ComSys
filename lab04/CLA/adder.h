#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>
#include "flag.h"

SC_MODULE(adder4) {
    sc_in<sc_int<4> > ain, bin;
    sc_in<bool> ci;
    sc_out<sc_int<4> > sum;
	sc_out<bool> co, zf, of;
    //sc_out<bool> po, go;

    bool co1, co2, co3, co4;
	bool p0, p1, p2, p3;
	bool g0, g1, g2, g3;
    sc_int<4> sum_s;
    bool fulladder(bool a, bool b, bool cif, bool& cof, bool& pof, bool& gof) {
        bool s;
		b = b ^ ci.read();
		gof = a & b;
		pof = a | b;
		cof = gof | (pof & cif);
		s = a ^ b ^ cif;
        return s;
    }

	zeroflag zero;
	overflag over;

    void process() {
        sum_s[0]=fulladder(ain.read()[0],bin.read()[0],ci.read(), co1, p0, g0);
        sum_s[0]=fulladder(ain.read()[0],bin.read()[0],ci.read(), co1, p0, g0);
        sum_s[1]=fulladder(ain.read()[1],bin.read()[1],co1,co2, p1, g1);
        sum_s[2]=fulladder(ain.read()[2],bin.read()[2],co2,co3, p2, g2);
        sum_s[3]=fulladder(ain.read()[3],bin.read()[3],co3,co4, p3, g3);

        sum.write(sum_s);
        co.write(co4);
    }

    SC_CTOR(adder4): zero("zero"), over("over")
	{
        SC_METHOD(process);


		zero.in(sum);
		zero.out(zf);

		over.ain(ain);
		over.bin(bin);
		over.sum(sum);
		over.out(of);

        sensitive << ain << bin << ci;
    }
};

#endif
