#include <iostream>
#include <cassert>
#include "ArraySequence.h"

void testConcat() {
    ArraySequence<int> seq1(3);
    seq1.get(0) = 1;
    seq1.get(1) = 2;
    seq1.get(2) = 3;

    ArraySequence<int> seq2(2);
    seq2.get(0) = 4;
    seq2.get(1) = 5;

    ArraySequence<int> concatenated = seq1.concat(seq2);

    assert(concatenated.getSize() == 5);

    assert(concatenated.get(0) == 1);
    assert(concatenated.get(1) == 2);
    assert(concatenated.get(2) == 3);
    assert(concatenated.get(3) == 4);
    assert(concatenated.get(4) == 5);

    std::cout << "Test for concat passed!" << std::endl;
}