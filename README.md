# QuarkBurst

[![QuarkBurst](quarkburst.jpg)](https://github.com/eightomic/quarkburst)

QuarkBurst (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast efficient stateful PRNG (non-cryptographic) that has a period of at least 2⁶⁴ (from a Weyl sequence), excellent statistical randomness quality test results (single-instance bitstreams passed Dieharder 3.31.1 `dieharder -Y 1 -a -g 200 -k 2`, NIST STS 2.1.2 100-bitstream `assess 1000000`, PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 32TB` and TestU01 1.2.3 BigCrush), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, reversibility (state rewinding) and ultra-fast speed (relative to the aforementioned constraints).

Each mention of QuarkBurst refers to each of the following 8 variants individually (`quarkburst32x1`, `quarkburst32x2`, `quarkburst32x4`, `quarkburst32x8`, `quarkburst64x1`, `quarkburst64x2`, `quarkburst64x4`, `quarkburst64x8`) implemented in C (requiring the `stdint.h` header to define unsigned integral types for both a 32-bit `uint32_t` and a 64-bit `uint64_t`).

[quarkburst.c](quarkburst.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of generating 100 million pseudorandom output integers (`uint32_t` for `quarkburst32` variants and `uint64_t` for `quarkburst64` variants) in a blocking loop.

The `quarkburst64x1` function modifies the state in a `struct quarkburst64x1_state` instance to generate a deterministic pseudorandom `uint64_t` integer (assigned to the `c` state variable). Each state variable (`a`, `b` and `c`) in a `struct quarkburst64x1_state` instance must be seeded before generating a deterministic `quarkburst64x1` bitstream (that must discard the first 3 `quarkburst64x1` results at least).

```
                             Elapsed   Mixing/Output/State Bits

quarkburst64x1               799ms     192
biski64                      944ms     384
xoshiro256_plus              979ms     384
xoroshiro128_plus            1009ms    320
jsf64_2rotate                1016ms    320
sfc64                        1052ms    384
jsf64_3rotate                1060ms    320
pcg_oneseq_64_rxs_m_xs_64    1224ms    192
pcg64_dxsm                   2060ms    384
pcg_oneseq_64_xsl_rr_rr_64   2726ms    256
```

The `quarkburst64x2` function modifies the state in a `struct quarkburst64x2_state` instance to generate 2 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b` and `c`) in a `struct quarkburst64x2_state` instance must be seeded before generating a deterministic `quarkburst64x2` bitstream (that must discard the first 3 `quarkburst64x2` results at least).

```
                         Elapsed   Mixing/Output/State Bits

quarkburst64x2           544ms     320
aesdec2 (-maes -msse2)   637ms     512
aesdec2 (-maes -msse3)   645ms     512
aesdec2 (-maes -msse4)   677ms     512
```

The `quarkburst64x4` function modifies the state in a `struct quarkburst64x4_state` instance to generate 4 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst64x4_state` instance must be seeded before generating a deterministic `quarkburst64x4` bitstream (that must discard the first 4 `quarkburst64x4` results at least).

```
                             Elapsed   Mixing/Output/State Bits

quarkburst64x4               450ms     512
shishua_half_sse4 (-msse4)   1491ms    2688
shishua_half_sse2 (-msse2)   1666ms    2688
shishua_half_sse3 (-msse3)   1675ms    2688
shishua_half_avx2 (-mavx2)   2170ms    4864
shishua_half                 2504ms    1984
```

The `quarkburst64x8` function modifies the state in a `struct quarkburst64x8_state` instance to generate 8 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst64x8_state` instance must be seeded before generating a deterministic `quarkburst64x8` bitstream (that must discard the first 4 `quarkburst64x8` results at least).

```
                        Elapsed   Mixing/Output/State Bits

quarkburst64x8          310ms     768
shishua_avx2 (-mavx2)   824ms     7424
shishua_sse4 (-msse4)   825ms     3840
shishua_sse3 (-msse3)   919ms     3840
shishua_sse2 (-msse2)   923ms     3840
shishua                 1483ms    3456
```

`quarkburst32x1`, `quarkburst32x2`, `quarkburst32x4` and `quarkburst32x8` aren't ready to publish yet.
