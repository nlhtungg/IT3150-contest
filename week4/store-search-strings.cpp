#include<bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<string> database;
    string key, cmd;

    while(true){
        cin >> key;
        if(key == "*") break;
        database.insert(key);
    }
    while(true){
        cin >> cmd;
        if(cmd == "***") break;
        cin >> key;
        if(cmd == "find"){
            if(database.find(key) != database.end()){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else if(cmd == "insert"){
            if(database.insert(key).second){
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}
