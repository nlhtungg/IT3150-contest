#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<int> q;
    while(true){
        string cmd; cin >> cmd;
        if(cmd == "#"){
            break;
        } else if(cmd == "PUSH"){
            int x; cin >> x;
            q.push(x);
        } else if(cmd == "POP"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
}