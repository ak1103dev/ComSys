#include <systemc.h>
#include "2-adder.h"

int sc_main(int argc, char *argv[])
{
	// 1: Instantiate gate objects
	FA2 fa1("fa1");

	// 2: Instantiate signal objects
	sc_signal<bool> A0;
	sc_signal<bool> A1;
	sc_signal<bool> B0;
	sc_signal<bool> B1;
	sc_signal<bool> CI;
	sc_signal<bool> CO;
	sc_signal<bool> SUM0;
	sc_signal<bool> SUM1;

	// 3: Connect the gates to signals
	fa1.A0(A0);
	fa1.A1(A1);
	fa1.B0(B0);
	fa1.B1(B1);
	fa1.CI(CI);
	fa1.CO(CO);
	fa1.SUM0(SUM0);
	fa1.SUM1(SUM1);

	sc_initialize();   // initialize the simulation engine
	// create the file to store simulation results
	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	// 4: specify the signals we’d like to record in the trace file
	sc_trace(tf, CI, "CI");
	sc_trace(tf, A1, "A1");
	sc_trace(tf, A0, "A0");
	sc_trace(tf, B1, "B1");
	sc_trace(tf, B0, "B0");
	sc_trace(tf, CO, "CO");
	sc_trace(tf, SUM1, "SUM1");
	sc_trace(tf, SUM0, "SUM0");
	// 5: put values on the input signals
	A0=0; A1=0; B0=0; B1=0; CI=0;  // initialize the input values
	sc_start(10, SC_PS);
	for( int i = 0 ; i <= 16; i++ )  // generate all input combinations
	{
		A0 = ((i & 0x1) != 0);
		A1 = ((i & 0x2) != 0);
		B0 = ((i & 0x4) != 0);
		B1 = ((i & 0x8) != 0);
		sc_start(10, SC_PS);
		cout << CO << SUM1 << SUM0 << endl;
	}

	sc_close_vcd_trace_file(tf);    // close file and we’re done
	return 0;
}
