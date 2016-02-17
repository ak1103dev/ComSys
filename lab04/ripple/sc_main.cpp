//------------------------------------------------------------------
// Simple Testbench for 4-bits adder file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>

#include "adder.h"
#include "stim.h"
#include "check.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_int<32> > ain, bin, sum;
    sc_signal<bool> ci,co,zflag,oflag;

    sc_clock clk("clk",10,SC_NS,0.5);

    addsub32 DUT("addsub32");
    DUT.ain(ain);
    DUT.bin(bin);
    DUT.ci(ci); 
    DUT.sum(sum);
    DUT.co(co);
    DUT.zf(zflag);
    DUT.of(oflag);

    stim STIM("stimulus");
    STIM.clk(clk);
    STIM.ain(ain);
    STIM.bin(bin);
    STIM.ci(ci);

    check CHECK("checker");
    CHECK.clk(clk); 
    CHECK.ain(ain);
    CHECK.bin(bin);
    CHECK.ci(ci);
    CHECK.sum(sum);
    CHECK.co(co);
    CHECK.zflag(zflag);
    CHECK.oflag(oflag);

    sc_initialize();
    sc_trace_file *tf = sc_create_vcd_trace_file("trace");

    sc_trace(tf, ain, "ain"); 
    sc_trace(tf, bin, "bin");
    sc_trace(tf, ci, "add/sub"); 
    sc_trace(tf, sum, "sum");
    sc_trace(tf, co, "co");
    sc_trace(tf, clk, "clk");
    sc_trace(tf, zflag, "zero_flag");
    sc_trace(tf, oflag, "overflow_flag");

    sc_start(200, SC_NS);    
    sc_close_vcd_trace_file(tf);

    return 0;                           // Return OK, no errors.
}
