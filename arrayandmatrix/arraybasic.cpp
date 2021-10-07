#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* a really easy example on how to use arrays. This code get a set of N numbers, then return them in reverse order. */
int main() {
    int N;
    cin>>N;
    int arr[N];
    for (int i=0; i<N; i++){
        cin>>arr[i];
    }
    for (int i=N-1; i>-1; i--){
        cout<<arr[i];
        cout<<" ";
    }
    return 0;
}
