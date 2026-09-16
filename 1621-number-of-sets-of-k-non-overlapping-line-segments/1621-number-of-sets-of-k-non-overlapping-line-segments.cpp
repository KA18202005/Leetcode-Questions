class Solution {
    using ll = long long;
    const ll mod = 1e9 + 7;
public:
    ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;
        vector<ll> fact(N + 1), invFact(N + 1);
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        invFact[N] = power(fact[N], mod - 2);
        for (int i = N; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % mod;
        }
        return fact[N] * invFact[R] % mod * invFact[N - R] % mod;
    }
};