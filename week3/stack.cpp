#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    while(true){
        string cmd; cin >> cmd;
        if(cmd == "#"){
            break;
        } else if(cmd == "PUSH"){
            int x; cin >> x;
            s.push(x);
        } else if(cmd == "POP"){
            if(!s.empty()){
                cout << s.top() << endl;
                s.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
}