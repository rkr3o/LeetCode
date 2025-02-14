class ProductOfNumbers {
public:
    vector<int>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int n = ans.size();
        int prod = ans[n-k];
        for(int i = n-k+1; i<n; i++){
            prod*=ans[i];
        }
        return prod;
    }
};
