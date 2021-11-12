#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a; string b;
    cin >> a >> b;
    int sa = a.size(); int sb=b.size();
    cout<<sa<<" "<<sb<<"\n";
    string ct=a+b;
    cout<<ct<<"\n";
    char fa=a[0]; char fb=b[0];
    a[0]=fb;
    b[0]=fa;
    cout<<a<<" "<<b;
    return 0;
}