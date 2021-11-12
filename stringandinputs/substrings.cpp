#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

 // This code recieves and string in 12-hour format and change it to 24-hour format.

string timeConversion(string s) {
    string hour = s.substr(0,2);
    string minsec = s.substr(2,6);
    string mm = s.substr(8,2);
    int numbhour = atoi(hour.c_str());
    if (mm=="AM"){
        if (hour == "12"){
            hour ="00";
            return hour+minsec;
        }
        else{
            return hour + minsec;
        }
    }
    else{
        if (hour =="12"){
            return hour + minsec;
        }
        else{
            numbhour = numbhour + 12;
            hour = to_string(numbhour);
            return hour + minsec;
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
