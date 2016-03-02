#include <systemc.h>
#include <iostream>
#include "bit.h"

using namespace std;

SC_MODULE(show) {
    sc_in<bool> clk;
    sc_in<sc_uint<N> > D, V, Q, R;

    void pc1() {
		if(V.read() == 0) {
			cout << "No Answer" << endl;
		}
		else {
		cout << D.read() << " / " << V.read() << " = " << Q.read() << " remainder: " << R.read() << endl;
		}
    }

    SC_CTOR(show) {
		SC_METHOD(pc1);
		sensitive << clk.pos();
		dont_initialize();
    }
};

