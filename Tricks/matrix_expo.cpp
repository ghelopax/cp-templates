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
#define matrix vector<vector<ll>>

const int maxN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 62;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

int sz;

void add(ll &a, ll b)
{
    a = (a + b % MOD) % MOD;
}

matrix idenmat()
{
    matrix res(sz, vector<ll>(sz, 0));

    for (int i = 0; i < sz; ++i)
        res[i][i] = 1;

    return res;
}

matrix mul(matrix &a, matrix &b)
{
    matrix res(sz, vector<ll>(sz, 0));

    for (int i = 0; i < sz; ++i)
        for (int j = 0; j < sz; ++j)
            for (int k = 0; k < sz; ++k)
                add(res[i][j], a[i][k] * b[k][j]);

    return res;
}

matrix expo(matrix &a, ll n)
{
    matrix res = idenmat();

    for (matrix b(a); n > 0; n >>= 1, b = mul(b, b))
        if (n & 1) res = mul(res, b);
    
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    

    return 0;
}