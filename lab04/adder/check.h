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
    sc_in<sc_uint<4> > ain, bin;
    sc_in<bool> ci;
    sc_in<sc_uint<4> > sum;
    sc_in<bool> co;

    sc_uint<5> sumc;


    void pc1() {    

        sumc=ain.read() + bin.read() + ci.read();

        cout << "fulladder " << ain.read() << " + " << bin.read() << " + " << ci.read() << " =" << sum.read()+co.read()*16; 
        if (sumc(3,0)==sum.read() && co==sumc[4]) {
            cout << " Passed" << endl;
        } else {
            cout << " Failed, expected sum=" << sumc(3,0) << " co=" << sumc[4] << endl;
        }

    }

    SC_CTOR(check) {     
        SC_METHOD(pc1);                     
        sensitive << clk.pos();
        dont_initialize();
    }
};
#endif

