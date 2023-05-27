## TinyBitSet

- tiny c++ library for fast operations on tiny sets of the integers between 1 and largest int size, (1-64)
- instantiating, or calling any of the operations o a TinyBitSet with  (64 < n < 0) will throw a runtime error

```

#include "tinybitset.h"
#include <vector>

TinyBitSet<32> t;
int tsize = t.getSetSize();                   // 0
int maxElems = t.getMaxElements();            // 32
t.insert(5);
t.insert(22);
tsize = t.getSetSize();                       // 2 
std::vector<int> = t.getIntegerElements();    // std::vector<int>({5, 22})
t.remove(22);
bool test = t.contains(5);                    // true
tsize = t.getSetSize();                       // 1
TinyBitSet<65> t;                             // throws size error

TinyBitSet<9> t1;
t1.insert(5);
t1.insert(7);

TinyBitSet<9> t2;
t2.insert(3);
t2.insert(5);

TinyBitSet<9> tinter = t1.intersectionb(t2);  // size 1
TinyBitSet<9> tunion = t1.unionb(t2);         // size 3

```