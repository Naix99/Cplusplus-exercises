#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

 /* Okay this was a cool problem. Given a number n the idea is to count all the number x, with 0 \leq x \leq n
 such that n+x = n XOR x. One can do a for but that is incredible ineficient. 
 To improve that one can look at the binayr representation of the number n and note that x will satisfy
 the required equation if it has a 0 at every bit in which n has a 1. This is easy to see by translating
 the required equation in binary numbers.
 Hence we just need to count the length of the binary expresion of n, substract the number of ones and
 that give all the free choices for x. */
 
int numberofones(long num){
    int count = 0;
    long nl=num;
    while (nl > 0){
        count = count + 1;
        nl = nl & (nl-1);
    }
    return count;
}

int lengthbinary(long num){
    return int(log2(num))+1;
}

long sumXor(long n) {
    if (n==0){
        return 1;
    }
    int freespaces = lengthbinary(n)-numberofones(n);
    long count = pow(2,freespaces);
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

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
