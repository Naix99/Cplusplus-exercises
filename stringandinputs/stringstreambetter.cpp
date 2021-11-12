#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string str;
    int a; char cr;
    cin >> str;
    stringstream ss(str);
    while (ss>>a){
        cout<<a<<"\n";
        ss >> cr;
    }    
    return 0;
}