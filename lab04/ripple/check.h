#ifndef CHECK_H
#define CHECK_H

#include <systemc.h>

#include <iostream>
using namespace std;       
                                
SC_MODULE(check) {
    sc_in<bool> clk;
    sc_in<sc_int<32> > ain, bin;
    sc_in<bool> ci;
    sc_in<sc_int<32> > sum;
    sc_in<bool> co;
    sc_in<bool> oflag, zflag;

    sc_int<33> sumc;

    void pc1() {    
		bool c = ci.read();
		if (!c) {
			sumc = (long)ain.read() + (long)bin.read();
		}
		else {
			sumc = (long)ain.read() - (long)bin.read();   
		}
		
		cout << "fulladder " << ain.read() << (c?" - ":" + ") << bin.read() << " = " << sum.read() << "  co = " << co; 
		
		if (sumc==sum.read()) {
			cout << "  Passed" << endl;
		} else {
			cout << "  Failed, expected sum=" << sumc << " co=" << sumc[32] << endl;
		}
		if (zflag.read()==true) {
			cout << "** zero value" << endl;
		}
		if (oflag.read()==true) {
			cout << "** overflow value" << endl;
		}
	}
	
	SC_CTOR(check) {     
		SC_METHOD(pc1);                     
		sensitive << clk.pos();
		dont_initialize();
	}
};
#endif
