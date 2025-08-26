#include <bits/stdc++.h>

using namespace std;

/*
 /\_/\  /\_/\  /\_/\  /\_/\
( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <
 /\_/\                /\_/\
( o.o )   ghelopax   ( o.o )
 > ^ <                > ^ <
 /\_/\  /\_/\  /\_/\  /\_/\
( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <
*/

#define ll long long
#define ldb long double

const int maxN = 1e6 + 5;
const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const ll BASE = 311;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))

// Hash

ll powb[maxN]; // BASE ^ idx

void preprocess() // calc powb
{
    powb[0] = 1;
    for (int i = 1; i < maxN; ++i)
    {
        powb[i] = powb[i - 1] * BASE;
        powb[i] %= MOD;
    }
}

void hbuild(const string &str, ll *h)
{
    h[0] = str[0];
    for (int i = 1; i < (int)(str.size()); ++i)
    {
        h[i] = (h[i - 1] * BASE) % MOD + str[i];
        h[i] %= MOD;
    }
}

ll hget(ll *h, int l, int r)
{
    if (l == 0)
        return h[r];

    // h[r] - h[l - 1] * BASE ^ (r - l + 1)
    return (h[r] - (h[l - 1] * powb[r - l + 1]) % MOD + MOD) % MOD;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    preprocess();

    return 0;
}