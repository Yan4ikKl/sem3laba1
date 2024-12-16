#include <iostream>
#include "ArraySequence.h"

int main() {
    // Создание двух ArraySequence для теста concat
    ArraySequence<int> seq1(3);
    ArraySequence<int> seq2(2);

    // Заполнение первой последовательности
    seq1.set(0, 1);
    seq1.set(1, 2);
    seq1.set(2, 3);

    // Заполнение второй последовательности
    seq2.set(0, 4);
    seq2.set(1, 5);

    // Демонстрация метода concat
    std::cout << "Sequence 1 before concat: ";
    for (int i = 0; i < seq1.getSize(); i++) {
        std::cout << seq1.get(i) << " ";
    }
    std::cout << std::endl;

    seq1.concat(seq2); // Соединяем seq1 и seq2

    std::cout << "Sequence 1 after concat: ";
    for (int i = 0; i < seq1.getSize(); i++) {
        std::cout << seq1.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
