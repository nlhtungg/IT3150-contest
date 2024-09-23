#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int a[n];
    int countlength=0, needtoremove=-1, tmp = 0, kount = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
            countlength++;
            if(countlength<k){
                tmp += a[i];
            } else if(countlength==k){
                tmp += a[i];
                if(tmp%2==0) kount++;
                countlength--;
                needtoremove++;
                tmp -= a[needtoremove];
            }
    }
    cout << kount;
}