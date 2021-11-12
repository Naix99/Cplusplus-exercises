#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 * solution for the bomberman game. It is really long to explain the rules; they are here https://www.hackerrank.com/challenges/bomber-man/
 * a key thing to note were that the solutions were periodic, so all the game can be reduce to computing 2 matrices.
 */

vector<string> oneexplosion(vector<string> grid){
    vector<string> eg=grid;
    for (int i=0; i<grid.size(); i++){
        for (int j=0; j<grid[0].size(); j++){
            if (grid[i][j]=='O'){
                eg[i][j]='.';
            }
            else{
                int gs = grid.size();
                int gss = grid[0].size();
                int mini = max(i-1,0); int maxi = min(i+1,gs-1);
                int minj = max(j-1,0); int maxj = min(j+1, gss-1);
                if ((grid[mini][j]=='O')||(grid[maxi][j]=='O')||(grid[i][minj]=='O')||(grid[i][maxj]=='O')){
                    eg[i][j]='.';
                }
                else{
                    eg[i][j]='O';
                }
            }
        }
    }
    return eg;
}

vector<string> fullgrid(vector<string> grid){
    vector<string> fg;
    string s(grid[0].size(), 'O');
    for(int i=0; i<grid.size(); i++){
        fg.push_back(s);
    }
    return fg;
}

vector<string> bomberMan(int n, vector<string> grid) {
    vector<string> gridcopy = grid;
    if (n <= 1){
        return grid;
    }
    else if (n%2==0){
        return fullgrid(grid);
    }
    else if ((n+1)%4==0){
        return oneexplosion(grid);
    }
    else{
        return oneexplosion(oneexplosion(grid));
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
