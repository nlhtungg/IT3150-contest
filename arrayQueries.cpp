#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, sum=0; cin >> n;
    int a[n];
    string command;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    while(true) {
        cin >> command;
        if(command == "*") continue;
        else if(command == "***") break;
        else if(command == "find-max"){
            int max = a[0];
            for(int i=1;i<n;i++){
                if(a[i]>max) max = a[i];
            }
            cout << max << endl;
        }
        else if(command == "find-min"){
            int min = a[0];
            for(int i=1;i<n;i++){
                if(a[i]<min) min = a[i];
            }
            cout << min << endl;
        }
        else if(command == "find-max-segment"){
            int x,y; cin >> x >> y;
            int max = a[x-1];
            for(int i=x;i<y;i++){
                if(a[i]>max) max = a[i];
            }
            cout << max << endl;
        }
        else if(command == "find-min-segment"){
            int x,y; cin >> x >> y;
            int min = a[x-1];
            for(int i=x;i<y;i++){
                if(a[i]<min) min = a[i];
            }
            cout << min << endl;
        }
        else if(command == "sum") cout << sum << endl;
     }
}