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



#### std::unordered_set comparison times, N=1000000 operations, 64 element sized sets:


                | insertion  | removal  | membership | union    | intersection | pop min | pop max
  ---           | ---       |  ---    | ---       | ---     | ---         | ---    | ---     
  std::set      | 0.086      | 0.037    | 0.057      | 4.8e-6   | 4.8e-5       | 8e.6    | 5.6e-6    
  tinybitset    | 0.005      | 0.0003   | 0.003      | 2.5e-7   | 2.5e-6       | 1.8e-6  | $${\color{lightblue}2.9e-7}$$       
  

