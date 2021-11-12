#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
 /* For this problem we have a queue with numbered people, which they can bribe each other to advance.
 the idea is to count the minumum number of bribes to get a configuration q.
 The nice trick is noticing that solving the problem "backwards from the queue" is much easier than doing
 it forward from the queue */

void minimumBribes(vector<int> q) {
    int sum_bribes=0; int flag = 0;
    int bribe_change=0; int bribe_change2;
    for (int i=1; i<q.size()+1; i++){
        int j = q.size()-i;
        if (q[j]!=j+1){
            if (q[j-1]==j+1){
                bribe_change = q[j];
                q[j]=j+1;
                q[j-1]=bribe_change;
                sum_bribes++;
            }
            else if (q[j-2] == j+1){
                bribe_change = q[j];
                bribe_change2= q[j-1];
                q[j]=j+1;
                q[j-1]=bribe_change;
                q[j-2]=bribe_change2;
                sum_bribes++;
                sum_bribes++;
            }
            else{
                flag=1;
            }
        }
    }

    if (flag == 0){
        cout << sum_bribes << endl;
    }
    else{
        cout << "Too chaotic" << endl;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
