#include <iostream>

#include "UI.h"
#include "TestDynamicArray.h"
#include "TestShared_ptr.h"
#include "TestUnique_ptr.h"
#include "ArraySequence.h"

void printSequence(const ArraySequence<int>& seq) {
	std::cout << "Sequence: ";
	for (int i = 0; i < seq.getSize(); ++i) {
		std::cout << seq.get(i) << " ";
	}
	std::cout << std::endl;
}

void startUI()
{
	std::cout << "Choose which test you want to do:\n";
	std::cout << "0 - finish program\n";
	std::cout << "1 - test with dynamic array\n";
	std::cout << "2 - test with shared_ptr\n";
	std::cout << "3 - test with unique_ptr\n";
	std::cout << "4 - add element\n";
	std::cout << "5 - get element\n";
	std::cout << "6 - print sequence\n";
	int selectedTest{};
	std::cin >> selectedTest;
	ArraySequence<int> sequence(0);
	while (selectedTest != 0)
	{
		while (selectedTest < 0 || selectedTest > 6)
		{
			std::cout << "The wrong number was entered.Try again\n";
			std::cin >> selectedTest;
		}
		if (selectedTest == 1)
		{
			TestDynamicArray testDynamicArray;
			testDynamicArray.allTests();
			std::cout << "The tests were successfull\n";
		}
		if (selectedTest == 2)
		{
			TestShared_ptr testShared_ptr;
			testShared_ptr.allTests();
			std::cout << "The tests were successfull\n";
		}
		if (selectedTest == 3)
		{
			TestUnique_ptr testUnique_ptr;
			testUnique_ptr.allTests();
			std::cout << "The tests were successfull\n";
		}
		if (selectedTest == 4)
		{
			int value;
			std::cout << "Enter value to add: ";
			std::cin >> value;

			ArraySequence<int> newSequence(sequence.getSize() + 1);
			for (int i = 0; i < sequence.getSize(); ++i) {
				newSequence.get(i) = sequence.get(i);
			}
			newSequence.get(sequence.getSize()) = value;

			sequence = std::move(newSequence);
		}
		if (selectedTest == 5)
		{
			int index;
			std::cout << "Enter index to get: ";
			std::cin >> index;
			try {
				std::cout << "Element at index " << index << ": " << sequence.get(index) << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}
		if (selectedTest == 6)
		{
			printSequence(sequence);
		}
		std::cout << "\n\nChoose which test you want to do:\n";
		std::cout << "0 - finish program\n";
		std::cout << "1 - test with dynamic array\n";
		std::cout << "2 - test with shared_ptr\n";
		std::cout << "3 - test with unique_ptr\n";
		std::cout << "4 - add element\n";
		std::cout << "5 - get element\n";
		std::cout << "6 - print sequence\n";
		std::cin >> selectedTest;
	}
	
	std::cout << "You have finished program\n";
}