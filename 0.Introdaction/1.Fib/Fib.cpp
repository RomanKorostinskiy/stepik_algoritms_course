#include <iostream>
#include <cassert>

using namespace std;

class Fibonacci {
public: 
	static long long unsigned int GetNumRecursive(int n) {
		assert(n >= 0);
		if (n <= 1)
			return n;

		return GetNumRecursive(n - 1) + GetNumRecursive(n - 2);
	}

	static long long unsigned int GetNumFast(int n) {
		assert(n >= 0);
		if (n <= 1)
			return n;

		long long unsigned int array[2] = {0, 1};
		long long unsigned int current_digit = 0;

		for (int i = 2; i <= n; i++) {
			 current_digit = array[0] + array[1];
			 array[0] = array[1];
			 array[1] = current_digit;
		}

		return current_digit;
	}

	static int GetLastDigit(int n) {
		assert(n >= 0);
		if (n <= 1)
			return n;

		int array[2] = {0, 1};
		int current_digit = 0;

		for (int i = 2; i <= n; i++) {
			 current_digit = (array[0] + array[1]) % 10;
			 array[0] = array[1];
			 array[1] = current_digit;
		}

		return current_digit;
	}
};

int main()
{
	int n;
	cin >> n;
	cout<< Fibonacci::GetLastDigit(n) << endl;  
	cout << "Fib num: " << Fibonacci::GetNumFast(n) << endl;
	return 0;
}
