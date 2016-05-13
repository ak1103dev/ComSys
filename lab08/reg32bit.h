#include "reg16bit.h"
// #include "reg16_.h"
 
SC_MODULE(reg32) {
 
    sc_in<bool >  clk;
    sc_in<bool >  reset;
    sc_in<bool > enable, rw, clr; 
    sc_out<sc_uint<32> > dout;
    sc_in<sc_uint<32> >  din;

    sc_signal<sc_uint<16> > _d[2], _q[2];
    sc_uint<32> d,q;

    sc_uint<5> module__index;
    sc_in<sc_uint<5> > _index;
    sc_in<sc_uint<5> > addr;
    // sc_out<bool> ready;

    reg16 reg16_1, reg16_2;//, reg16_3, reg16_4;

    // sc_signal<bool> ready_reg16_1, ready_reg16_2, ready_reg16_3, ready_reg16_4;

    // sc_uint<4> ready_reg4;

    void p1()
    {
        // while (true) {
        //   wait();
        // cout << "addr.read =" << addr.read() << " module__index = " << module__index << endl;
        if (addr.read() == module__index) {
          d = din.read();
          for (int i = 0; i < 2; i++) {
            _d[i] =  d(i*16+15, i*16);
          }
      // }
        }
    }
  
    void p2()
    { 
        // while (true) {
        //   wait();
        if (addr.read() == module__index) {
          for (int i = 0; i < 2; i++) {
            q(i*16+15, i*16) = _q[i];
          }
          dout.write(q);
        // }
        }

    }

    void p3() {
        module__index = _index.read();
        // cout << " module index " << module__index << endl;
    }

    // void run() {
    //     while (true) {
    //         wait();
    //         ready.write(false);
    //         p1();
    //         p2();
    //         // while (ready.read() != true) {
    //             ready_reg4[0] = ready_reg16_1.read();
    //             ready_reg4[1] = ready_reg16_2.read();
    //             ready_reg4[2] = ready_reg16_3.read();
    //             ready_reg4[3] = ready_reg16_4.read();

    //             ready.write(ready_reg4.and_reduce());
    //             // wait();
    //         // }
    //     }
    // }
 
    SC_CTOR(reg32) : reg16_1("reg16_1"), reg16_2("reg16_2") {//reg16_1("reg16_1"), reg16_2("reg16_2"), reg16_3("reg16_3"), reg16_4("reg16_4") {
    
    SC_METHOD(p3);
    sensitive << _index;
    SC_METHOD(p1);
    sensitive << clk.pos();
    SC_METHOD(p2);
    sensitive << clk.pos();
    
    

    // SC_CTHREAD(p1, clk);
    // SC_CTHREAD(p2, clk);

    // SC_CTHREAD(run, clk);

    
    d=0; q=0;

    reg16_1.clk(clk);
    reg16_1.reset(reset);
    reg16_1.din(_d[0]);
    reg16_1.dout(_q[0]);
 
    reg16_2.clk(clk);
    reg16_2.reset(reset);
    reg16_2.din(_d[1]);
    reg16_2.dout(_q[1]);

    // reg16_3.clk(clk);
    // reg16_3.reset(reset);
    // reg16_3.din(_d[2]);
    // reg16_3.dout(_q[2]);

    // reg16_4.clk(clk);
    // reg16_4.reset(reset);
    // reg16_4.din(_d[3]);
    // reg16_4.dout(_q[3]);
  
    reg16_1.enable(enable);
    reg16_1.rw(rw);
    reg16_1.clr(clr);

    reg16_2.enable(enable);
    reg16_2.rw(rw);
    reg16_2.clr(clr);

    reg16_1.addr(addr);
    reg16_1.addr(addr);

    reg16_2.addr(_index);
    reg16_2.addr(_index);

    // reg16_3.enable(enable);
    // reg16_3.rw(rw);
    // reg16_3.clr(clr);

    // reg16_4.enable(enable);
    // reg16_4.rw(rw);
    // reg16_4.clr(clr);

    // reg16_1.ready(ready_reg16_1);
    // reg16_2.ready(ready_reg16_2);
    // reg16_3.ready(ready_reg16_3);
    // reg16_4.ready(ready_reg16_4);
  }
};
