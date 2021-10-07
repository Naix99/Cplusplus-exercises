#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    // Good example on how to print the same elements in different formats.
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << hex << left << showbase << nouppercase; // hexadecimal formatting
        cout << (long long) A << endl; // actual printed part

        // LINE 2
        cout << dec << right << setw(15) << setfill('_') << showpos << fixed <<  setprecision(2); // formatting for two decimals
        cout << B << endl; // actual printed part

        // LINE 3
        cout << scientific << uppercase << noshowpos << setprecision(9); // formatting for 9 decimals in scientific notation
        cout << C << endl; // actual printed part

	}