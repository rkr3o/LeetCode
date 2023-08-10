class Solution {
public:
    int minSteps(string s1, string s2) {

        int count = 0;
        // store the count of character
        int char_count[26];
         
        for (int i = 0; i < 26; i++)
        {
            char_count[i] = 0;
        }
 
        // iterate though the first String
        // and update count
        for (int i = 0; i < s1.length(); i++)
            char_count[s1[i] - 'a']++;
 
        // iterate through the second string
        // update char_count.
        // if character is not found in
        // char_count then increase count
        for (int i = 0; i < s2.length(); i++)
        {
            char_count[s2[i] - 'a']--;      
        }
       
        for(int i = 0; i < 26; ++i)
        {
          if(char_count[i] != 0)
          {
            count+=abs(char_count[i]);
          }
        }
        return count / 2;
  
    }
};