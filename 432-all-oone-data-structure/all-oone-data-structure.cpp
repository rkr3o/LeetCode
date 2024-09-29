class AllOne {
private:
    map<string, int> mp;
    priority_queue<pair<int, string>> maxima; 
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minima;

    void cleanMaxima() {
        while (!maxima.empty() && mp[maxima.top().second] != maxima.top().first) {
            maxima.pop();
        }
    }

    void cleanMinima() {
        while (!minima.empty() && mp[minima.top().second] != minima.top().first) {
            minima.pop();
        }
    }

public:
    AllOne() {
    }

    void inc(string key) {
        mp[key]++;
        maxima.push({mp[key], key});
        minima.push({mp[key], key});
    }

    void dec(string key) {
        mp[key]--;
        if (mp[key] == 0) {
            mp.erase(key);
        } else {
            maxima.push({mp[key], key});
            minima.push({mp[key], key});
        }
    }

    string getMaxKey() {
        cleanMaxima();
        return maxima.empty() ? "" : maxima.top().second;
    }

    string getMinKey() {
        cleanMinima();
        return minima.empty() ? "" : minima.top().second;
    }
};
