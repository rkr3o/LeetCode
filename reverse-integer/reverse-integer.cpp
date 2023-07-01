#include <algorithm> // Include the algorithm library for std::reverse
#include <stdexcept> // Include the std::out_of_range exception

class Solution {
public:
    int reverse(int x) 
    {
        if(x==0)return 0 ;
         string s = to_string((x));
         if (s.size() > 32) {
             return 0;
         }
         while (s.back() == '0') {
             s.pop_back(); 
         }
         std::reverse(s.begin(), s.end());
         int sign = s.back();
         if (sign == '-') {
              s.pop_back();
         }
         while (s.back() == '0') {
             s.pop_back();
         }
         int res = 0;
         try {
             res = std::stoi(s);
         } catch (const std::out_of_range&) {
             return 0;
         }
         if (sign == '-') {
             res = -res;
         }
         return res;   
    }
};
