#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    while(n--){
        string s; cin >> s;
        int hash = 0;
        int power = 1;
        for(int i=s.size()-1; i>=0; i--){
            hash = (hash + (s[i]*power) % m) % m;
            power = (power*256) % m;
        }
        cout << hash << endl;
    }
}