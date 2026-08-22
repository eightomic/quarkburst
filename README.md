# LeptonFlurry

[![LeptonFlurry](leptonflurry.jpg)](https://github.com/eightomic/leptonflurry)

## Table of Contents

- [Introduction](README.md?tab=readme-ov-file#introduction)
- [Author](README.md?tab=readme-ov-file#author)
- [License](README.md?tab=readme-ov-file#license)
- [Implementation](README.md?tab=readme-ov-file#implementation)
- [Quality](README.md?tab=readme-ov-file#quality)
- [Speed](README.md?tab=readme-ov-file#speed)

## Introduction

LeptonFlurry is the ultra-efficient counter-based PRNG (non-cryptographic for scientific simulations) that has GPU-friendly 32-bit integers, arbitrary jumps (counter-based index jumps), excellent statistical randomness quality test results, low-footprint implementation (efficient memory usage and small code size), massive parallelism (up to 2⁶⁴ key-based independent streams that each have a counter-based period of 2⁶⁴), no division/modulus/multiplication operators and ultra-fast speed.

## Author

LeptonFlurry was created by William Stafford Parsons as a product of [Eightomic](https://eightomic.com).

## License

LeptonFlurry is licensed with [BSD-3-Clause](LICENSE).

## Implementation

Each mention of LeptonFlurry refers to each of the 4 following variants individually (`leptonflurry1x32`, `leptonflurry2x32`, `leptonflurry4x32` and `leptonflurry8x32`) implemented in C (requiring the `stdint.h` header to define a 32-bit, unsigned integral type for `uint32_t`).

[leptonflurry.c](leptonflurry.c)

#### `leptonflurry1x32`

The `leptonflurry1x32` function generates (from 2 `uint32_t` `counter` integers that must be seeded and 2 `uint32_t` `key` integers that must be seeded) a deterministic pseudorandom `uint32_t` integer as the return value.

#### `leptonflurry2x32`

`leptonflurry2x32` isn't ready to publish yet.

#### `leptonflurry4x32`

`leptonflurry4x32` isn't ready to publish yet.

#### `leptonflurry8x32`

`leptonflurry8x32` isn't ready to publish yet.

## Quality

LeptonFlurry yielded the following excellent results (from a stream that permutes through 2 `uint32_t` `counter` integers with 2 fixed `uint32_t` `key` integers) from statistical randomness quality tests.

#### Dieharder 3.31.1

LeptonFlurry passed `dieharder -Y 1 -a -g 200 -k 2` (each ambiguous result resolved to a `PASSED` result).

#### NIST STS 2.1.2

LeptonFlurry passed `assess 1000000` (using 100 bitstreams).

#### PractRand 0.96

LeptonFlurry passed `RNG_test stdin -tlmin 1KB -tlmax 32TB`.

#### SmokeRand 0.47

LeptonFlurry passed `smokerand full stdin32` (4/4 quality score).

#### TestU01 1.2.3

LeptonFlurry passed BigCrush.

## Speed

Each of the following results log the fastest process execution speed (in milliseconds) among several repetitions of a speed benchmark (using `gcc -O3` from an AMD A4-9120C) that generates 1 billion pseudorandom `uint32_t` integers in a blocking `#pragma GCC unroll 0` loop.

| Counter-Based PRNG | Elapsed |
| --- | --- |
| **`leptonflurry8x32`** | **?ms** |
| **`leptonflurry4x32`** | **?ms** |
| **`leptonflurry2x32`** | **?ms** |
| **`leptonflurry1x32`** | **2527ms** |
| `threefry4x32` | 3532ms |
| `philox4x32` | 3626ms |
| `threefry2x32` | 4959ms |
| `philox2x32` | 5139ms |
| `squares32` | 7552ms |
| `chacha8_ctr` | 13230ms |
| `chacha20_ctr` | 26402ms |
