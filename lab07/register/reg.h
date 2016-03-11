#include "dff.h"

SC_MODULE(reg4) {
	sc_in<bool>  clk;
	sc_in<sc_uint<4> >  din;
	sc_out<sc_uint<4> > dout;
    sc_in<bool> rw;
    sc_in<bool> enable;
    sc_in<bool> clear;

	sc_signal<bool> d[4], q[4];

	sc_uint<4> qq;

	dff dff1;
	dff dff2;
	dff dff3;
	dff dff4;

	void p1() {
//		cout << "din: " << din.read() << endl;
		for(int i = 0; i < 4; i++) {
			d[i] = din.read()[i];
			qq[i] = q[i];
		}
		dout.write(qq);
	}

	SC_CTOR(reg4) : dff1("dff1") , dff2("dff2"), dff3("dff3"), dff4("dff4") {
		SC_METHOD(p1);
		sensitive << clk.pos();
		//SC_CTHREAD(p1, clk.pos());

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
	}
};
