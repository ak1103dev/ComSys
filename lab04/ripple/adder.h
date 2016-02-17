#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>
#include "resize.h"
#include "one_complement.h"
#include "flag.h"

SC_MODULE(adder4) {
    sc_in<sc_int<4> > ain, bin;
    sc_in<bool> ci;
    sc_out<sc_int<4> > sum;
    sc_out<bool> co;

    bool co0, co1, co2, co3;
    sc_int<4> sum_s;
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
    }

    SC_CTOR(adder4) {     
        SC_METHOD(p1);  
        sensitive << ain << bin << ci; 
    }
};


SC_MODULE(addsub32) {
    sc_in<sc_int<32> > ain, bin;
    sc_in<bool> ci;
    sc_out<sc_int<32> > sum;
    sc_out<bool> co, zf, of;

    sc_signal<bool> c0, c1, c2, c3, c4, c5, c6, c7;
    sc_signal<sc_int<4> > a[8], b[8], s[8];
    sc_signal<sc_int<32> > b_new;

    adder4 add0, add1, add2, add3, add4, add5, add6, add7;
    r32to4 ra, rb; 
    r4to32 rs;
    one_comp oc_b;
    zeroflag zero;
    overflag overflow;

    SC_CTOR(addsub32): add0("add0"), add1("add1"), add2("add2"), add3("add3"), add4("add4"), add5("add5"), add6("add6"), add7("add7"), ra("ra"), rb("rb"), oc_b("ocb"), rs("rs"), zero("zero"), overflow("overflow") 
    {
		oc_b.in(bin);
		oc_b.x(ci);
		oc_b.out(b_new);

		ra.in(ain);
		ra.o0(a[0]);
		ra.o1(a[1]);
		ra.o2(a[2]);
		ra.o3(a[3]);
		ra.o4(a[4]);
		ra.o5(a[5]);
		ra.o6(a[6]);
		ra.o7(a[7]);

		rb.in(b_new);
		rb.o0(b[0]);
		rb.o1(b[1]);
		rb.o2(b[2]);
		rb.o3(b[3]);
		rb.o4(b[4]);
		rb.o5(b[5]);
		rb.o6(b[6]);
		rb.o7(b[7]);

		add0.ain(a[0]); add0.bin(b[0]); add0.ci(ci); add0.sum(s[0]); add0.co(c0);
		add1.ain(a[1]); add1.bin(b[1]); add1.ci(c0); add1.sum(s[1]); add1.co(c1);
		add2.ain(a[2]); add2.bin(b[2]); add2.ci(c1); add2.sum(s[2]); add2.co(c2);
		add3.ain(a[3]); add3.bin(b[3]); add3.ci(c2); add3.sum(s[3]); add3.co(c3);
		add4.ain(a[4]); add4.bin(b[4]); add4.ci(c3); add4.sum(s[4]); add4.co(c4);
		add5.ain(a[5]); add5.bin(b[5]); add5.ci(c4); add5.sum(s[5]); add5.co(c5);
		add6.ain(a[6]); add6.bin(b[6]); add6.ci(c5); add6.sum(s[6]); add6.co(c6);
		add7.ain(a[7]); add7.bin(b[7]); add7.ci(c6); add7.sum(s[7]); add7.co(co);

		rs.i0(s[0]);
		rs.i1(s[1]);
		rs.i2(s[2]);
		rs.i3(s[3]);
		rs.i4(s[4]);
		rs.i5(s[5]);
		rs.i6(s[6]);
		rs.i7(s[7]);
		rs.out(sum);

		zero.in(sum); zero.out(zf);
		overflow.ain(ain); overflow.bin(b_new); overflow.sum(sum); overflow.out(of);

		sensitive << ain << bin << ci;
    }
};


#endif
