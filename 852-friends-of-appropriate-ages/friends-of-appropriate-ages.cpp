class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCount(121, 0); // Age count array, maximum age is 120

        // Count the number of people in each age group
        for (int age : ages) {
            ageCount[age]++;
        }

        int cnt = 0;

        // Calculate the number of friend requests for each age group
        for (int ageA = 1; ageA <= 120; ageA++) {
            int countA = ageCount[ageA];
            for (int ageB = 0.5 * ageA + 8; ageB <= ageA; ageB++) {
                int countB = ageCount[ageB];

                // Don't count requests from a person to themselves
                if (ageA == ageB) {
                    cnt += countA * (countA - 1);
                } else {
                    cnt += countA * countB;
                }
            }
        }

        return cnt;
    }
};
