#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;

const int MAX_PEOPLE = 100;

vector<int> children[MAX_PEOPLE];
vector<string> names;
int name_to_id[MAX_PEOPLE];

int find_or_add(const string& name) {
    for (int i = 0; i < names.size(); ++i) {
        if (names[i] == name)
            return i;
    }
    names.push_back(name);
    return names.size() - 1;
}

int count_descendants(int person) {
    int count = 0;
    stack<int> s;
    for (int child : children[person]) {
        s.push(child);
    }
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        count++;
        for (int child : children[current]) {
            s.push(child);
        }
    }
    
    return count;
}

int count_generations(int person) {
    int max_depth = 0;
    stack<pair<int, int>> s;
    for (int child : children[person]) {
        s.push({child, 1});
    }
    
    while (!s.empty()) {
        auto [current, depth] = s.top();
        s.pop();
        max_depth = max(max_depth, depth);
        for (int child : children[current]) {
            s.push({child, depth + 1});
        }
    }
    
    return max_depth;
}

int main() {
    string child, parent;
    vector<pair<string, string>> relations;

    while (cin >> child) {
        if (child == "***") break;
        cin >> parent;
        int child_id = find_or_add(child);
        int parent_id = find_or_add(parent);
        children[parent_id].push_back(child_id);
    }
    
    string cmd, name;
    
    while (cin >> cmd) {
        if (cmd == "***") break;
        cin >> name;
        int person_id = find_or_add(name);
        
        if (cmd == "descendants") {
            cout << count_descendants(person_id) << endl;
        } else if (cmd == "generation") {
            cout << count_generations(person_id) << endl;
        }
    }

    return 0;
}
