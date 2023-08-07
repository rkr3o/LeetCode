class Solution {
public:

using ll = long long int ;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
 
ll expo(ll a , ll b , ll m) { a = a % m ; ll res = 1; while (b > 0) {if (b & 1)res = res * a % m; a = a * a % m; b >>= 1;} return res;}
ll mminvPrime(ll a , ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a , ll b , ll m) {a = a % m ; b = b % m; return (mod_mul(a, mminvPrime(b, m), b) + m) % m;} //only for prime}
 
//compute hash
//(s[0]+s[1]*p+s[2]*p^2+s[3]*p^4)%mod;
//compute hash
vector<ll> hshPrefixes;
vector<ll> powers;
 
void calculateHashPrefixes(const string& s) {
    int n = s.size();
    const int p = 50;
    hshPrefixes.clear();
    powers.resize(n, 1);
    //precompute p^k
    for (int i = 1; i < n; ++i) {
        powers[i] = (powers[i - 1] * p) % mod;
    }
    //precompute hash
    for (int i = 0; i < n; i++) {
        int character = s[i] - 'a' + 1;
        if (i == 0)
            hshPrefixes.push_back(character);
        else
            hshPrefixes.push_back((hshPrefixes[i - 1] + character * powers[i]) % mod);
    }
}
 
ll substringHash(int l, int r) {
    //ans = h[r] - h[l-1] / p^l;
 
    if (l == 0) return hshPrefixes[r];
    ll a = mod_sub(hshPrefixes[r], hshPrefixes[l - 1], mod);
    ll b = powers[l];
    ll modInverse = expo(b, mod - 2, mod);
    return (a * modInverse) % mod;
}
 
ll compute_hash(string const& s) {
    const int p = 50;
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash_value;
}
string findBorders(const string& s) {
    string p = s;
    reverse(p.begin(), p.end()); // Reverse the string to find suffixes.
 
    int n = s.size();
    calculateHashPrefixes(s);
    ll y = compute_hash(p);
 
    vector<int> borderLengths;
    for (int i = 0; i < n - 1; i++) {
        if (substringHash(0, i) == substringHash(n - 1 - i, n - 1)) {
            borderLengths.push_back(i + 1);
        }
    }
 
    if (borderLengths.empty()) {
       return "";
    }
    
    // Find the longest happy prefix
        int longestLength = *max_element(borderLengths.begin(), borderLengths.end());
        return s.substr(0, longestLength);
}
    string longestPrefix(string s) {
        return findBorders(s);
    }
};