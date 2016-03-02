#include <systemc.h>
#include "bit.h"

SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_uint<N> > RD, RV;

	void test(unsigned int a, unsigned int b)
	{
		RD.write(a);
		RV.write(b);
		wait();
	}


    void ps1() {
		test(0, 0);
		test(30, 4);
		test(30, 5);
		sc_stop();
    }

    SC_CTOR(stim) {
        SC_THREAD(ps1);
        sensitive << clk.pos();
    }
};
