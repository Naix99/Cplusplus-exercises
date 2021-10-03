#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    map<string,int>notes;
    int Q; int choice;
    string name; int mark; int marksum;
    cin >> Q;
    for (int i=0; i <Q; i++){
        cin >> choice;
        if (choice ==1){
            cin >> name >> mark;
            map<string,int>::iterator itr=notes.find(name);
            if (itr == notes.end()){
                notes.insert(make_pair(name, mark));
            }
            else{
                marksum = notes[name]+mark;
                notes.erase(name);
                notes.insert(make_pair(name, marksum));
            }
        }
        else if (choice == 3){
            cin >> name;
            marksum = notes[name];
            cout << marksum << "\n";
        }
        else{
            cin >> name;
            notes.erase(name);
        }
    }
    return 0;
}



