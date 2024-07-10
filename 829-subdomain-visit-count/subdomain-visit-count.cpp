class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainCount;
        
        for (const auto& cpdomain : cpdomains) {
            int spaceIndex = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, spaceIndex));
            string domain = cpdomain.substr(spaceIndex + 1);
            
            while (true) {
                domainCount[domain] += count;
                int dotIndex = domain.find('.');
                if (dotIndex == string::npos) break;
                domain = domain.substr(dotIndex + 1);
            }
        }
        
        vector<string> result;
        for (const auto& [domain, count] : domainCount) {
            result.push_back(to_string(count) + " " + domain);
        }
        
        return result;
    }
};