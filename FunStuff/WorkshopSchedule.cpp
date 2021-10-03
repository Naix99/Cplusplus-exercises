#include<bits/stdc++.h>

using namespace std;
#include<vector>
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops {
    int starttime;
    int duration;
    int endingtime;
};

struct Available_Workshops {
    int numberworkshops;
    vector<Workshops> wlist;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
  // code to be executed
  Available_Workshops* ws{new Available_Workshops};
  ws->numberworkshops = n;
  for (int i=0; i<n; i++){
      Workshops acws;
      acws.starttime = start_time[i];
      acws.duration = duration[i];
      acws. endingtime = start_time[i]+duration[i];
      ws->wlist.push_back(acws);
  }
  return ws;
}

bool compare_workshops(Workshops& ws1, Workshops& ws2) {
  return ws1.endingtime > ws2.endingtime;
}

int CalculateMaxWorkshops(Available_Workshops* aws) {
  vector<Workshops> wrlist = aws->wlist;
  sort(wrlist.begin(), wrlist.end(), compare_workshops);
  int totalworkshops =0;
  while (wrlist.size()>0) {
    totalworkshops ++;
    int end_time = wrlist.back().endingtime;
    while ((wrlist.size()>0)) {
      wrlist.pop_back();
      if (wrlist.back().starttime >= end_time) {
        break;
      }
    }
  }

  return totalworkshops;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}