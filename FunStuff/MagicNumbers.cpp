#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    int precom1[3][3]={{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    int precom2[3][3]={{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
    int precom3[3][3]={{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    int precom4[3][3]={{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
    int precom5[3][3]={{8, 3, 4}, {1, 5, 9}, {6, 7, 2}};
    int precom6[3][3]={{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
    int precom7[3][3]={{6, 7, 2}, {1, 5, 9}, {8, 3, 4}};
    int precom8[3][3]={{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
    int actualsum=0;
    int bestsum=100000;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom1[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom2[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom3[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom4[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom5[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom6[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom7[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    for (int i=0; i<3;i++){
        for (int j=0; j<3;j++){
            actualsum=actualsum+ abs( s[i][j]-precom8[i][j] );
        }    
    }
    if (bestsum>actualsum){
        bestsum = actualsum;
    }
    actualsum=0;
    return bestsum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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