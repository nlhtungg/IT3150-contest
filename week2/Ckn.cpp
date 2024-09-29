#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int mod = 1e9+7;
    int k, n; cin >> k >> n;
    long long int c[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(i == 0 || i == j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i][j-1]) % mod;
        }
    }
    cout << c[k][n] << endl;
}