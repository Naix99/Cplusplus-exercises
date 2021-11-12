#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
 
 /* this problem ask to "shift" an string by a integer k.Really fun problem actually */

string caesarCipher(string s, int k) {
    k = k % 26; // we do not need to "go arround" the alphabet.
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] >= 65 && s[i] <= 90) // If the letter is lower case, shift it.
        {
            if(s[i] + k > 90) // If we pass the alphabet we need to restart "at the beginning"
                s[i] -= 26;
            s[i] += k;
        }
        else if(s[i] >= 97 && s[i] <= 122) //Now do the same with Upper case.
        {   
            if(s[i] + k > 122)
                s[i] -= 26;
            s[i] += k;
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

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