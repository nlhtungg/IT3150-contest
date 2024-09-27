#include<bits/stdc++.h>

using namespace std;

int main(){
    string time;
    cin >> time;
    if(time.length()<7 || time[2]!=':' || time[5]!=':'){
        cout << "INCORRECT";
    } else if (time[0] > '2' || (time[0] == '2' && time[1] > '3') || time[3] > '5' || time[6] > '5'){
        cout << "INCORRECT";
    } else {
        int hour = (time[0] - '0')*10 + (time[1] - '0');
        int minute = (time[3] - '0')*10 + (time[4] - '0');
        int second = (time[6] - '0')*10 + (time[7] - '0');
        cout << hour*3600 + minute*60 + second;
    }
}