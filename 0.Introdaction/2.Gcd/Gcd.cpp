#include <iostream>
#include <cassert>

using namespace std;

int Gcd (int a, int b) 
{
	assert (a >=0 && b >= 0);

	if (a * b == 0)
		return a + b;

	if (a > b)
		return Gcd(a % b, b);
	else 
		return Gcd(a, b % a);
}

int main()
{
	int a, b = 0;
	cin >> a >> b;
	cout << Gcd(a, b) << endl;
	return 0;
}
