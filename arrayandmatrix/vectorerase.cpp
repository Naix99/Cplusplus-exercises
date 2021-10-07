#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Example code on how to work with vectors. In particular on how to erase elements.*/ 
    int N;
    int newn;
    int er; int ers; int ere;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i < N; i++){
        cin >> newn;
        v[i]=newn;
    }  
    cin >> er;
    v.erase(v.begin()+er-1);
    cin >> ers >> ere;
    v.erase(v.begin()+ers-1,v.begin()+ere-1);
    cout<< v.size() <<endl;
    for (int i=0; i < v.size(); i++){
        cout<<v[i]<< " ";
    }
    return 0;
}
