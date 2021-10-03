#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; int Q;
    int valo;
    cin >> N;
    vector<int> ar;
    for (int i=0; i<N; i++){
       cin >> valo;
       ar.push_back(valo);
    }
    cin >> Q;  
    for (int j=0; j<Q; j++){
        cin >> valo;
        vector<int>::iterator low = lower_bound(ar.begin(), ar.end(), valo);
        if (ar[low - ar.begin()] == valo){
            cout<<"Yes " <<(low-ar.begin()+1)<<"\n";
        }
        else{
            cout<<"No "<<(low-ar.begin()+1)<<"\n";
        }
    }
    return 0;
}