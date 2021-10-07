/* Example on how to use macros. Really nice actually! */


// Basic defining formats for some macros.
#define INF 100000000
#define toStr(str) #str 
#define FUNCTION(name, op) void name(int& a, int b) { if (b op a) a = b; }
#define io(a) cin>>a
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)


#include <iostream>
#include <vector>
using namespace std;

// A code to check if certain macros are defined.
#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}