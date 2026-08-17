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
#define pii pair<int, int>

const int maxN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll INFLL = 4e18;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define MID(l, r) ((l) + (((r) - (l)) >> 1))

// Tree Diameter
    pii farthest(vector<int> *_adj, int _N, int s)
    {
        pii res(-1, 0);

        vector<bool> _vst(_N + 1, 0);
        queue<pii> q;
        q.emplace(s, 0);
        _vst[s] = true;

        while (!q.empty())
        {
            int u, du;
            tie(u, du) = q.front(); q.pop();

            if (res.second < du)
            {
                res.second = du;
                res.first = u;
            }

            for (const int &v : _adj[u])
            {
                if (_vst[v]) continue;
                _vst[v] = true;
                q.emplace(v, du + 1);
            }
        }

        return res;
    }

    int diameter(vector<int> *_adj, int _N)
    {
        int A = farthest(_adj, _N, 1).first;
        if (A == -1) return 0;
        return farthest(_adj, _N, A).second;
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
