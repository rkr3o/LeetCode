class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

    string result;

    // Determine the sign of the result
    if ((numerator < 0) ^ (denominator < 0)) {
        result += "-";
    }

    // Convert numerator and denominator to long to avoid integer overflow
    long long num = abs(static_cast<long long>(numerator));
    long long den = abs(static_cast<long long>(denominator));

    // Add the integral part
    result += to_string(num / den);

    // If the result is an integer, return it
    if (num % den == 0) return result;

    // Add the decimal point
    result += ".";

    // Map to store remainders and their corresponding indices
    unordered_map<long long, int> remainderMap;

    // Initialize remainder
    long long remainder = num % den;

    while (remainder != 0) {
        // If the remainder repeats, enclose it in parentheses
        if (remainderMap.find(remainder) != remainderMap.end()) {
            result.insert(remainderMap[remainder], "(");
            result += ")";
            break;
        }

        // Record the current remainder and its index
        remainderMap[remainder] = result.size();

        // Perform long division to compute the next digit
        remainder *= 10;
        result += to_string(remainder / den);
        remainder %= den;
    }

    return result;
    }
};