class FreqStack {
private:
    map<int, int, greater<int>> freqMap;
    map<int, stack<int>, greater<int>> freqStackMap;
    
public:
    FreqStack() {}
    void push(int val) {
        int freq = ++freqMap[val];
        freqStackMap[freq].push(val);
    }
    int pop() {
        auto maxFreqIt = freqStackMap.begin();
        int val = maxFreqIt->second.top();
        maxFreqIt->second.pop();
        
        if (maxFreqIt->second.empty()) {
            freqStackMap.erase(maxFreqIt);
        }
        
        freqMap[val]--;
        return val;
    }
};
