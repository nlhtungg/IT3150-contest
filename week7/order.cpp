#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Order {
    string customer_id;
    string product_id;
    int price;
    string shop_id;
    string time_point;
    int time_in_seconds;
};

vector<Order> orders;
unordered_map<string, int> shop_revenue;
unordered_map<string, unordered_map<string, int>> customer_shop_revenue;
vector<int> prefix_revenue;

int timeToSeconds(const string &time_point) {
    int h = stoi(time_point.substr(0, 2));
    int m = stoi(time_point.substr(3, 2));
    int s = stoi(time_point.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

void processOrderData() {
    string line;
    while (getline(cin, line) && line != "#") {
        stringstream ss(line);
        Order order;
        ss >> order.customer_id >> order.product_id >> order.price >> order.shop_id >> order.time_point;
        
        order.time_in_seconds = timeToSeconds(order.time_point);
        orders.push_back(order);

        // Update shop revenue
        shop_revenue[order.shop_id] += order.price;

        // Update revenue of customer at specific shop
        customer_shop_revenue[order.customer_id][order.shop_id] += order.price;
    }

    // Sort orders by time for efficient range querying
    sort(orders.begin(), orders.end(), [](const Order &a, const Order &b) {
        return a.time_in_seconds < b.time_in_seconds;
    });

    // Build prefix sum array for total revenue
    int cumulative_revenue = 0;
    for (const auto &order : orders) {
        cumulative_revenue += order.price;
        prefix_revenue.push_back(cumulative_revenue);
    }
}

void handleTotalNumberOrders() {
    cout << orders.size() << endl;
}

void handleTotalRevenue() {
    if (!prefix_revenue.empty()) {
        cout << prefix_revenue.back() << endl;
    } else {
        cout << 0 << endl;
    }
}

void handleRevenueOfShop(const string &shop_id) {
    cout << shop_revenue[shop_id] << endl;
}

void handleTotalConsumeOfCustomerShop(const string &customer_id, const string &shop_id) {
    cout << customer_shop_revenue[customer_id][shop_id] << endl;
}

void handleTotalRevenueInPeriod(const string &from_time, const string &to_time) {
    int from_seconds = timeToSeconds(from_time);
    int to_seconds = timeToSeconds(to_time);

    // Find the first order at or after `from_time`
    auto from_it = lower_bound(orders.begin(), orders.end(), from_seconds, 
                               [](const Order &order, int time) {
                                   return order.time_in_seconds < time;
                               });

    // Find the last order at or before `to_time`
    auto to_it = upper_bound(orders.begin(), orders.end(), to_seconds, 
                             [](int time, const Order &order) {
                                 return time < order.time_in_seconds;
                             }) - 1;

    // Calculate the total revenue in the period [from_time, to_time]
    if (from_it <= to_it && from_it != orders.end()) {
        int from_idx = from_it - orders.begin();
        int to_idx = to_it - orders.begin();
        int revenue_in_period = prefix_revenue[to_idx] - (from_idx > 0 ? prefix_revenue[from_idx - 1] : 0);
        cout << revenue_in_period << endl;
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

        if (query == "?total_number_orders") {
            handleTotalNumberOrders();
        } else if (query == "?total_revenue") {
            handleTotalRevenue();
        } else if (query == "?revenue_of_shop") {
            string shop_id;
            ss >> shop_id;
            handleRevenueOfShop(shop_id);
        } else if (query == "?total_consume_of_customer_shop") {
            string customer_id, shop_id;
            ss >> customer_id >> shop_id;
            handleTotalConsumeOfCustomerShop(customer_id, shop_id);
        } else if (query == "?total_revenue_in_period") {
            string from_time, to_time;
            ss >> from_time >> to_time;
            handleTotalRevenueInPeriod(from_time, to_time);
        }
    }
}

int main() {
    processOrderData();
    processQueries();
    return 0;
}
