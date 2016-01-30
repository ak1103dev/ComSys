#include <systemc.h>

SC_MODULE(AND2)
{
	sc_in<bool> a;
	sc_in<bool> b;
	sc_out<bool> o;
	SC_CTOR(AND2)
	{
		SC_METHOD(and_process);
		sensitive << a << b;
	}
	void and_process() {
		o.write(a.read() && b.read());
	}
};

SC_MODULE(AND3)
{
	sc_in<bool> a;
	sc_in<bool> b;
	sc_in<bool> c;
	sc_out<bool> o;
	SC_CTOR(AND3)
	{
		SC_METHOD(or_process);
		sensitive << a << b << c;
	}
	void or_process() {
		o.write(a.read() && b.read() && c.read());
	}
};
