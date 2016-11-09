#!/usr/bin/env bash
set -exuo pipefail

# 1. frist compile to generate the fst
g++ -std=c++11 -L/Users/songmeixu/code/openfst/lib -lfst -o num_written_to_spoken num_written_to_spoken.cpp
./num_written_to_spoken
## show transfer fst in pdf
fstdraw -portrait num_written_to_spoken.fst | dot -Tpdf >num_written_to_spoken.pdf

# 2. then test
## compile the example
fstcompile --isymbols=numbers.syms --osymbols=numbers.syms < written.fst.txt > written.fst
## compose example with transfer fst to get result
fstproject written.fst | fstcompose - num_written_to_spoken.fst | fstproject --project_output | fstrmepsilon > spoken.fst
## show result in pdf
fstdraw -portrait spoken.fst | dot -Tpdf >spoken.pdf
