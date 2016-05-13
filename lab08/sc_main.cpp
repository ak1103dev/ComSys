#include "reg32bit.h"
#include "check.h"
#include <systemc.h>
#define N_MO 32


sc_signal<sc_uint<32> > din[N_MO], dout[N_MO];
sc_signal<bool> reset, ready;
sc_signal<bool>  enable, rw, clr;
sc_signal<sc_uint<5> > addr;
sc_signal<sc_uint<5> > _index[N_MO];

sc_clock clk("clk",10,SC_NS);       // Create a 10ns period clock signal

int sc_main(int argc, char* argv[]) {

    reg32* R[N_MO];
    check* C[N_MO];

    for (int i = 0; i < N_MO; i++) {
        char name_reg[100] = "reg_";
        name_reg[4] = (char)(i/10 + '0');
        name_reg[5] = (char)(i%10 + '0') ;

        R[i] = new reg32(name_reg);
        R[i] -> clk(clk);
        R[i] -> reset(reset);
        R[i] -> din(din[i]);
        R[i] -> dout(dout[i]);
        R[i] -> enable(enable);
        R[i] -> rw(rw);
        R[i] -> clr(clr);

        R[i] -> _index(_index[i]);
        R[i] -> addr(addr);


        char name_check[100] = "check_";
        name_check[6] = (char)(i/10 + '0');
        name_check[7] = (char)(i%10 + '0') ;

        C[i] = new check(name_check);
        C[i] -> clk(clk);
        C[i] -> din(din[i]);
        C[i] -> dout(dout[i]);
        C[i] -> enable(enable);
        C[i] -> rw(rw);
        C[i] -> clr(clr);

        C[i] -> _index(_index[i]);
        C[i] -> addr(addr);
    }

    sc_trace_file *fp;                  // VCD filepointer
    fp=sc_create_vcd_trace_file("wave");// Create wave.vcd file
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,rw,"rw");
    sc_trace(fp,clr,"clr");
    for (int i = 0; i < N_MO; i++) {
        if (i == 5 || i == 7 || i == 1) {
            char name_din[100] = "din_";
            name_din[4] = (char)(i/10 + '0');
            name_din[5] = (char)(i%10 + '0') ;

            char name_dout[100] = "dout_";
            name_dout[5] = (char)(i/10 + '0');
            name_dout[6] = (char)(i%10 + '0') ;

            sc_trace(fp,din[i],name_din);
            sc_trace(fp,dout[i],name_dout);
        }
    }
    sc_trace(fp,enable,"enable");

    sc_start(SC_ZERO_TIME);
    for (int i = 0; i < N_MO; i++) {
        _index[i] = i;
    }
    sc_start(100, SC_NS);

    enable =0, rw=1, addr = 1, din[1] = 27, clr=1;
    sc_start(100 , SC_NS);
    enable =1;
    sc_start(100 , SC_NS);
    rw=0, addr = 1, din[1] = 27;
    sc_start(100 , SC_NS);

    // enable =0,rw=1, addr = 0, din[addr.read()] = 25, clr=1;
    // sc_start(100 , SC_NS);
    // enable=1;
    // sc_start(100, SC_NS);
    // rw =0;
    // sc_start(100 , SC_NS);

    enable =0, rw=1;
    sc_start(100 , SC_NS);
    enable=1 , addr = 7, din[7] = 25;
    sc_start(100 , SC_NS);
    rw=0;
    sc_start(100 , SC_NS);


    enable =0, rw=1;
    sc_start(100 , SC_NS);
    enable=1 , addr = 5, din[5] = 3;
    sc_start(100 , SC_NS);
    rw=0;
    sc_start(100 , SC_NS);

    sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}                                       // no ;
