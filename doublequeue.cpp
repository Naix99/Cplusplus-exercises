#include <iostream>
#include <deque> 
using namespace std;

// Example and format to use a double queue find in here.
// The problem was the find the position of the maximum of an array in each possible "mask" of size k
// The problem was weird, but it did help to learn double queue :).

void printKMax(int arr[], int n, int k){
    deque<int> knumbers;
    int amax = 0; int posmax =0;
    for (int i=0; i<k; i++ ){
        if (amax < arr[i]){
            amax = arr[i];
            posmax = i;
        } 
        knumbers.push_back(arr[i]);
    }
    cout << amax << " ";
    for (int j=k; j<n; j++){
        knumbers.push_back(arr[j]);
        knumbers.pop_front();
        posmax = posmax-1;
        if (amax <arr[j]){
            amax = arr[j];
            posmax = k-1;
        }
        else if (posmax==-1){
            amax = 0;
            for (int i=0; i<k; i++ ){
                if (amax < knumbers[i]){
                    amax = knumbers[i];
                    posmax = i;
                } 
            }
        }
        cout << amax << " ";
    }
    cout << "\n";
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}