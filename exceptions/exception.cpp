#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Example on how to use exceptions. A little bit forced, but you can check the idea with the comments below. */

struct BadLengthException : public std::exception { // This creates an "exception" element. There are some existing with C++, but good to know how to create one.
   private:
    int N;
   public:
   BadLengthException(int length) { //constructor of BadLengthException, requieres an int
        N = length;
   }
   int what(){
       return N;
   }
   
};



bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n); //This "throws into the consule" the exception. To get that into console we see below.
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try { //We try to do something, knowing to abort if an exception is thrown.
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n'; //If an exception was throw we override the computations so far and retur an error message.
		}
	}
	return 0;
}