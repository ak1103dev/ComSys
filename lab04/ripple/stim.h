#ifndef STIM_H
#define STIM_H

#include <systemc.h>

SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_int<32> > ain, bin;
    sc_out<bool> ci;

    void ps1() {    

		wait();       
		ain.write(-5);
		bin.write(7);
		ci.write(0);
		wait();             
		
		ain.write(7);
		bin.write(-3);
		ci.write(0);
		wait();  
		
		ain.write(500);
		bin.write(500);
		ci.write(1);
		wait();  
		
		ain.write(0x7fffffff);
		bin.write(0x7fffffff);
		ci.write(0);
		wait();

		sc_stop();
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);
        sensitive << clk.pos();
    }
};
#endif

