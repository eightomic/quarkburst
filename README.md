# QuarkBurst

[![QuarkBurst](quarkburst.jpg)](https://github.com/eightomic/quarkburst)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)

## Introduction

QuarkBurst is the efficient non-cryptographic stateful PRNG that has a period of at least 2⁶⁴ (from a Weyl sequence), excellent statistical randomness quality test results, low-footprint implementation (efficient memory usage and small code size), no division/modulus/multiplication operators, reversibility (state rewinding), ultra-fast speed and up to 2⁶⁴ distinct (non-independent) parallel QuarkBurst bitstreams that each have non-probabilistic full-state overlap avoidance with each other for a period of at least 2⁶⁴ (when each `a` state variable is seeded with a thread ID integer and the remaining single-letter state variables are seeded with `0`).

QuarkBurst single-instance bitstreams passed Dieharder 3.31.1 `dieharder -Y 1 -a -g 200 -k 2` (each ambiguous result resolved to a `PASSED` result), NIST STS 2.1.2 `assess 1000000`, PractRand 0.96 `RNG_test stdin -tlmin 1KB -tlmax 32TB` and TestU01 1.2.3 BigCrush.

[LeptonFlurry](https://github.com/eightomic/leptonflurry) is the alternative counter-based PRNG solution when an application requires GPU-native 32-bit integers, a larger 2¹²⁸ period, index-based jumps or up to 2⁶⁴ independent parallel bitstreams.

## Author

QuarkBurst was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

QuarkBurst is licensed with [BSD-3-Clause](LICENSE).

## Implementation

Each mention of QuarkBurst refers to each of the 4 following variants individually (`quarkburst1x64`, `quarkburst2x64`, `quarkburst4x64` and `quarkburst8x64`) implemented in C (requiring the `stdint.h` header to define a 64-bit, unsigned integral type for `uint64_t`).

[quarkburst.c](quarkburst.c)

The `quarkburst1x64` function modifies the state in a `struct quarkburst1x64_state` instance to generate a deterministic pseudorandom `uint64_t` integer as the return value. Each state variable (`a`, `b` and `c`) in a `struct quarkburst1x64_state` instance must be seeded before generating a deterministic `quarkburst1x64` bitstream (that must discard the first 3 `quarkburst1x64` results as a state warmup).

The `quarkburst2x64` function modifies the state in a `struct quarkburst2x64_state` instance to generate 2 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b` and `c`) in a `struct quarkburst2x64_state` instance must be seeded before generating a deterministic `quarkburst2x64` bitstream (that must discard the first 3 `quarkburst2x64` results as a state warmup).

The `quarkburst4x64` function modifies the state in a `struct quarkburst4x64_state` instance to generate 4 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst4x64_state` instance must be seeded before generating a deterministic `quarkburst4x64` bitstream (that must discard the first 4 `quarkburst4x64` results as a state warmup).

The `quarkburst8x64` function modifies the state in a `struct quarkburst8x64_state` instance to generate 8 deterministic pseudorandom `uint64_t` integers in the `output` array. Each single-letter state variable (`a`, `b`, `c` and `d`) in a `struct quarkburst8x64_state` instance must be seeded before generating a deterministic `quarkburst8x64` bitstream (that must discard the first 5 `quarkburst8x64` results as a state warmup).
