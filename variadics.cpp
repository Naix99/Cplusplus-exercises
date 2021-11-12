#include <iostream>
using namespace std;

// This is an example of how to use a template parameter pack for implementing a function that 
//check binary repreasentation of numbers.

// Enter your code for reversed_binary_value<bool...>()
//If you have only one digit, we return that (because tht is the number)
template <bool a> int reversed_binary_value() { return a; }

/* if we have a lst of digits, we use recursion. Each digit is then passed to base 2.
 recall <<1 is shifting in binary, so x << y is x 2^y. Hence the << 1 below
 is just shifting one digit in base-2 */
template <bool a, bool b, bool... d> int reversed_binary_value() {
  return (reversed_binary_value<b, d...>() << 1) + a;
}


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}