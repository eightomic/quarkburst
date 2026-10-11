# QuarkBurst

[![QuarkBurst](quarkburst.jpg)](https://github.com/eightomic/quarkburst)

QuarkBurst (as a proprietary, source-available product of [Eightomic](https://eightomic.com)) is the fast efficient stateful PRNG (non-cryptographic) that has a period of at least 2⁶⁴ (from a Weyl sequence), excellent statistical randomness quality test results (single-instance bitstreams passed Dieharder 3.31.1 `dieharder -Y 1 -a -g 200 -k 2`, NIST STS 2.1.2 100-bitstream `assess 1000000` and PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 32TB`), low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, reversibility (state rewinding), ultra-fast speed (relative to the aforementioned constraints) and up to 2⁶⁴ distinct parallel bitstreams (each with possible subtle cross-bitstream statistical correlations) that each have non-probabilistic full-state overlap avoidance with each other for a period of at least 2⁶⁴ (when each `a` state variable is seeded with a thread ID integer and the remaining single-letter state variables are seeded with `0`).

Each mention of QuarkBurst refers to each of the following 8 variants individually (`quarkburst32x1`, `quarkburst32x2`, `quarkburst32x4`, `quarkburst32x8`, `quarkburst64x1`, `quarkburst64x2`, `quarkburst64x4`, `quarkburst64x8`) implemented in C (requiring the `stdint.h` header to define unsigned integral types for both a 32-bit `uint32_t` and a 64-bit `uint64_t`).

[quarkburst.c](quarkburst.c)

Each of the following speed benchmark results (with `gcc` from an AMD A4-9120C) log the fastest process execution speed (in milliseconds) among several repetitions of generating 100 million pseudorandom `uint64_t` integers in a blocking loop.

The `quarkburst64x1` function modifies the state in a `struct quarkburst64x1_state` instance to generate a deterministic pseudorandom `uint64_t` integer (assigned to the `c` state variable). Each state variable (`a`, `b` and `c`) in a `struct quarkburst64x1_state` instance must be seeded before generating a deterministic `quarkburst64x1` bitstream (that must discard the first 3 `quarkburst64x1` results as a state warmup).

```
                 Elapsed   Mixing/Output/State Bits

quarkburst64x1   799ms     192
biski64          944ms     384
sfc64            1052ms    384
```

The `quarkburst64x2` function modifies the state in a `struct quarkburst64x2_state` instance to generate 2 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b` and `c`) in a `struct quarkburst64x2_state` instance must be seeded before generating a deterministic `quarkburst64x2` bitstream (that must discard the first 3 `quarkburst64x2` results as a state warmup).

The `quarkburst64x4` function modifies the state in a `struct quarkburst64x4_state` instance to generate 4 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst64x4_state` instance must be seeded before generating a deterministic `quarkburst64x4` bitstream (that must discard the first 4 `quarkburst64x4` results as a state warmup).

The `quarkburst64x8` function modifies the state in a `struct quarkburst64x8_state` instance to generate 8 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst64x8_state` instance must be seeded before generating a deterministic `quarkburst64x8` bitstream (that must discard the first 5 `quarkburst64x8` results as a state warmup).

`quarkburst32x1`, `quarkburst32x2`, `quarkburst32x4` and `quarkburst32x8` aren't ready to publish yet.
