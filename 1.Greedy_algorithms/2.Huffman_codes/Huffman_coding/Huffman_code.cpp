#include <iostream>
#include <queue>
#include <vector>

#define NOT_FOUND -1

class Symbol {
public:
	char name;
	int frequency;

	Symbol(const char name): name(name), frequency(1) {}

	void Print () {
		std::cout << name << " " << frequency;
	}
};

class PriorityQueue {
public:
	std::vector<Symbol> array;

	void Insert(Symbol sym) {
		array.push_back(sym);
	}

	Symbol ExtractMin() {
		Symbol min_freq_sym = array[0];

		for (size_t i = 0; i < array.size(); i++) {
			if (array[i].frequency < min_freq_sym.frequency)
				min_freq_sym = array[i];
		}

		return min_freq_sym;
	}

	size_t Size() {
		return array.size();
	}

	void Print() {
		for (size_t i = 0; i < array.size(); i++) {
			array[i].Print();
			std::cout << " ";
		}
 
		std::cout << std::endl;
	}

	Symbol operator [] (int i) { return array[i]; }
};

namespace Code {
    class BinaryTree {
        struct node {
            Symbol sym;
            node *left;
            node *right;
        };

        node root;

        BinaryTree():
    };

	int FindSymInQueue(char sym_name, PriorityQueue queue) {
		for (size_t i = 0; i < queue.Size(); i++) {
			if (queue[i].name == sym_name)
				return i;
		}

		return NOT_FOUND;
	}

	void PutSymbolsIntoQueue(std::string string, PriorityQueue &queue) {
		int len = string.length();
		int sym_place = 0;

		for(int i = 0; i < len; i++) {
			if ((sym_place = FindSymInQueue(string[i], queue)) != NOT_FOUND) {
				//queue[sym_place].frequency++; //using rvalue as lvalue <???>
				queue.array[sym_place].frequency++;
			} else {
				Symbol sym = Symbol(string[i]);
				queue.Insert(sym);
			}
		}
	}
}

int main() {
	std::string string;
	std::cin >> string;

	PriorityQueue queue;

	Code::PutSymbolsIntoQueue(string, queue);

	queue.Print();

    Code::BinaryTree tree;

	return 0;
}
