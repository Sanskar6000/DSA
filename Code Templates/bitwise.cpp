//Some properties of bitwise operations:
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b
//Addition:
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)
//Subtraction:
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))

class bitwise {
    __builtin_popcount(100011); -> count number of 1
    __builtin_popcountll(100011); -> count number of 1s' when input value is in long long
    __builtin_ctz(00110) -> number of trailing zeroes (crash for zero)
    __builtin_ctzll(00110) -> number of trailing zeroes (crash for zero)
    __builtin_clz(01000) -> number of leading  zeroes (crash for zero)
    __builtin_clzll(01000) -> number of leading  zeroes (crash for zero)
};

Tricks:
Number of bits: 32 - __builtin_clz(01000)
mod2 => &1
mod2^5 = mod32 => &31

mod2^x => &(2^x - 1)

a + b = (a^b) + 2(a&b)