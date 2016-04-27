//------------------------------------------------------------------
// Simple 4-bits adder
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef STIM_H
#define STIM_H

#include <systemc.h>
#include <stdlib.h>

#include <iostream>

#define N 32
                                
SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_uint<8> > A0, A1, A2, A3;

	sc_uint<8> a[1024];

	void ps0() {
		//wait();

		FILE * fp;
		char * line = NULL;
		size_t len = 0;
		ssize_t read;

		int i = -1;

		fp = fopen("./data1024.txt", "r");
		if (fp == NULL)
		exit(EXIT_FAILURE);

		while ((read = getline(&line, &len, fp)) != -1) {
			if(i > -1) {
				a[i] = atoi(line);
				//cout << a[i] << endl;
			}
			i++;
		}

		fclose(fp);
		if (line)
			free(line);
	}

    void ps1() {    
		wait();
		sc_uint<16> i;
		for(i = 0; i < 1024; i+=4) {
			A0.write(a[i]);
			A1.write(a[i+1]);
			A2.write(a[i+2]);
			A3.write(a[i+3]);
		//	cout << i << endl;
			wait();
		}

        sc_stop();                          // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps0);                     // Run ps1 only ones
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif

