//------------------------------------------------------------------
// Simple 4-bits adder
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>
                                
SC_MODULE(reduct) {
    sc_in<sc_uint<8> > A0, A1, A2, A3;
	sc_out<sc_uint<8> > AVG;

    void p1() { 
		AVG.write((A0.read() + A1.read() + A2.read() + A3.read())/4);
    }

    SC_CTOR(reduct) {     
        SC_METHOD(p1);  
        sensitive << A0 << A1 << A2 << A3; 
    }
};
#endif

