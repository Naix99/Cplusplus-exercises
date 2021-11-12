#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


/* The objective of this problem was to make a simple text editor.
the instructions were to ethier add new string to the end of the current string, to erase the last k characters,
to print the k-th caracter or to undo the last possible acction (basically ctrl+Z). For the last bit I used a stack.


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  int Q;
    cin >> Q;
    string s1 =""; stack<string> laststeps;
    string opoption; string opobjst; int opobjint;
    for (int i=0; i<Q; i++){
        cin >> opoption;
        if (opoption=="1"){
            laststeps.push(s1);
            cin >> opobjst;
            s1.append(opobjst);
        }
        else if (opoption=="2"){
            cin >> opobjint;
            laststeps.push(s1);
            s1.erase(s1.size()-(opobjint),opobjint);
        }
        else if (opoption=="3"){
            cin >> opobjint;
            if (s1.size() >= opobjint){
                cout << s1[opobjint-1] << endl;
            }
        }
        else if (opoption=="4"){
            if (laststeps.size()>0){
              s1=laststeps.top();
              laststeps.pop();
            }
        }
    }
    return 0;
}
