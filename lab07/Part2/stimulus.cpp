#include "RegisterFile.h"
//#include "reg32.h"
#define L 32

SC_MODULE(show) {
	SC_CTOR(show) {

	}
	void print(bool clk, sc_uint<L> din, sc_uint<L> dout, bool enable, bool rw, bool clr, sc_uint<5> addr) {
		cout << "clk: " << clk << endl;
		cout << "clear: " << clr << endl;
		cout << "enable: " << enable << endl;
		if(rw) {
			cout << "write " << din << " at reg" << addr << endl;
		} else {
			cout << "read " << dout << " at reg" << addr << endl;
		}
		cout << endl;
	}
};

int sc_main(int argc, char* argv[]) {

    sc_signal<sc_uint<L> > din, dout;
    sc_signal<bool> enable, rw, clr;
	sc_signal<sc_uint<5> > addr;

    sc_clock clk("clk",50,SC_NS);

    register_file DUT("reg");
    DUT.clk(clk);
    DUT.din(din);
    DUT.dout(dout);
    DUT.enable(enable);
    DUT.clear(clr);
    DUT.rw(rw);
	DUT.addr(addr);

    sc_trace_file *fp;
    fp=sc_create_vcd_trace_file("wave");
    sc_trace(fp,clk,"clk");
    sc_trace(fp,din,"din");
    sc_trace(fp,dout,"dout");
    sc_trace(fp,enable,"enable");
    sc_trace(fp,clr,"clr");
    sc_trace(fp,rw,"rw");
    sc_trace(fp,addr,"addr");

	show show("show");

	clr = 0;
  	sc_start(50, SC_NS);

	clr = 1;
  	sc_start(50, SC_NS);

	//enable=1; rw=1; din=3;
  	//sc_start(100, SC_NS);
	//show.print(clk, din, dout, enable, rw, clr);

	enable=1; rw=1; addr=5; din=3;
  	sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

	enable=1; rw=0;
  	sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

	enable=0; rw=1; din=1;
  	sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

	enable=1; rw=0;
  	sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

	enable=1; rw=1; din=15;
  	sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

	enable=1; rw=0;
    sc_start(100, SC_NS);
	show.print(clk, din, dout, enable, rw, clr, addr);

    sc_close_vcd_trace_file(fp);
    return 0;
}
