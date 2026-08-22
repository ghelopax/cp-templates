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

#define NAME "main"

#define ll long long
#define ldb long double

const int maxN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 20;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define BIT(msk, i) (((msk) >> (i)) & 1LL)
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))
#define FOR(i, l, r) for (int i = (l); i <= (int)(r); ++i)
#define FORLL(i, l, r) for (ll i = (l); i <= (ll)(r); ++i)
#define isz(v) (int)v.size()

int di[4] = {1, 0, 0, -1};
int dj[4] = {0, 1, -1, 0};

int N, M;
string a[maxN];

char arr(int i, int j) { return a[i - 1][j - 1]; }

void input()
{
    cin >> N >> M;

    FOR(i, 0, N - 1) cin >> a[i];
}

namespace Subtask_4
{
    bool constraint()
    {
        return true;
    }

    bool vst[maxN][maxN];
    int c[maxN][maxN];

    struct Node
    {
        int i, j;

        Node() : i(0), j(0) {}
        Node(int _i, int _j) : i(_i), j(_j) {}

        Node nxt(int k) { return Node(i + di[k], j + dj[k]); }
        bool valid() { return (i >= 1 && i <= N && j >= 1 && j <= M); }
        bool &visited() { return vst[i][j]; }
        int &cost() { return c[i][j]; }
        char value() { return arr(i, j); }
    };

    queue<Node> q;

    void ms_bfs()
    {
        while (!q.empty())
        {
            Node u = q.front(); q.pop();

            FOR(k, 0, 3)
            {
                Node v = u.nxt(k);
                if (!v.valid()) continue;
                if (v.visited()) continue;

                v.cost() = u.cost() + 1;
                v.visited() = true;
                q.push(v);
            }
        }
    }

    Node src, tgt;

    void dfs(Node u, int lim)
    {
        FOR(k, 0, 3)
        {
            Node v = u.nxt(k);
            if (!v.valid()) continue;
            if (v.visited()) continue;
            if (v.value() == 'X') continue;
            if (v.cost() < lim) continue;

            v.visited() = true;
            dfs(v, lim);
        }
    }

    bool check(int x)
    {
        memset(vst, 0, sizeof(vst));
        src.visited() = true;
        dfs(src, x);

        return tgt.visited();
    }

    void preprocess()
    {
        FOR(i, 1, N) FOR(j, 1, M) 
        {
            Node cur(i, j);
            switch (cur.value())
            {
                case 'X':
                {
                    cur.cost() = 0;
                    cur.visited() = true;
                    q.push(cur);   
                } break;
                case 'S': src = cur; break;
                case 'E': tgt = cur; break;
                default: break;
            }
        }
    }

    void solve()
    {
        ms_bfs();

        // FOR(i, 1, N) FOR(j, 1, M) cerr << c[i][j] << " \n"[j == M];

        int lo = 1, hi = src.cost();
        int ans = -1;
        while (lo <= hi)
        {
            int mid = MID(lo, hi);

            if (check(mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout << ans;
    }

    void run()
    {
        preprocess();
        solve();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (fopen(NAME".inp", "r"))
    {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }

    input();

    if (Subtask_4::constraint()) return Subtask_4::run(), 0;

    return 0;
}