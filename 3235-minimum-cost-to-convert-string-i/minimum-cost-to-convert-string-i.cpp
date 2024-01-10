class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a' ;
            dist[u][v] = min(dist[u][v],(long long)cost[i]);
        }
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], (long long)dist[i][via] + dist[via][j]);
                }
            }
        }
        long long sum = 0;
        for (int i = 0; i < source.size(); i++) {
            if(source[i]==target[i])continue;
            
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            
            if (dist[row][col] == INT_MAX) {
                return -1;
            }
            sum += dist[row][col];
        }
        return sum;
    }
};
