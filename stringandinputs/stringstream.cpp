#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> lect(0);
    char cr; 
    int a; int actualsize;
    stringstream ss(str);
    while (ss>>a){
        actualsize ++;
        lect.resize(actualsize);
        lect[actualsize-1]=a;
        ss >>cr;
    }
    return lect;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}