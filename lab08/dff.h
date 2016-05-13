#include "systemc.h"

SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;
    sc_in<bool> reset;

    sc_in<bool> enable; // enable =1, to use it but enable = 0 output is 0 (ZERO ALL)
    sc_in<bool> rw; // rw=0 (read), rw=1 (write)
    sc_in<bool> clr; // clr = 0; clear  value to zeroall // clr = 1; not clear value;
    bool value; //  holding value in here

    // sc_out<bool> ready;
 
    void p1() {
       while(true) {
          wait();
          // ready.write(false);
          if (enable.read() == true) {
            if (rw.read() == true) {
                value = din.read();
            }
            if (clr.read() == false) {
              value = false;
            }
            dout.write(value);
            // ready.write(true);
            // cout << "--> ready = " ready.read();
            // wait();
          }
       }
    }

    SC_CTOR(dff) {
        SC_CTHREAD(p1, clk.pos()); // call p1 only once
        // sensitive << clk.pos();
    }
};
