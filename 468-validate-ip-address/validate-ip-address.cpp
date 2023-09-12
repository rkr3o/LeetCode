#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) {
            return "IPv4";
        } else if (isValidIPv6(IP)) {
            return "IPv6";
        }
        return "Neither";
    }

private:
    bool isValidIPv4(const string& IP) {
        if (IP.length() > 15) {
            return false;
        }

        int count = 0;
        size_t start = 0;
        size_t end = IP.find('.');
        while (end != string::npos) {
            count++;
            string s = IP.substr(start, end - start);
            if (!isValidIPv4Part(s)) {
                return false;
            }
            start = end + 1;
            end = IP.find('.', start);
        }

        if (count != 3) {
            return false;
        }

        string s = IP.substr(start);
        return isValidIPv4Part(s);
    }

    bool isValidIPv4Part(const string& part) {
        if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) {
            return false;
        }
        int num = 0;
        for (char c : part) {
            if (!isdigit(c)) {
                return false;
            }
            num = num * 10 + (c - '0');
        }
        return num >= 0 && num <= 255;
    }

    bool isValidIPv6(const string& IP) {
        if (IP.length() > 39) {
            return false;
        }

        int count = 0;
        size_t start = 0;
        size_t end = IP.find(':');
        while (end != string::npos) {
            count++;
            string s = IP.substr(start, end - start);
            if (!isValidIPv6Part(s)) {
                return false;
            }
            start = end + 1;
            end = IP.find(':', start);
        }

        if (count != 7) {
            return false;
        }

        string s = IP.substr(start);
        return isValidIPv6Part(s);
    }

    bool isValidIPv6Part(const string& part) {
        if (part.empty() || part.size() > 4) {
            return false;
        }
        for (char c : part) {
            if (!isxdigit(c)) {
                return false;
            }
        }
        return true;
    }
};
