#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int a[1000000001];

unsigned long long  sum_array (int array[], unsigned long len)
{
    int i;
    unsigned long long value=0;
    for (i=1; i <= len; i++)
     value += array[i];

    return value;

}

void read_file(char *argv[]) {
	int i = 0;
	fstream myfile(argv[1], std::ios_base::in);
	//fstream myfile("./example.txt", std::ios_base::in);
	while (myfile >> a[i++]);
}

int main (int argc, char *argv[])
{

	time_t start, finish;
    // read number file from argv[1]

    // the first line of the file is array "len".

    // don't forget to check error missing argv[1]
	cout << "ARGC: " << argc << endl;
	if (argc < 2) {
		return 0;
	}

    // allocate array "array" of len
    // read file line by line; put to "array"
	read_file(argv);

    // start timer: time()
	start = time(NULL);
    // call sum_array(..)
	cout << "start sum" << endl;
	cout << "sum_array = " << sum_array(a, a[0]) << endl;

    // end timer: time()
	finish = time(NULL);

    // print time
	printf("time = %ld\n", finish - start);
	return 0;

}
