class MedianFinder {
public:
    priority_queue<int>maxima;
    priority_queue<int,vector<int>,greater<int>>minima;
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
         if(maxima.empty() || num<=maxima.top())
         {
             maxima.push(num);
         }    
         else
         {
             minima.push(num);
         }

         //balance the size
         if(maxima.size()>minima.size()+1)
         {
             int x = maxima.top();
             maxima.pop();
             minima.push(x);
         }
         else if(minima.size()>maxima.size())
         {
             int x = minima.top();
             minima.pop();
             maxima.push(x);
         }

    }
    
    double findMedian() {
        if(maxima.size()>minima.size())return maxima.top();
         return (maxima.top()+minima.top())/2.0;
    }
};
 