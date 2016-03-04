#include <systemc.h>

#include "bit.h"
#include "non-restoring.h"
#include "stim.h"
#include "show.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_uint<N> > D, V, Q, R;
    sc_clock clk("clk",10,SC_NS,0.5);

    division DUT("division");
    DUT.D(D);
    DUT.V(V);
    DUT.Q(Q);
    DUT.R(R);

    stim STIM("stimulus");
    STIM.clk(clk);
    STIM.RD(D);
    STIM.RV(V);

	show SHOW("show");
	SHOW.clk(clk);
    SHOW.D(D);
    SHOW.V(V);
    SHOW.Q(Q);
    SHOW.R(R);

	sc_start(SC_ZERO_TIME);
	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	sc_trace(tf, D, "D");
	sc_trace(tf, V, "V");
	sc_trace(tf, Q, "Q");
	sc_trace(tf, R, "R");
	sc_trace(tf, clk, "clk");
    sc_start(200, SC_NS);

	sc_close_vcd_trace_file(tf);
    return 0;
}
