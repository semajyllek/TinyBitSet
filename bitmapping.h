
// this is just a file of silly precalculations so these don't have to be computed at runtime,
// to be used by tinybitset.h
// all bit operations are done at compile time, so they are in this form for readability


/*


bit mapping, mapping of the bit that represents the number, 
and 0 for all the bits that are not the bit that represents the number:


if n == 32
1 -> 00000000000000000000000000000000001
2 -> 00000000000000000000000000000000010
3 -> 00000000000000000000000000000000100
4 -> 00000000000000000000000000000001000
...
32 -> 10000000000000000000000000000000000

*/

#include <cstdint>


uint_fast8_t BIT8_MAP[8] {
	1, 
	1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7
};


uint_fast16_t BIT16_MAP[16] {
	1, 
	1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10,
	1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15
};


uint_fast32_t BIT32_MAP[32] {
	1, 
	1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10,
	1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 
	1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 
	1 << 31									   
};




uint_fast64_t BIT64_MAP[64] {
	1, 
	1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10,
	1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 
	1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 
	1 << 31, 1 << 32, 1 << 33, 1 << 34, 1 << 35, 1 << 36, 1 << 37, 1 << 38, 1 << 39, 1 << 40, 
	1 << 41, 1 << 42, 1 << 43, 1 << 44, 1 << 45, 1 << 46, 1 << 47, 1 << 48, 1 << 49, 1 << 50, 
	1 << 51, 1 << 52, 1 << 53, 1 << 54, 1 << 55, 1 << 56, 1 << 57, 1 << 58, 1 << 59, 1 << 60, 
	1 << 61, 1 << 62, 1 << 63											   
};


template <int NumBits>
struct BitMap {
    static constexpr uint_fast8_t* BIT_MASK = nullptr;
};

template <>
struct BitMap<8> {
    static constexpr uint_fast8_t* BIT_MAP = BIT8_MAP;
};

template <>
struct BitMap<16> {
    static constexpr uint_fast16_t* BIT_MAP = BIT16_MAP;
};

template <>
struct BitMap<32> {
    static constexpr uint_fast32_t* BIT_MAP = BIT32_MAP;
};

template <>
struct BitMap<64> {
    static constexpr uint_fast64_t* BIT_MAP = BIT64_MAP;
};





/*


mask mapping, mapping of all the bits that are not the bit that represents the number, 
and 0 for the bit that represents the number

if n == 32
1 -> 11111111111111111111111111111111110
2 -> 11111111111111111111111111111111101
3 -> 11111111111111111111111111111111011
...

32 -> 01111111111111111111111111111111111

*/ 


uint_fast8_t MASK8_MAP[8] = {
	~1, 
	~(1 << 1), ~(1 << 2), ~(1 << 3), ~(1 << 4), ~(1 << 5), ~(1 << 6), ~(1 << 7)
};


uint_fast16_t MASK16_MAP[16] = {
	~1, 
	~(1 << 1), ~(1 << 2), ~(1 << 3), ~(1 << 4), ~(1 << 5), ~(1 << 6), ~(1 << 7), ~(1 << 8), ~(1 << 9), ~(1 << 10),
	~(1 << 11), ~(1 << 12), ~(1 << 13), ~(1 << 14), ~(1 << 15)
};


uint_fast32_t MASK32_MAP[32] = {
	~1, 
	~(1 << 1), ~(1 << 2), ~(1 << 3), ~(1 << 4), ~(1 << 5), ~(1 << 6), ~(1 << 7), ~(1 << 8), ~(1 << 9), ~(1 << 10),
	~(1 << 11), ~(1 << 12), ~(1 << 13), ~(1 << 14), ~(1 << 15), ~(1 << 16), ~(1 << 17), ~(1 << 18), ~(1 << 19), ~(1 << 20), 
	~(1 << 21), ~(1 << 22), ~(1 << 23), ~(1 << 24), ~(1 << 25), ~(1 << 26), ~(1 << 27), ~(1 << 28), ~(1 << 29), ~(1 << 30), 
	~(1 << 31)									   
};


uint_fast64_t MASK64_MAP[64] = {
	~1, 
	~(1 << 1), ~(1 << 2), ~(1 << 3), ~(1 << 4), ~(1 << 5), ~(1 << 6), ~(1 << 7), ~(1 << 8), ~(1 << 9), ~(1 << 10),
	~(1 << 11), ~(1 << 12), ~(1 << 13), ~(1 << 14), ~(1 << 15), ~(1 << 16), ~(1 << 17), ~(1 << 18), ~(1 << 19), ~(1 << 20), 
	~(1 << 21), ~(1 << 22), ~(1 << 23), ~(1 << 24), ~(1 << 25), ~(1 << 26), ~(1 << 27), ~(1 << 28), ~(1 << 29), ~(1 << 30), 
	~(1 << 31), ~(1 << 32), ~(1 << 33), ~(1 << 34), ~(1 << 35), ~(1 << 36), ~(1 << 37), ~(1 << 38), ~(1 << 39), ~(1 << 40), 
	~(1 << 41), ~(1 << 42), ~(1 << 43), ~(1 << 44), ~(1 << 45), ~(1 << 46), ~(1 << 47), ~(1 << 48), ~(1 << 49), ~(1 << 50), 
	~(1 << 51), ~(1 << 52), ~(1 << 53), ~(1 << 54), ~(1 << 55), ~(1 << 56), ~(1 << 57), ~(1 << 58), ~(1 << 59), ~(1 << 60), 
	~(1 << 61), ~(1 << 62), ~(1 << 63)											   
};



template <int NumBits>
struct MaskMap {
    static constexpr uint_fast8_t* MASK_MAP = nullptr;
};

template <>
struct MaskMap<8> {
    static constexpr uint_fast8_t* MASK_MAP = MASK8_MAP;
};

template <>
struct MaskMap<16> {
    static constexpr uint_fast16_t* MASK_MAP = MASK16_MAP;
};

template <>
struct MaskMap<32> {
    static constexpr uint_fast32_t* MASK_MAP = MASK32_MAP;
};

template <>
struct MaskMap<64> {
    static constexpr uint_fast64_t* MASK_MAP = MASK64_MAP;
};





