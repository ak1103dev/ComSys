#include <systemc.h>
#include "2-adder.h"

int sc_main(int argc, char *argv[])
{
	FA2 aa("aa");

	sc_signal<bool> a0;
	sc_signal<bool> a1;
	sc_signal<bool> b0;
	sc_signal<bool> b1;
	sc_signal<bool> ci;
	sc_signal<bool> co;
	sc_signal<bool> s0;
	sc_signal<bool> s1;

	aa.A0(a0);
	aa.B0(b0);
	aa.A1(a1);
	aa.B1(b1);
	aa.CI(ci);
	aa.CO(co);
	aa.SUM0(s0);
	aa.SUM1(s1);

	a0 = 0; a1 = 0;
	b0 = 0; b1 = 0;
   	ci = 0;
	co = 0;
	s0 = 0; s1 = 0;
	sc_start(2, SC_NS);
	//cout << "A: " << a0 << ", B: " << b0  << ", C: " << ci << endl;
	cout << "O: " << co << s0 << s1 << endl;

//	one_bit_adder aaa("aaa");

//	sc_signal<bool> a;
//	sc_signal<bool> b;
//	sc_signal<bool> ci;
//	sc_signal<bool> co;
//	sc_signal<bool> sum;
//
//	aaa.A(a);
//	aaa.B(b);
//	aaa.CI(ci);
//	aaa.CO(co);
//	aaa.SUM(sum);
//
//	a = 0; b = 0, ci = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 0; b = 0, ci = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 0; b = 1, ci = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 0; b = 1, ci = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 1; b = 0, ci = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 1; b = 0, ci = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 1; b = 1, ci = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;
//
//	a = 1; b = 1, ci = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b  << ", C: " << ci << endl;
//	cout << "O: " << co << sum << endl;

	//OR2 or1("or1");
	//sc_signal<bool> a;
	//sc_signal<bool> b;
	//sc_signal<bool> o;

	//or1.a(a);
	//or1.b(b);
	//or1.o(o);

	//a = 0; b = 0;
	//sc_start(2, SC_NS);
	//cout << "A: " << a << ", B: " << b << ", O: " << o << endl;

	//a = 0; b = 1;
	//sc_start(2, SC_NS);
	//cout << "A: " << a << ", B: " << b << ", O: " << o << endl;

	//a = 1; b = 0;
	//sc_start(2, SC_NS);
	//cout << "A: " << a << ", B: " << b << ", O: " << o << endl;

	//a = 1; b = 1;
	//sc_start(2, SC_NS);
	//cout << "A: " << a << ", B: " << b << ", O: " << o << endl;


//	AND2 or1("or1");
//	sc_signal<bool> a;
//	sc_signal<bool> b;
//	sc_signal<bool> o;
//
//	or1.a(a);
//	or1.b(b);
//	or1.o(o);
//
//	a = 0; b = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b << ", O: " << o << endl;
//
//	a = 0; b = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b << ", O: " << o << endl;
//
//	a = 1; b = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b << ", O: " << o << endl;
//
//	a = 1; b = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", B: " << b << ", O: " << o << endl;

//	INV inv1("inv1");
//	sc_signal<bool> a;
//	sc_signal<bool> o;
//
//	inv1.a(a);
//	inv1.o(o);
//
//	a = 0;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", O: " << o << endl;
//
//	a = 1;
//	sc_start(2, SC_NS);
//	cout << "A: " << a << ", O: " << o << endl;


	// 1: Instantiate gate objects
//	OR2  or1("or1"), or8(“or8”);
//	OR3  or2(“or2”);
//	AND2 and3("and3"), and4("and4"), and5("and5");
//	AND3 and6("and6");
//	NOR2 nor7(“nor7");
//	INV  inv9(“inv9”);
	// 2: Instantiate signal objects

	// 3: Connect the gates to signals
	// 4: specify which values to print
	// 5: put values on signal objects
	// 6: Start simulator run
	return 0;
}
