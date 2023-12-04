#include <iostream>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
         int maxima = -1; 
         for(int i = 0 ; i <= num.size()-3 ; i++)
         {
             if(num[i] == num[i+1] and num[i] == num[i+2])
             {
                  maxima = max(maxima,num[i]-'0');
             }
         }
         if(maxima==-1)return "";
         return string(3,maxima+'0');
    }
};

 