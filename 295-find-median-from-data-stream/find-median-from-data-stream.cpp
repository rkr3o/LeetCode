class MedianFinder {
public:
    priority_queue<int>high;
    priority_queue<int,vector<int>,greater<int>>low;
    MedianFinder(){}
    void addNum(int num) {
        if(high.empty() || num<=high.top()){
            high.push(num);
        }
        else{
            low.push(num);
        }
        //balance both
        if(high.size() > low.size()+1){
            low.push(high.top());
            high.pop();
        }
        else if(low.size() > high.size())
        {
            high.push(low.top());
            low.pop();
        }
    }
    double findMedian() {
        if(high.size()>low.size())
            return high.top();
        return ((low.top()+high.top())/2.0);
    }
};