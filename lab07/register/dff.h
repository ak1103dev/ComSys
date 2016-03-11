#include "systemc.h"

SC_MODULE(dff) {
    sc_in<bool> clk;
    sc_in<bool> din;
    sc_out<bool> dout;
    sc_in<bool> rw; // 0->r, 1->w
    sc_in<bool> enable; // 1->use
    sc_in<bool> clear; // 0->clear

	bool value;

	void p1() {
		while(true) {
			wait();
			if(!clear) {
				value = '0';
			}
			else if(enable) {
				if(rw) {
//					cout << "din: " << din.read() << endl;
					value = din.read();
					//cout << "value: " << value << endl;
				}
				else {
					dout.write(value);
				}
			}
		}
	}

	SC_CTOR(dff) {
		SC_CTHREAD(p1, clk.pos());
		//SC_THREAD(p1);
		//sensitive << clk.pos();
	}
};
