#include <bits/stdc++.h>

using namespace std;

string readnum(int n);

int main()
{
    int n_temp;
    string n_text;
    cin>>n_temp;

    if (n_temp>9){
        cout<<"Greater than 9";
    }
    else{
        n_text = readnum(n_temp);
        cout<< n_text;
    }

    // Write your code here

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