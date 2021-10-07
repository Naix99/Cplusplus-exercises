#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Student class containing five grades of the student.

class Student {
    private:
        int score1; int score2; int score3; int score4; int score5;
    public:
        void input() {
            string scores;
            cin>>score1 >> score2 >> score3 >> score4 >> score5;
        }
        int calculateTotalScore(){
            return score1 + score2 + score3 + score4 + score5;
        }
};

// Student class finish here

// The following code compare a student (kristen) with respect to her position against all other student in the class.
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}