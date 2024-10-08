#include<bits/stdc++.h>

using namespace std;

int operation(string s){
    int tron=0, vuong=0, nhon=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==40) tron++;
        else if(s[i]==41) tron--;
        else if(s[i]==91) vuong++;
        else if(s[i]==93) vuong--;
        else if(s[i]==123) nhon++;
        else if(s[i]==125) nhon--;
        if(tron<0 || vuong<0 || nhon<0) return 0;
    }
    if(tron>0 || vuong>0 || nhon>0) return 0;
    return 1;
}

int main(){
    string s; cin >> s;
    cout << operation(s);
}
