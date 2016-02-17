#include <systemc.h>

SC_MODULE(one_comp) {
    sc_in<sc_int<32> > in;
    sc_in<bool> x;
    sc_out<sc_int<32> > out;

    SC_CTOR(one_comp) {
        SC_METHOD(process);
        sensitive << in << x;
    }

    void process () {
        sc_int<32> b;
        b = in.read();
        for (int i=0; i<32; i++) {
            b[i] = b[i] ^ x;
        }
        out.write(b);
    }
};
