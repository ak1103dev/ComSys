# Comsys-lab10
## How to use ?
### Check Result
check sort correct
```bash
python checker_sort.py mergesort.cpp
```

### Change Value
change value (N, MAX, MIN) in mergesort.cpp
```cpp
#define N 65536
#define MAX 255
#define MIN 0
```

## How to use "cache-sim" command line ?

For cache size: 32KB, line size: 128B, associativity: 8 ways, tracefile name: "log" <br>
You can run

```bash
$./cache-sim log 32 128 8
```
and this command use for execute file name: "sort" and tool name: "dcache.so" <br>
run in path: "/pin-3.0-76991-gcc-linux/source/tools/SimpleExamples"
