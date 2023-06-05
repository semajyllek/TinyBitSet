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


  library       | insertion  | removal  | membership | union    | intersection | pop min | pop max
  ---           | ---        |  ---     | ---        | ---      | ---          | ---     | ---     
  std\:\:set      | 0.086      | 0.037    | 0.057      | 4.8e-6   | 4.8e-5       | 8e.6    | 5.6e-6    
  tinybitset    | 0.005      | 0.0003   | 0.003      | 2.5e-7   | 2.5e-6       | 1.8e-6  | $${\color{lightblue}2.9e-7}$$       
  

  clues  | array mean | array min | array max | tbs mean | tbs min | tbs max | mp tbs mean | mp tbs min | mp tbs max 
  ---    | ---        |  ---      | ---       | ---      | ---     |  ---    | ---         | ---        | --- 
  9      | 0.02       | 7e-5      | 5.75      | 7e-3     | 1e-4    | 2.13    | $${\color{lightblue}4e-3}$$        | 5e-5       | 1.14 
  19     | 2e-3       | 5e-5      | 0.88      | 4e-3     | 7e-5    | 0.05    | $${\color{lightblue}2e-4}$$        | 4e-5       | 0.03
  29     | 9e-3       | 3e-5      | 7.96      | 3e-3     | 2e-6    | 2.96    | $${\color{lightblue}2e-3}$$        | 2e-6       | 1.63 
  39     | 5e-3       | 2e-5      | 0.22      | 8e-5     | 1e-6    | 0.07    | $${\color{lightblue}4e-5}$$        | 0          | 0.04
  49     | 4e-5       | 2e-5      | 3e-4      | 3e-6     | 1e-6    | 6e-5    | $${\color{lightblue}2e-6}$$        | 0          | 4e-5
  59     | 2e-5       | 1e-5      | 8e-5      | $${\color{lightblue}1e-6}$$   | 1e-6    | 9e-6    | $${\color{lightblue}1e-6}$$        | 0          | 8e-6
  69     | 1e-5       | 7e-6      | 4e-5      | 1e-6     | 1e-6    | 3e-6    | $${\color{lightblue}8e-7}$$        | 0          | 2e-6
  79     | 8e-6       | 2e-6      | 2e-5      | 1e-6     | 1e-6    | 7e-6    | $${\color{lightblue}8e-7}$$        | 0          | 3e-6 

