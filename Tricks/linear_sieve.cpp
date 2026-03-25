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
const int maxA = 1e7 + 5;
const int maxP = 7e5; // ~ maxA / ln(maxA)
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

// Linear Sieve
ll spf[maxA];
ll p[maxP];

void init()
{
    spf[0] = spf[1] = 1;
    for (ll i = 2; i < maxA; ++i) 
        spf[i] = i;

    int cnt = 0;
    for (ll i = 2; i < maxA; ++i)
    {
        if (spf[i] == i) 
            p[cnt++] = i;
            
        for (int j = 0; j < cnt && p[j] * i < maxA; ++j)
        {
            spf[p[j] * i] = p[j];

            if (i % p[j] == 0) break;
        }
    }
}

void input()
{
}

void preprocess()
{
}

void solve() // or: query()
{
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    init();
    input();
    preprocess();
    solve(); // or: while(Q--) query();

    return 0;
}