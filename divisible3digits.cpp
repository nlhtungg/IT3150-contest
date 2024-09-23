#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int i=n;
    if(i>99 && i<1000) cout << i << " ";
    while(i<1000){
        i+=n;
        if(i>99 && i<1000) cout << i << " ";
    }
}