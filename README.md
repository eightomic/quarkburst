# QuarkBurst

[![QuarkBurst](quarkburst.jpg)](https://github.com/eightomic/quarkburst)

QuarkBurst is the fast constrained 64-bit PRNG (non-cryptographic) that has a period of at least 2⁶⁴, excellent statistical randomness quality test results (single-instance bitstreams passed Dieharder 3.31.1 `dieharder -Y 1 -a -g 200 -k 2`, NIST STS 2.1.2 `assess 1000000` with 100 bitstreams, PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 32TB -te 0 -tf 1` and TestU01 1.2.3 BigCrush), an [open-source license](LICENSE), low-footprint implementation (efficient memory usage and small code size), no comparison/division/modulus/multiplication operators, reversibility (state rewinding), ultra-fast speed (relative to the aforementioned constraints) and up to 2⁶⁴ distinct parallel bitstreams (each with possible subtle cross-bitstream statistical correlations) that each have non-probabilistic full-state overlap avoidance with each other for a period of at least 2⁶⁴ (when each `a` state variable is seeded with a thread ID integer and the remaining single-letter state variables are seeded with `0`).

Each mention of QuarkBurst refers to each of the 4 following variants individually (`quarkburst1x64`, `quarkburst2x64`, `quarkburst4x64` and `quarkburst8x64`) implemented in C (requiring the `stdint.h` header to define an unsigned integral type for a 64-bit `uint64_t`).

[quarkburst.c](quarkburst.c)

The `quarkburst1x64` function modifies the state in a `struct quarkburst1x64_state` instance to generate a deterministic pseudorandom `uint64_t` integer as the return value. Each state variable (`a`, `b` and `c`) in a `struct quarkburst1x64_state` instance must be seeded before generating a deterministic `quarkburst1x64` bitstream (that must discard the first 3 `quarkburst1x64` results as a state warmup).

The `quarkburst2x64` function modifies the state in a `struct quarkburst2x64_state` instance to generate 2 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b` and `c`) in a `struct quarkburst2x64_state` instance must be seeded before generating a deterministic `quarkburst2x64` bitstream (that must discard the first 3 `quarkburst2x64` results as a state warmup).

The `quarkburst4x64` function modifies the state in a `struct quarkburst4x64_state` instance to generate 4 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst4x64_state` instance must be seeded before generating a deterministic `quarkburst4x64` bitstream (that must discard the first 4 `quarkburst4x64` results as a state warmup).

The `quarkburst8x64` function modifies the state in a `struct quarkburst8x64_state` instance to generate 8 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst8x64_state` instance must be seeded before generating a deterministic `quarkburst8x64` bitstream (that must discard the first 5 `quarkburst8x64` results as a state warmup).

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (with `gcc -O3` from an AMD A4-9120C) that generates 1 billion pseudorandom `uint64_t` integers in a blocking `#pragma GCC unroll 0` loop.

```
                                    Elapsed

quarkburst8x64                      545ms
quarkburst4x64                      561ms
quarkburst2x64                      743ms
shishua_avx2* (-mavx2)              866ms
aesdec2** (-maes -msse4)            905ms
shishua_sse4** (-msse4)             978ms
quarkburst1x64                      1072ms
shishua_sse3** (-msse3)             1147ms
shishua_sse2** (-msse2)             1154ms
biski64                             1292ms
sfc64                               1320ms
xoshiro128_plus*                    1541ms
xoshiro256_plus                     1546ms
xorshiftr128_plus                   1654ms
jsf64_2rotate                       1718ms
xoroshiro128_plus                   1733ms
xoshiro128_plusplus*                1740ms
xoroshiro64_star*                   1749ms
xoshiro128_starstar*                1759ms
mrsf64                              1833ms
jsf64_3rotate                       1841ms
mrc64                               1862ms
romu_trio                           1894ms
wob2m                               1928ms
xoshiro64_starstar                  1945ms
mwc192                              1997ms
wyrand                              2033ms
xorshift64                          2135ms
shishua                             2251ms
xorshift128_plus                    2260ms
xorwow*                             2882ms
romu_mono                           2982ms
pcg32_minimal*                      2983ms
pcg_64_xsh_rr_32*                   2987ms
mwc128                              2998ms
lehmer_mcg32*                       3402ms
pcg_64_xsh_rs_32*                   3404ms
lcg32*                              3409ms
lehmer_mcg64                        3413ms
lcg64                               3416ms
threefry4x32*                       3532ms
philox4x32*                         3626ms
aes_ni_ctr_128** (-maes -msse4)     3796ms
pcg_64_xsl_rr_rr_64                 3928ms
isaac*                              4099ms
splitmix64                          4385ms
cwg64                               4680ms
cwg128                              4757ms
threefry2x32*                       4959ms
philox2x32*                         5139ms
sfmt** (-msse2)                     5525ms
lxm_xbg128                          5863ms
wanghash64                          5983ms
pcg_128_xsh_rr_64                   6833ms
threefry4x64                        7093ms
mt19937_64                          7126ms
squares32*                          7552ms
pcg64_dxsm                          7604ms
pcg_128_xsh_rs_64                   7676ms
philox4x64                          9171ms
google_randen***** (-maes -msse4)   9206ms
squares64                           9596ms
threefry2x64                        9907ms
philox2x64                          10622ms
*chacha8                            13230ms
tinymt64                            16081ms
mrg32k3a****                        19356ms
chacha20*                           26402ms
rand* (stdlib.h)                    46083ms

* Each n-bit output integer was casted to a uint64_t integer.

** Each 128-bit output integer was extracted as 2 uint64_t integers.

*** Each 256-bit output integer was extracted as 4 uint64_t integers.

**** Each output integer was returned as a uint64_t integer instead of a double.

***** Each block of 4 uint8_t output integers were merged into a uint32_t
      integer that was casted to a uint64_t integer.
```
