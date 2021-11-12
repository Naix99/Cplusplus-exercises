#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

 /* this was a cool problem. You had to determine in each step the following step ends. You grab a number n,
if it is a power of 2 divide it by 2. If not substract the biggest power of 2, smaller than the number,
than you can find. 

If this ends on an odd step "Louise" wins, if not "Richard" wins.

This has really cool tricks regarding bit representation */
long smallerPowerOf2(long nl)
{
    int count = 0;
     
    // First n in the below condition
    // is for the case where n is 0
    if (nl && !(nl & (nl - 1)))
        return nl;
     
    while( nl != 0)
    {
        nl >>= 1;
        count ++;
    }
    count --;
     
    return 1L << count; // Needed the long 1 to make this correct for big values.
}
 

string counterGame(long n) {
    long num = n;
    int i=1;
    while (true){
        if (num==1){
            if (i==1){
                return "Richard";
            }
            else{
                return "Louise";
            }
        }
        else if (((num & (num - 1)))==0){ //This happens if and only if the number is a power of 2 (see the bit representation :P)
            if (!((int)log2(num)%2==0)){
                i=i*(-1);
            }
            if (i==1){
                return "Richard";
            }
            else{
                return "Louise";
            }
        }
        else{
            num = num-smallerPowerOf2(num);
        }
        i=i*(-1);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

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