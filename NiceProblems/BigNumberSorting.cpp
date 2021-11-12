#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.

 The idea was to ordered numbers that are too big for int or long. They are passed as string. First I implement a methord to compare the strings
 and then just ordered using sort, but overloading the inequality checker with my method. Intersting problem :).
 */




bool firstsbigger(string s1, string s2){
    if (s1.size()>s2.size()){
        return false;
    }
    else if (s1.size()<s2.size()){
        return true;
    }
    else{
        for (int i=0; i<s1.size(); i++){
            if (s1[i]>s2[i]){
                return false;
            }
            else if (s1[i]<s2[i]){
                return true;
            }
        }
    }
    return false;
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> ordered=unsorted;
    sort(ordered.begin(), ordered.end(), firstsbigger);
    return ordered;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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