#include <systemc.h>

SC_MODULE(zeroflag) {
    sc_in<sc_int<32> > in;
    sc_out<bool> out;

    SC_CTOR(zeroflag) {
        SC_METHOD(zero_process);
        sensitive << in;
    }

    void zero_process() {
        bool ans = false;
        sc_int<32> a;
        a = in.read();
        for (int i=0; i<32; i++) {
            ans = ans | a[i];
        }
        out.write(!ans);
    }
};


SC_MODULE(overflag) {
    sc_in<sc_int<32> > ain, bin, sum;
    sc_out<bool> out;

    SC_CTOR(overflag) {
        SC_METHOD(overflow_process);
        sensitive << ain << bin << sum;
    }

    bool checkoverflow (bool a, bool b, bool s) {
        return (a&b&!s) | (!a&!b&s);
    }

    void overflow_process() {
        sc_int<32> a, b, s;
        a = ain.read();
        b = bin.read();
        s = sum.read();
        out.write(checkoverflow(a[31], b[31], s[31]));
    }
};