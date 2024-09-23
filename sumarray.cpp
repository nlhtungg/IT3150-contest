#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    int sumArray = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sumArray += a[i];
    }
    cout << sumArray;
}