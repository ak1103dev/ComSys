#include <systemc.h>

SC_MODULE(stim) {
    sc_in<bool> clk, Ready;
    sc_out<sc_uint<16> > RA, RB;
    sc_out<bool> Start;

	void test(unsigned int a, unsigned int b)
	{
		RA.write(a);
		RB.write(b);
		wait();
	}


    void ps1() {
		test(0, 0);
		test(5, 5);
		test(10, 10);
		test(4, 8);
		test(100, 100);
		test(2000, 20);
		sc_stop();
    }

    SC_CTOR(stim) {
        SC_THREAD(ps1);
        sensitive << Ready.neg();
    }
};
