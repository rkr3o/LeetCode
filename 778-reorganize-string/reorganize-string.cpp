class Solution {
public:
    string reorganizeString(string s) {
    priority_queue<pair<int,char>>pq;
	unordered_map<char,int>mp;
	string result = "";
	for(auto chr :s){
		mp[chr] ++;
	}
	for(auto &[x,y]:mp){
		pq.push({y,x}); // pushing the frequency first and then the number.
	}
	// since we are takin out the first 2 elements 
	// hence we did size>1 so that we can make sure there are atleast 2 elements
	while(pq.size()>1){ 
		auto top1 = pq.top();
		pq.pop();
		auto top2 = pq.top();
		pq.pop();
		result+= top1.second;
		result+= top2.second;
		top1.first--; // reducing the frequencies
		top2.first--; 
		if(top1.first>0){
			pq.push(top1);
		}
		if(top2.first>0){
			pq.push(top2);
		}
	}
	// cout<<pq.top().first;
	if(!pq.empty()){
		if(pq.top().first>1)
        {  // it even checks for string like "aaaaa"
			return "";
		}
		else{
			result+=pq.top().second;
			pq.pop();
		}
	}
	return result;
    }
};