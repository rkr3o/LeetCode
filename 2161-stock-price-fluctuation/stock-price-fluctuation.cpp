#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class StockPrice {
public:
    unordered_map<int, int> mp;   // timestamp to price mapping
    multiset<int> st;             // multiset to keep track of prices, sorted by price
    int lastTimeStamp = 0;
    int lastPrice = 0;
    StockPrice() {
        
    }
    void update(int timestamp, int price) {
        if (mp.find(timestamp) != mp.end()) {
            st.erase(st.find(mp[timestamp]));  // find and erase the specific element in multiset
        }
        st.insert(price);
        mp[timestamp] = price;
        
        if (timestamp >= lastTimeStamp) {
            lastTimeStamp = timestamp;
            lastPrice = price;
        }
    }
    
    int current() {
        return lastPrice;
    }
    int maximum() {
        return *prev(st.end());  // use prev() to get iterator to last element
    }
    int minimum() {
        return *st.begin();  // use begin() to get iterator to first element
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp, price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
