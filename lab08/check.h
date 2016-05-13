#ifndef CHECK_H
#define CHECK_H

#include "setting.h"
#include <systemc.h>

#include <iostream>
using namespace std;

SC_MODULE(check) {
    sc_in<bool> clk, enable, rw, clr;//, ready;
    sc_in<sc_uint<N_BIT_REG> > write_data, src1_data, src2_data;//din, dout;
    // sc_uint<BIT_ADDR> module__index;
    // sc_in<sc_uint<BIT_ADDR> > _index;
    sc_in<sc_uint<BIT_ADDR> > src1_addr, src2_addr, dst_addr;//addr;

    // sc_uint<5> module__index;

    void pc1() {
            if (enable.read() == true) {
                if (rw.read() == 0) {
                  cout << "[";
                // }
                    ///cout << "ADDR = " << addr.read() << " --> din = " << din.read() << " dout = " << dout.read() << " enable = " << enable.read() << " rw = " << rw.read() << " clr = " << clr.read(); // << " clk = " << clk;
                    cout << "ADDR1 = " << src1_addr.read() << " --> din = " << write_data.read() << " dout = " << src1_data.read() << " enable = " << enable.read() << " rw = " << rw.read() << " clr = " << clr.read(); // << " clk = " << clk;
                    cout << endl << "ADDR2 = " << src2_addr.read() << " --> din = " << write_data.read() << " dout = " << src2_data.read() << " enable = " << enable.read() << " rw = " << rw.read() << " clr = " << clr.read(); // << " clk = " << clk;


                // if (rw.read() == 0) {
                  cout << "]";
                  cout << endl << endl;
                }
                // cout << endl << endl;

            }
    }

    SC_CTOR(check) {
        SC_METHOD(pc1);
        sensitive << enable << rw << clr << write_data << src1_data << src2_data;
    }
};
#endif
