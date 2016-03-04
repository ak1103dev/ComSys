#include <systemc.h>
#include "bit.h"

SC_MODULE(division) {
    sc_in<sc_uint<N> > D, V;
    sc_out<sc_uint<N> > Q, R;

	sc_uint<N> RA, RQ, RM;
	sc_uint<1> RS;

    void p1() {
		int count;
		RQ = D.read();
		RM = V.read();
		RA = 0;
		RS = 0;
		for(count = 0; count < N; count++) {
			if(RS) {
				(RA, RQ) = (RA, RQ) << 1;
				(RS, RA) = (RS, RA) + RM;
			} else {
				(RA, RQ) = (RA, RQ) << 1;
				(RS, RA) = (RS, RA) - RM;
			}
			if(RS) {
				RQ[0] = 0;
			} else {
				RQ[0] = 1;
			}
		}
		if(RS) {
			(RS, RA) = (RS, RA) + RM;
		}
		Q.write(RQ);
		R.write(RA);
    }

    SC_CTOR(division) {
        SC_METHOD(p1);
        sensitive << D << V;
    }
};
