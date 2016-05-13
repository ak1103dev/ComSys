#ifndef MIPS_REG
#define MIPS_REG

#include "reg16bit.h"
#include "setting.h"
#include <systemc.h>

#include <iostream>
using namespace std;


SC_MODULE(mips_reg) {
    sc_in<bool> clk, enable, rw, clr, reset;
    sc_in<sc_uint<N_BIT_REG> > write_data;
    sc_out<sc_uint<N_BIT_REG> > src1_data, src2_data;
	sc_in<sc_uint<5> > src1_addr, src2_addr, dst_addr;
    ///sc_in<sc_uint<5> > addr;

    sc_signal<sc_uint<5> > _index[N_MODULE];
    sc_signal<sc_uint<N_BIT_REG> > _din[N_MODULE], _dout[N_MODULE];

    reg16* R[N_MODULE];


    void pc1() {
        //dout.write(_dout[addr.read()]);
        src1_data.write(_dout[src1_addr.read()]);
        src2_data.write(_dout[src2_addr.read()]);
    }

    SC_CTOR(mips_reg) {
        SC_METHOD(pc1);
        sensitive << clk.pos(); //enable << rw << clr << addr << reset << din;
        // SC_METHOD(pcInput);
        // sensitive << din;

        for (int i = 0; i < N_MODULE; i++) {
            char name_reg[100] = "reg_";
            name_reg[4] = (char)(i/10 + '0');
            name_reg[5] = (char)(i%10 + '0') ;

            R[i] = new reg16(name_reg);
            R[i] -> clk(clk);
            R[i] -> reset(reset);
            R[i] -> din(write_data);
            R[i] -> dout(_dout[i]);
            R[i] -> enable(enable);
            R[i] -> rw(rw);
            R[i] -> clr(clr);

            R[i] -> _index(_index[i]);
            R[i] -> addr(dst_addr);
        }

        for (int i = 0; i < N_MODULE; i++) {
            _index[i] = i;
        }
    }



};
#endif
