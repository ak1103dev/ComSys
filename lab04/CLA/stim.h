#ifndef STIM_H
#define STIM_H

#include <systemc.h>

SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_int<4> > ain, bin;
    sc_out<bool> ci;

    void ps1() {    

		wait();       
		ain.write(7);
		bin.write(5);
		ci.write(0);
		wait();             
		
		ain.write(7);
		bin.write(5);
		ci.write(1);
		wait();  
		
		ain.write(-5);
		bin.write(3);
		ci.write(0);
		wait();  
		
		ain.write(-5);
		bin.write(3);
		ci.write(1);
		wait();

		ain.write(5);
		bin.write(5);
		ci.write(1);
		wait();

		ain.write(-1);
		bin.write(-8);
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

