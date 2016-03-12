#include "dff.h"
#define N 16

SC_MODULE(reg) {
	sc_in<bool>  clk;
	sc_in<sc_uint<N> > din;
	sc_out<sc_uint<N> > dout;
    sc_in<bool> rw;
    sc_in<bool> enable;
    sc_in<bool> clear;

	sc_signal<bool> d[N], q[N];

	sc_uint<N> qq;

	dff dff1;
	dff dff2;
	dff dff3;
	dff dff4;
	dff dff5;
	dff dff6;
	dff dff7;
	dff dff8;
	dff dff9;
	dff dff10;
	dff dff11;
	dff dff12;
	dff dff13;
	dff dff14;
	dff dff15;
	dff dff16;

	void p1() {
		for(int i = 0; i < N; i++) {
			d[i] = din.read()[i];
			qq[i] = q[i];
		}
		dout.write(qq);
	}

	SC_CTOR(reg) : dff1("dff1") , dff2("dff2"), dff3("dff3"), dff4("dff4"), dff5("dff5"), dff6("dff6"), dff7("dff7"), dff8("dff8"), dff9("dff9"), dff10("dff10"), dff11("dff11"), dff12("dff12"), dff13("dff13"), dff14("dff14"), dff15("dff15"), dff16("dff16") {
		SC_METHOD(p1);
		sensitive << din << clk.pos();

		dff1.clk(clk);
		dff1.enable(enable);
		dff1.din(d[0]);
		dff1.dout(q[0]);
		dff1.rw(rw);
		dff1.clear(clear);

		dff2.clk(clk);
		dff2.enable(enable);
		dff2.din(d[1]);
		dff2.dout(q[1]);
		dff2.rw(rw);
		dff2.clear(clear);

		dff3.clk(clk);
		dff3.enable(enable);
		dff3.din(d[2]);
		dff3.dout(q[2]);
		dff3.rw(rw);
		dff3.clear(clear);

		dff4.clk(clk);
		dff4.enable(enable);
		dff4.din(d[3]);
		dff4.dout(q[3]);
		dff4.rw(rw);
		dff4.clear(clear);

		dff5.clk(clk);
		dff5.enable(enable);
		dff5.din(d[4]);
		dff5.dout(q[4]);
		dff5.rw(rw);
		dff5.clear(clear);

		dff6.clk(clk);
		dff6.enable(enable);
		dff6.din(d[5]);
		dff6.dout(q[5]);
		dff6.rw(rw);
		dff6.clear(clear);

		dff7.clk(clk);
		dff7.enable(enable);
		dff7.din(d[6]);
		dff7.dout(q[6]);
		dff7.rw(rw);
		dff7.clear(clear);

		dff8.clk(clk);
		dff8.enable(enable);
		dff8.din(d[7]);
		dff8.dout(q[7]);
		dff8.rw(rw);
		dff8.clear(clear);

		dff9.clk(clk);
		dff9.enable(enable);
		dff9.din(d[8]);
		dff9.dout(q[8]);
		dff9.rw(rw);
		dff9.clear(clear);

		dff10.clk(clk);
		dff10.enable(enable);
		dff10.din(d[9]);
		dff10.dout(q[9]);
		dff10.rw(rw);
		dff10.clear(clear);

		dff11.clk(clk);
		dff11.enable(enable);
		dff11.din(d[10]);
		dff11.dout(q[10]);
		dff11.rw(rw);
		dff11.clear(clear);

		dff12.clk(clk);
		dff12.enable(enable);
		dff12.din(d[11]);
		dff12.dout(q[11]);
		dff12.rw(rw);
		dff12.clear(clear);

		dff13.clk(clk);
		dff13.enable(enable);
		dff13.din(d[12]);
		dff13.dout(q[12]);
		dff13.rw(rw);
		dff13.clear(clear);

		dff14.clk(clk);
		dff14.enable(enable);
		dff14.din(d[13]);
		dff14.dout(q[13]);
		dff14.rw(rw);
		dff14.clear(clear);

		dff15.clk(clk);
		dff15.enable(enable);
		dff15.din(d[14]);
		dff15.dout(q[14]);
		dff15.rw(rw);
		dff15.clear(clear);

		dff16.clk(clk);
		dff16.enable(enable);
		dff16.din(d[15]);
		dff16.dout(q[15]);
		dff16.rw(rw);
		dff16.clear(clear);
	}
};
