#include <systemc.h>

SC_MODULE(r32to4) {
    sc_in<sc_int<32> > in;
    sc_out<sc_int<4> > o0, o1, o2, o3, o4, o5, o6, o7;

    void process () {
        sc_int<32> i;
        i = in.read();
        o0.write(i(3,0));
        o1.write(i(7,4));
        o2.write(i(11,8));
        o3.write(i(15,12));
        o4.write(i(19,16));
        o5.write(i(23,20));
        o6.write(i(27,24));
        o7.write(i(31,28));
    }

    SC_CTOR(r32to4) {
        SC_METHOD(process);
        sensitive << in;
    }
};

SC_MODULE(r4to32) {
    sc_in<sc_int<4> > i0, i1, i2, i3, i4, i5, i6, i7;
    sc_out<sc_int<32> > out;

    void process () {
        sc_int<32> x;
        x(3,0) = i0;
        x(7,4) = i1;
        x(11,8) = i2;
        x(15,12) = i3;
        x(19,16) = i4;
        x(23,20) = i5;
        x(27,24) = i6;
        x(31,28) = i7;
        out.write(x);
    }

    SC_CTOR(r4to32) {
        SC_METHOD(process);
        sensitive << i0 << i1 << i2 << i3 << i4 << i5 << i6 << i7;
    }
};
