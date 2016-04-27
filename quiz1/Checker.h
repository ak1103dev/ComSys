//------------------------------------------------------------------
// 4-bits adder checker module
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#ifndef CHECK_H
#define CHECK_H

#include <systemc.h>
#include <stdlib.h>

#include <iostream>

#define n 256
using namespace std;       
                                
SC_MODULE(check) {
    sc_in<bool> clk;
    sc_in<sc_uint<8> > AVG;
	sc_out<sc_uint<16> > TCV;

	sc_uint<8> a[n];
	sc_uint<16> count;

	void ps0() {
		FILE * fp;
		char * line = NULL;
		size_t len = 0;
		ssize_t read;

		int i = -1;

		fp = fopen("./data1024.result.txt", "r");
		if (fp == NULL)
		exit(EXIT_FAILURE);

		while ((read = getline(&line, &len, fp)) != -1) {
			if(i > -1)
				a[i] = atoi(line);
			//printf("%s", line);
			i++;
		}

		fclose(fp);
		if (line)
			free(line);
//		exit(EXIT_SUCCESS);
	}

    void pc1() {    
		count = 0;

		wait();

		for(int i = 0; i < n; i++) {
			if(a[i] == AVG) {
				count++;
			}
			wait();
		}
		cout << "count: " << count << endl;
		TCV.write(count);
    }

    SC_CTOR(check) {     
        SC_THREAD(pc1);                     
        sensitive << clk.pos();
        dont_initialize();
    }
};
#endif

