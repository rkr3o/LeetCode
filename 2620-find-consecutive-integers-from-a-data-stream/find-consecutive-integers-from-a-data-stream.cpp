class DataStream {
public:
    int cnt = 0;
    int target , k;
    DataStream(int _value, int _k) {
        target=_value;
        k = _k;
    }
    
    bool consec(int num) {
        if(num==target)
        {
            cnt++;
        }
        else
        {
            cnt=0;
           
        }
        return cnt>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */