#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* an example of how to use maps. This was a bit forced, but the basic strcuture is still useful. */
    map<string,int>notes;  // This create the map that asigns a integer to a string.
    int Q; int choice;
    string name; int mark; int marksum;
    cin >> Q;
    for (int i=0; i <Q; i++){
        cin >> choice;
        if (choice ==1){
            cin >> name >> mark;
            map<string,int>::iterator itr=notes.find(name); //this finds the reference of a particular name  (value in the domain) 
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



