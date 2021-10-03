#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int newn;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i < N; i++){
        cin >> newn;
        v[i]=newn;
    }
    sort(v.begin(),v.end());
    for (int i=0; i < N; i++){
        cout<<v[i]<< " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
