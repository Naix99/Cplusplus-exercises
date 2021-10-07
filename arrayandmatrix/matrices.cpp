#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* An easy example of how to work with matrices. Again, forced ideas, but the code is still useful. */ 
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n); /* this creates a vector of length n where each element is an array of length n (so a matrix of size nxn */

    for (int i = 0; i < n; i++)
    {
        int length;
        cin >> length;
        arr[i].resize(length); /*resize the i component to the length given by the output */
        for(int j = 0; j < length; j++) /*subroutine to fill the i row of the array*/
        {
            cin >> arr[i][j];
        }       
    }
 /*up to here we have filled the matrix, now we answer the queries*/
    for (int k = 0; k < q; k++)
    {
        int i, j;
        cin >> i >> j;
        cout << arr[i][j]<<endl; /*this goes to the (i,j) of the matrix and returns that*/
    }    
    return 0;
}