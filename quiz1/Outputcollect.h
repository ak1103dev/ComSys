//------------------------------------------------------------------
// Simple 4-bits adder
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#include <systemc.h>

#define N 32
                                
SC_MODULE(ooo) {
    sc_in<sc_uint<8> > AVG;
	sc_out<sc_uint<8> > outbuf[N*N/4];

    void p1() { 
		for(int i = 0; i < N*N/4; i++) {
			outbuf[i].write(AVG.read());
		}
    }

    SC_CTOR(ooo) {     
        SC_METHOD(p1);  
        sensitive << AVG;
    }
};
