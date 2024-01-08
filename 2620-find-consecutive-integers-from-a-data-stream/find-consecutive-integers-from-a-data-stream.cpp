class DataStream {
public:
    int cnt = 1;
    int target , k;
    DataStream(int _value, int _k) {
        target=_value;
        k = _k;
    }
    
    bool consec(int num) {
        if(num==target and cnt>=k)
        {
            cnt++;
            return true;
        }
        else if(num==target and cnt < k)
        {
            cnt++;
            return false;
        }
        else{
            cnt=1;
            return false;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */