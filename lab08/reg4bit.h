#include "dff.h"
 
SC_MODULE(reg4) {
 
    sc_in<bool >  clk;
    sc_in<bool >  reset;
    sc_in<bool > enable, rw, clr; 
    sc_out<sc_uint<4> > dout;
    sc_in<sc_uint<4> >  din;
    sc_signal<bool > _d[4], _q[4];
    sc_uint<4> d,q;
    dff dff1, dff2, dff3, dff4;
    
    // sc_out<bool> ready;
    // sc_signal<bool> ready_dff1, ready_dff2, ready_dff3, ready_dff4;
// 
    // sc_uint<4> ready_dff;

    void p1()
    {
      // while (true) {
      //   wait();
        d = din.read();
        for (int i = 0; i < 4; i++) {
          _d[i] =  (d[i] == 0 ? false : true);
        }
      // }
    }
  
    void p2()
    { 
        // while (true) {
        //   wait();
          for (int i = 0; i < 4; i++) {
            q[i] = _q[i];
          }
          dout.write(q);
        // }
    }

 
    SC_CTOR(reg4) : dff1("dff1"), dff2("dff2"), dff3("dff3"), dff4("dff4") {

    SC_METHOD(p1);
    // sensitive << din << clk;
    sensitive << clk.pos();
    SC_METHOD(p2);
    // sensitive << dout << clk;
    sensitive << clk.pos();

    d=0; q=0;

    dff1.clk(clk);  // Named association
    dff1.reset(reset);
    dff1.din(_d[0]);
    dff1.dout(_q[0]);
 
    dff2.clk(clk);
    dff2.reset(reset);
    dff2.din(_d[1]);
    dff2.dout(_q[1]);

    dff3.clk(clk);
    dff3.reset(reset);
    dff3.din(_d[2]);
    dff3.dout(_q[2]);

    dff4.clk(clk);
    dff4.reset(reset);
    dff4.din(_d[3]);
    dff4.dout(_q[3]);
  

    // =============================
    dff1.enable(enable);
    dff1.rw(rw);
    dff1.clr(clr);

    dff2.enable(enable);
    dff2.rw(rw);
    dff2.clr(clr);

    dff3.enable(enable);
    dff3.rw(rw);
    dff3.clr(clr);

    dff4.enable(enable);
    dff4.rw(rw);
    dff4.clr(clr);
    // =============================

    // dff1.ready(ready_dff1);
    // dff2.ready(ready_dff2);
    // dff3.ready(ready_dff3);
    // dff4.ready(ready_dff4);
  }
};
