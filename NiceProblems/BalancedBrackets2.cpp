#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    if (s.size()==0){
        return "YES";
    }
    else if ((s.size()%2 !=0)){
        return "NO";
    }
    else{
        stack<char> pila;
        char nb;
        for (int i=0; i<s.size(); i++){
            if ((s[i]=='(')||(s[i]=='{')||(s[i]=='[')){
                pila.push(s[i]);
            }
            else if(s[i]==')'){
                if (pila.size()>0){
                    nb = pila.top();
                    if (nb!='('){
                        return "NO";
                    }
                    pila.pop();
                }
                else{
                    return "NO";
                }
            }
            else if(s[i]=='}'){
                if (pila.size()>0){
                    nb = pila.top();
                    if (nb!='{'){
                        return "NO";
                    }
                    pila.pop();
                }
                else{
                    return "NO";
                }
            }
            else if(s[i]==']'){
                if (pila.size()>0){
                    nb = pila.top();
                    if (nb!='['){
                        return "NO";
                    }
                    pila.pop();
                }
                else{
                    return "NO";
                }
            }
        }
        if (pila.size()==0){
            return "YES";
        }
        else{
            return "NO";
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
