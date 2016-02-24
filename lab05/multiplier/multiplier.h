#include <systemc.h>

SC_MODULE(multiplier) {
	sc_in<bool> clk, Start;
    sc_in<sc_uint<16> > A, B;
    sc_out<sc_uint<32> > C;
	sc_out<bool> Ready;

	sc_uint<16> RA, RB;
	sc_uint<32> RC;

	bool odd(unsigned int x)
	{
		return x % 2;
	}

    void p1() {
		while (1)
		{
			wait(); // Start
			RA=A.read(); RB=B.read(); RC=0;
			while(RA>0)
			{
				if(odd(RA)) RC=RC+RB;
				RA = RA >> 1;
				RB = RB << 1;
			}
			Ready.write(1);
			C.write(RC);
			wait(); // !Start
			Ready.write(0);
		}
    }

    SC_CTOR(multiplier) {
        SC_THREAD(p1);
        sensitive << clk.pos();
    }
};
