#include <systemc.h>
#include "1-adder.h"

SC_MODULE(FA2)
{
	sc_in<bool> A0, A1, B0, B1, CI;
	sc_out<bool> CO, SUM0, SUM1;

	FA fa1, fa2;

	sc_signal<bool> C;

	SC_CTOR(FA2): fa1("fa1"), fa2("fa2")
	{
		fa1.A(A0);
		fa1.B(B0);
		fa1.CI(CI);
		fa1.CO(C);
		fa1.SUM(SUM0);

		fa2.A(A1);
		fa2.B(B1);
		fa2.CI(C);
		fa2.CO(CO);
		fa2.SUM(SUM1);

		sensitive << A0 << A1 << B0 << B1 << CI;
	}
};
