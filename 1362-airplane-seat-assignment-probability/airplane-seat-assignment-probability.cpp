class Solution {
public:

    double nthPersonGetsNthSeat(int n) {
        if (n == 1) {
            return 1.0; 
        }
        return 1.0 / n + (n - 2.0) / n * nthPersonGetsNthSeat(n - 1);

    }
};
/*
there will be two cases
if n=1 -> there's only one passenger, they will always get their own seat
in other case
total probability = Probability for the nth person is 1/n for getting the first seat and (n-2)/n for getting the others
and
Probability of getting other seats is calculated recursively for n-1 passengers
*/