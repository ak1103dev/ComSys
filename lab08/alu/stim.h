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
    sc_out<sc_int<16> > ain, bin;
    sc_out<sc_uint<4> > opcode;

    void ps1() {    
		wait();

        ain.write("0b0000");
        bin.write("0b0000");
        opcode.write(0);
        wait();

        ain.write("0b0100");
        bin.write("0b0010");
        opcode.write(0);
        wait();             

        ain.write("0b1110");
        bin.write("0b0010");
        opcode.write(0);
        wait();             

        ain.write("0b0100");
        bin.write("0b0010");
        opcode.write(0);
        wait();             


        ain.write("0b1110");
        bin.write("0b0010");
        opcode.write(0);
        wait();             

        ain.write("0b0100");
        bin.write("0b0010");
        opcode.write(0);
        wait();             

        ain.write("0b0100");
        bin.write("0b0010");
        opcode.write(1);
        wait();             

        ain.write("0b0010");
        bin.write("0b0110");
        opcode.write(1);
        wait();             

        sc_stop();                          // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif

