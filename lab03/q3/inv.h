#include <systemc.h>

SC_MODULE(INV)
{
	sc_in<bool> a;
	sc_out<bool> o;
	SC_CTOR(INV)
	{
		SC_METHOD(inv_process);
		sensitive << a;
	}
	void inv_process() {
		o.write(!a.read());
	}
};
