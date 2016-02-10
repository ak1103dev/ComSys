//------------------------------------------------------------------
// Simple 4-bits adder
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef STIM_H
#define STIM_H

#include <systemc.h>
                                
SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_uint<4> > ain, bin;
    sc_out<bool> ci;

    void ps1() {    
		wait();

        ain.write("0b0000");
        bin.write("0b0000");
        ci.write(false);
        wait();

        ain.write("0b0100");
        bin.write("0b0010");
        ci.write(false);
        wait();             

        ain.write("0b1110");
        bin.write("0b0010");
        ci.write(false);
        wait();             

        ain.write("0b0100");
        bin.write("0b0010");
        ci.write(true);
        wait();             


        ain.write("0b1110");
        bin.write("0b0010");
        ci.write(true);
        wait();             

        ain.write("0b0100");
        bin.write("0b0010");
        ci.write(true);
        wait();             

        sc_stop();                          // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif

