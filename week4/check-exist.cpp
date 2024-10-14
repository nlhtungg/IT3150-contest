#include<bits/stdc++.h>

using namespace std;

#define MAX_INT 1000000000

int main() {
    int n; cin >> n;
    bool exist[MAX_INT + 1];
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(exist[a[i]]){
            cout << 1 << endl;
        } else cout << 0 << endl;
        exist[a[i]] = true;
    }
}