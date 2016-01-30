#include <systemc.h>

SC_MODULE(NOR2)
{
	sc_in<bool> a;
	sc_in<bool> b;
	sc_out<bool> o;
	SC_CTOR(NOR2)
	{
		SC_METHOD(or_process);
		sensitive << a << b;
	}
	void or_process() {
		o.write(!(a.read() || b.read()));
	}
};
