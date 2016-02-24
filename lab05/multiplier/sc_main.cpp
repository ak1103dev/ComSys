#include <systemc.h>

#include "multiplier.h"
#include "stim.h"
#include "show.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_uint<16> > A, B;
    sc_signal<sc_uint<32> > C;
	sc_signal<bool> start, ready;
    sc_clock clk("clk",10,SC_NS,0.5);

    multiplier DUT("multiplier");
    DUT.A(A);
    DUT.B(B);
    DUT.C(C);
    DUT.Start(start);
    DUT.Ready(ready);
    DUT.clk(clk);

    stim STIM("stimulus");
    STIM.clk(clk);
    STIM.Start(start);
    STIM.Ready(ready);
    STIM.RA(A);
    STIM.RB(B);

	show SHOW("show");
	SHOW.clk(clk);
	SHOW.start(start);
	SHOW.ready(ready);
	SHOW.A(A);
	SHOW.B(B);
	SHOW.C(C);

	sc_start(SC_ZERO_TIME);
	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	sc_trace(tf, A, "A");
	sc_trace(tf, B, "B");
	sc_trace(tf, C, "C");
	sc_trace(tf, ready, "ready");
	sc_trace(tf, clk, "clk");
    sc_start(200, SC_NS);

	sc_close_vcd_trace_file(tf);
    return 0;
}
