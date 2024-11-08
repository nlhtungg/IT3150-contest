#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

struct Transaction {
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

vector<Transaction> transactions;
unordered_map<string, int> money_sent_from_account;
unordered_map<string, vector<string>> adjacency_list;
unordered_set<string> unique_accounts;

void processTransactionData() {
    string line;
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        Transaction t;
        ss >> t.from_account >> t.to_account >> t.money >> t.time_point >> t.atm;
        transactions.push_back(t);
        money_sent_from_account[t.from_account] += t.money;
        adjacency_list[t.from_account].push_back(t.to_account);
        unique_accounts.insert(t.from_account);
        unique_accounts.insert(t.to_account);
    }
}

void handleNumberTransactions() {
    cout << transactions.size() << endl;
}

void handleTotalMoneyTransaction() {
    int total_money = 0;
    for (const auto &t : transactions) {
        total_money += t.money;
    }
    cout << total_money << endl;
}

void handleListSortedAccounts() {
    set<string> sorted_accounts(unique_accounts.begin(), unique_accounts.end());
    for (const string &account : sorted_accounts) {
        cout << account << " ";
    }
    cout << endl;
}

void handleTotalMoneyTransactionFrom(const string &account) {
    cout << money_sent_from_account[account] << endl;
}

bool dfsCycleDetect(const string &start, const string &current, int depth, int target_length, unordered_set<string> &visited) {
    if (depth == target_length) {
        return current == start;
    }

    visited.insert(current);

    for (const string &next : adjacency_list[current]) {
        if ((visited.find(next) == visited.end() || (depth + 1 == target_length && next == start)) &&
            dfsCycleDetect(start, next, depth + 1, target_length, visited)) {
            return true;
        }
    }

    visited.erase(current); // backtrack
    return false;
}

void handleInspectCycle(const string &account, int cycle_length) {
    unordered_set<string> visited;
    if (dfsCycleDetect(account, account, 0, cycle_length, visited)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

void processQueries() {
    string line;
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        string query;
        ss >> query;

        if (query == "?number_transactions") {
            handleNumberTransactions();
        } else if (query == "?total_money_transaction") {
            handleTotalMoneyTransaction();
        } else if (query == "?list_sorted_accounts") {
            handleListSortedAccounts();
        } else if (query == "?total_money_transaction_from") {
            string account;
            ss >> account;
            handleTotalMoneyTransactionFrom(account);
        } else if (query == "?inspect_cycle") {
            string account;
            int cycle_length;
            ss >> account >> cycle_length;
            handleInspectCycle(account, cycle_length);
        }
    }
}

int main() {
    processTransactionData();
    processQueries();
    return 0;
}
