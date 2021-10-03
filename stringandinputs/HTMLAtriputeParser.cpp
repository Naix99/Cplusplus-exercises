#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;


class QueryStructure{
    private:
        map<string, string> atributes;
    public:
        void addinputtag(string sname, string snameat, string sat){
            atributes.insert(make_pair(sname+"~"+snameat, sat));
        }
        
        void getQuery(string s){
            string out = atributes[s];
            if (out == ""){
                cout << "Not Found!" << endl;
            }
            else{
                cout << out<< endl;
            }
        }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N; int Q;
    string newline;
    string nameholder = "";
    cin >> N >> Q;
    QueryStructure HMTL;
    for (int i=0; i<N; i++){
        //Create query structure for each line that gives information
        cin >> newline;
        if (newline.substr(1,1) != "/" ){
            string checkat = newline.substr(newline.size()-1, newline.size());
          //  cout << "HAHAHA " << checkat << endl;
            if (checkat  == ">"){
           //     cout << "This ever happens?" << endl;
                string tagname = newline.substr(1,newline.size()-2);
                nameholder = nameholder + "." + tagname;
            }
            else{
                string tagname = newline.substr(1,newline.size());
                nameholder = nameholder + "." + tagname;
                tagname = nameholder.substr(1, nameholder.size()-1);
                string atname; string at;
                while (0<1){
                    cin >> atname >> at >> at;
                    if (at.substr(at.size()-1, at.size()-1)==">"){
                        at = at.substr(1,at.size()-3);
                        // cout << "HERE1 " << tagname << " " << atname << " " << at << "\n";
                        HMTL.addinputtag(tagname, atname, at);
                        break;
                    }
                    else {
                        at = at.substr(1,at.size()-2);
                        // cout << "HERE2 " << tagname << " " << atname << " " << at << "\n";
                        HMTL.addinputtag(tagname, atname, at);
                    }
                }
            }
        }
        else{
            int lastindex = nameholder.find_last_of(".");
            nameholder = nameholder.substr(0, lastindex);
            // cout << "BORRA " << nameholder << " "  << nameholder.size() << "\n";
        }    
    }
    for (int j =0; j<Q; j++){
        //Ask for information for each possible query 
        cin >> newline;
        // cout << "BUSCA " << newline << endl;
        HMTL.getQuery(newline);
    }
    return 0;
}