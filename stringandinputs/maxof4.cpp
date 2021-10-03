#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d){
    int maxi;
    if (a>b){
        maxi = a;
    }
    else{
        maxi = b;
    }
    if (maxi<c){
        maxi = c;
    }
    if (maxi < d){
        maxi = d;
    }
    return maxi;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}