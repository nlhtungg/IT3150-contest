#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int kount = 0;
    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == k) {
            kount++;
            i++;
            j--;
        } else if(a[i] + a[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    cout << kount << endl;
}