#include <systemc.h>
#include <iostream>

using namespace std;

SC_MODULE(show) {
    sc_in<bool> clk, start, ready;
    sc_in<sc_uint<16> > A, B;
    sc_in<sc_uint<32> > C;

    void pc1() {
		cout << A.read() << " * " << B.read() << " = " << C.read() << endl;
		cout << "clk=" << clk << ", start=" << start << ", ready="  << ready << endl;
    }

    SC_CTOR(show) {
		SC_METHOD(pc1);
		sensitive << ready.neg();
		dont_initialize();
    }
};

