//------------------------------------------------------------------
// 4-bits adder checker module
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef CHECK_H
#define CHECK_H

#include <systemc.h>

#include <iostream>
using namespace std;       
                                
SC_MODULE(check) {
    sc_in<bool> clk;
    sc_in<sc_int<16> > ain, bin;
    sc_in<sc_int<16> > result;
    sc_in<sc_uint<4> > opcode;
	sc_in<bool> zflag, oflag;

    void pc1() {
		cout << "a: " << ain.read() << endl;
		cout << "b: " << bin.read() << endl;
		cout << "opcode: " << opcode.read() << endl;
		cout << "result: " << result.read() << endl;
		cout << "zflag: " << zflag.read() << endl;
		cout << "oflag: " << oflag.read() << endl;
		cout << endl;
    }

    SC_CTOR(check) {     
        SC_METHOD(pc1);                     
        sensitive << clk.pos();
        dont_initialize();
    }
};
#endif

