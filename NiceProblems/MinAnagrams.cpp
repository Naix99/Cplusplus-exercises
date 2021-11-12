#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.

 Really fun problem. The idea was to grab a string, cut it in two pieces, and then look what is the minimum ammount of changes to the 
 character of the string one need to make to get two anagrams.

 Since it is the ammount of changes (and not which), we can just count the letters and see "how much surpluss of one character"
 each string has. 
 */

int anagram(string s) {
    int tot=0;
    if (s.size()%2!=0){
        return -1;
    }
    else{
        string ss = s;
        string s1 = ss.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2,s.size()/2);
        vector<int> als1(27,0);
        for (int i=0; i<s1.size(); i++){
            int c1 = s1[i]-'a'; int c2 = s2[i]-'a';
            cout << c1 << " " << als1[c1] << endl ;
            als1[c1] ++; als1[c2] --;
        }
        for (int i=0; i<27; i++){
            tot += abs(als1[i]);
        }
    }
    return tot/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
