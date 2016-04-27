//------------------------------------------------------------------
// Simple Testbench for 4-bits adder file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>

#include "Reduction.h"
#include "Stim.h"
#include "Checker.h"
#include "Outputcollect.h"

#define N 32

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_uint<8> > A0, A1, A2, A3;
    sc_signal<sc_uint<8> > AVG;
    sc_signal<sc_uint<8> > outbuf[N*N/4];
    sc_signal<sc_uint<16> > TCV;

    //sc_start(0, SC_NS);               // Run simulation
    sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal

    reduct DUT("adder");                 // Instantiate Device Under Test
    DUT.A0(A0);                       // Connect ports
    DUT.A1(A1);                       // Connect ports
    DUT.A2(A2);                       // Connect ports
    DUT.A3(A3);                       // Connect ports
    DUT.AVG(AVG);                       // Connect ports

    stim STIM("stimulus");              // Instantiate stimulus generator
    STIM.clk(clk);  
    STIM.A0(A0);
    STIM.A1(A1);
    STIM.A2(A2);
    STIM.A3(A3);

    check CHECK("checker");             // Instantiate checker
    CHECK.clk(clk); 
    CHECK.AVG(AVG);
    CHECK.TCV(TCV);

	ooo OUT("output");
	OUT.AVG(AVG);
	for(int i = 0; i < N*N/4; i++) {
		OUT.outbuf[i](outbuf[i]);
	}

	sc_start(SC_ZERO_TIME);   // initialize the simulation engine
	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	sc_trace(tf, A0, "A0");
	sc_trace(tf, A1, "A1");
	sc_trace(tf, A2, "A2");
	sc_trace(tf, A3, "A3");
	sc_trace(tf, clk, "clk");
	sc_trace(tf, AVG, "AVG");
    sc_start(4000, SC_NS);               // Run simulation

	sc_close_vcd_trace_file(tf);    // close file and we’re done
    return 0;                           // Return OK, no errors.
}
