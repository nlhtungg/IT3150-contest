#include<bits/stdc++.h>

using namespace std;

void generate(int n){
    int value=0;
    int s[n];
    while(value<pow(2,n)){
        bool check=true;
        int tmp=value;
        for(int i=n-1;i>=0;i--){
            s[i]=tmp%2;
            tmp=tmp/2;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==1 && s[i+1]==1){
                check=false;
                break;
            }
        }
        if(check == true){
            for(int i=0;i<n;i++) cout << s[i];
            cout << endl;
        }
        value++;
    }
}

int main(){
    int n; cin >> n;
    generate(n);
}