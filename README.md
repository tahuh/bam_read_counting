# bam_read_counting
Count up the reads in BAM file

## Requirements
Compiler
- gcc >= 4.8.4

OS
- Ubuntu 18.04

Libraries
htslib (must be installed system-wide) >= 1.10
pysam (for python users)

## Installation
C code can be compiled with command below
`$ gcc -g -O2 -o bamReadCounter main.c -lhts`

Python code can be directly used as running script

## Usage

C - code
`$ bamReadCounter in.bam`

Python - code
`$ bamReadCounter.py in.bam`

## LICENSE
MIT
