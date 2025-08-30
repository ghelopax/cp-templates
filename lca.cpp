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

const int maxN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))

// Tree
vector<int> child[maxN]; // hoặc sử dụng adj và kiểm tra v != p
int h[maxN];

// LCA
int up[LG + 1][maxN];

void calc(int u)
{
    for (int v : child[u])
    {
        up[0][v] = u;
        for (int j = 1; j <= LG; ++j)
        {
            up[j][v] = up[j - 1][up[j - 1][v]];
        }

        h[v] = h[u] + 1;

        calc(v);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);

    int k = h[u] - h[v];

    for (int j = 0; j <= LG; ++j)
    {
        if ((k >> j) & 1)
        {
            u = up[j][u];
        }
    }

    if (u == v)
        return u;

    for (int j = LG; j >= 0; --j)
    {
        if (up[j][u] != up[j][v])
        {
            u = up[j][u];
            v = up[j][v];
        }
    }

    return up[0][u];
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