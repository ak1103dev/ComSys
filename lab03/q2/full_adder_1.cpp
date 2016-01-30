#include <systemc.h>
#include "and.h"
#include "or.h"
#include "inv.h"
#include "nor.h"

int sc_main(int argc, char *argv[])
{
	// 1: Instantiate gate objects
	OR2  or1("or1"), or8("or8");
	OR3  or2("or2");
	AND2 and3("and3"), and4("and4"), and5("and5");
	AND3 and6("and6");
	NOR2 nor7("nor7");
	INV  inv9("inv9");

	// 2: Instantiate signal objects
	sc_signal<bool> A;
	sc_signal<bool> B;
	sc_signal<bool> CI;
	sc_signal<bool> or_1;
	sc_signal<bool> or_2;
	sc_signal<bool> and_3;
	sc_signal<bool> and_4;
	sc_signal<bool> and_5;
	sc_signal<bool> and_6;
	sc_signal<bool> nor_7;
	sc_signal<bool> CO;
	sc_signal<bool> SUM;

	// 3: Connect the gates to signals
	or1.a(A); or1.b(B); or1.o(or_1);
	or2.a(A); or2.b(B); or2.c(CI); or2.o(or_2);
	and3.a(or_1); and3.b(CI); and3.o(and_3);
	and4.a(A); and4.b(B); and4.o(and_4);
	and5.a(nor_7); and5.b(or_2); and5.o(and_5);
	and6.a(A); and6.b(B); and6.c(CI); and6.o(and_6);
	nor7.a(and_3); nor7.b(and_4); nor7.o(nor_7);
	or8.a(and_5); or8.b(and_6); or8.o(SUM);
	inv9.a(nor_7); inv9.o(CO);

	sc_initialize();   // initialize the simulation engine
	// create the file to store simulation results
	sc_trace_file *tf = sc_create_vcd_trace_file("trace");
	// 4: specify the signals we’d like to record in the trace file
	sc_trace(tf, A, "A"); sc_trace(tf, B, "B");
	sc_trace(tf, CI, "CI");
	sc_trace(tf, SUM, "SUM"); sc_trace(tf, CO, "CO");
	// 5: put values on the input signals
	A=0; B=0; CI=0;                 // initialize the input values
	sc_start(10, SC_PS);
	for( int i = 0 ; i <= 8 ; i++ )  // generate all input combinations
	{
		A  = ((i & 0x1) != 0);    // value of A is the bit0 of i
		B  = ((i & 0x2) != 0);    // value of B is the bit1 of i
		CI = ((i & 0x4) != 0);    // value of CI is the bit2 of i
		sc_start(10, SC_PS);           // evaluate
	}

	sc_close_vcd_trace_file(tf);    // close file and we’re done
	return 0;
}
