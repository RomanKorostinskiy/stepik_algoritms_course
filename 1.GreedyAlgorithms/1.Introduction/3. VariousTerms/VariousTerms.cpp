#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct VariousTerms {
	int num_of_consecutive_terms = 0;
	int last_term = 0;
};

int GetSum (int number) {
	int sum = 0;
	for (int i = 1; i <= number; i++) {
		sum += i;
	}

	return sum;
}

void GetVariousTerms (int number, VariousTerms* various_terms) {
	int i = 1;
	int sum = 1;

	while (number - sum > i + 1) {
		i++;
		sum = GetSum(i);
	}

	if (number - sum == i + 1) {
		various_terms->last_term = i + 1;
		various_terms->num_of_consecutive_terms = i;
	} else {
		various_terms->last_term = number - sum + i;
		various_terms->num_of_consecutive_terms = i - 1;
	}
}

int main() {
	int number;
	VariousTerms various_terms;

	std::cin >> number;

	GetVariousTerms(number, &various_terms);

	std::cout << various_terms.num_of_consecutive_terms + 1 << std::endl;

	for (int i = 1; i <= various_terms.num_of_consecutive_terms; i++) {
		std::cout << i << " ";
	}

	std::cout << various_terms.last_term << std::endl;

	return 0;
}