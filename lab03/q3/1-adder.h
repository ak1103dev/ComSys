#include <systemc.h>
#include "and.h"
#include "or.h"
#include "inv.h"
#include "nor.h"

SC_MODULE(FA)
{
	sc_in<bool> A, B, CI;
	sc_out<bool> CO, SUM;

	OR2 or1, or8;
	OR3  or2;
	AND2 and3, and4, and5;
	AND3 and6;
	NOR2 nor7;
	INV  inv9;

	sc_signal<bool> or_1;
	sc_signal<bool> or_2;
	sc_signal<bool> and_3;
	sc_signal<bool> and_4;
	sc_signal<bool> and_5;
	sc_signal<bool> and_6;
	sc_signal<bool> nor_7;

	SC_CTOR(FA):
		or1("or1"), or8("or8"), or2("or2"),
		and3("and3"), and4("and4"), and5("and5"), and6("and6"),
		nor7("nor7"), inv9("inv9")
	{
		or1.a(A); or1.b(B); or1.o(or_1);
		or2.a(A); or2.b(B); or2.c(CI); or2.o(or_2);
		and3.a(or_1); and3.b(CI); and3.o(and_3);
		and4.a(A); and4.b(B); and4.o(and_4);
		and5.a(nor_7); and5.b(or_2); and5.o(and_5);
		and6.a(A); and6.b(B); and6.c(CI); and6.o(and_6);
		nor7.a(and_3); nor7.b(and_4); nor7.o(nor_7);
		or8.a(and_5); or8.b(and_6); or8.o(SUM);
		inv9.a(nor_7); inv9.o(CO);
		sensitive << A << B << CI;
	}
};
