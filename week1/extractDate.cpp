#include<bits/stdc++.h>

using namespace std;

int main(){
    string date;
    cin >> date;
    if(date.length()<10 || date[4]!='-' || date[7]!='-') cout << "INCORRECT";
    else if (date[5] > '1' || (date[5] == '1' && date[6] > '2') || date[8] > '3' || (date[8] == '3' && date[9] > '1')){
        cout << "INCORRECT";
    } else {
        int year = (date[0] - '0')*1000 + (date[1] - '0')*100 + (date[2] - '0')*10 + (date[3] - '0');
        int month = (date[5] - '0')*10 + (date[6] - '0');
        int day = (date[8] - '0')*10 + (date[9] - '0');
        cout << year << " " << month << " " << day;
    }
}