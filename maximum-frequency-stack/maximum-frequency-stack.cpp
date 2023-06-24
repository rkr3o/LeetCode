class FreqStack {
public:
    int pos = 0;
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>mp;
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.push({++mp[val],{pos++,val}});
    }
     
    int pop() {
        if(pq.empty())return -1;
        auto x = pq.top();
        pq.pop();
        int val = x.second.second;
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */