#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;

string readnum(int n);
string parity(int n);

int main() {
    // Complete the code.
    int a; int b;
    cin>>a>>b;
    for (int i=a; i<b+1; i++){
        if (i<10){
            cout<<readnum(i)<<endl;
        }
        else{
            cout<<parity(i)<<endl;
        }
    }
    return 0;
}


string readnum(int n) {
    if (n==1){
        return "one";
    }
    else if (n==2){
        return "two";
    }
    else if (n==3){
        return "three";
    }
    else if (n==4){
        return "four";
    }
    else if (n==5){
        return "five";
    }
    else if (n==6){
        return "six";
    }
    else if (n==7){
        return "seven";
    }
    else if (n==8){
        return "eight";
    }
    else{
        return "nine";
    }
}


string parity(int n) {
    int che;
    che = pow((-1.0),n);
    if (che ==1){
        return "even";
    }
    else{
        return "odd";
    }
}