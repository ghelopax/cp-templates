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

const int maxN = 2e5 + 5;
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
#define FOR(i, l, r) for (ll i = (l); i <= (ll)(r); ++i)

struct DATA
{
    ll value;

    DATA(ll _value = 0) 
    {
        value = (_value % MOD + MOD) % MOD;
    }

    DATA operator+(const DATA &o) const
    {
        ll res = value;
        res += o.value;
        if (res >= MOD) res -= MOD;
        return DATA(res);
    }

    DATA operator*(const DATA &o) const
    {
        return DATA((value * o.value) % MOD);
    }

    void operator+=(const DATA &o)
    {
        value += o.value;
        if (value >= MOD) value -= MOD;
    }

    void operator=(const ll w)
    {
        value = w;
    }

    bool operator==(const ll o) const
    {
        return value == o;
    }

    DATA sqre()
    {
        return *this * *this;
    }

    DATA cube()
    {
        return sqre() * *this;
    }
};

int N, Q;
ll a[maxN];

void input()
{
    cin >> N >> Q;

    FOR(i, 1, N) cin >> a[i];
}

namespace Subtask_1
{
    bool constraint()
    {
        return N <= 2e3 && Q <= 2e3;
    }

    DATA arr[maxN];

    void preprocess()
    {
        FOR(i, 1, N) arr[i] = DATA(a[i]);
    }

    void query()
    {
        char type;
        cin >> type;

        if (type == '0')
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;

            FOR(i, l, r) arr[i] = DATA(val);
        }
        else if (type == '1')
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;

            FOR(i, l, r) arr[i] += DATA(val);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            DATA ans(0);
            FOR(i, l, r) ans += arr[i].cube();
            cout << ans.value << el;
        }
    }

    void run()
    {
        preprocess();
        while(Q--) query();
    }
}

namespace Subtask_5
{
    bool constraint()
    {
        return true;
    }

    struct Segment_Tree
    {
        private:
        struct Node
        {
            // sum of x^3, x^2, x
            DATA cb, sq, sm;

            Node() : cb(0), sq(0), sm(0) {}
            Node(ll _cb, ll _sq, ll _sm) : cb(_cb), sq(_sq), sm(_sm) {}
            Node(DATA _cb, DATA _sq, DATA _sm) : cb(_cb), sq(_sq), sm(_sm) {}

            Node operator+(const Node &o) const
            {
                return Node(cb + o.cb, sq + o.sq, sm + o.sm);
            }
        };

        struct Tag
        {
            // x -> ax + b
            DATA a, b;

            Tag() : a(1), b(0) {}
            Tag(DATA _a, DATA _b) : a(_a), b(_b) {}

            bool empty()
            {
                return a == 1 && b == 0;
            }

            void reset()
            {
                a = 1;
                b = 0;
            }

            void compose(const Tag &o)
            {
                a = o.a * a;
                b = o.a * b + o.b;
            }
        };

        Node ST[4 * maxN];
        Tag LZ[4 * maxN];

        void apply(Node &cur, Tag t, DATA len)
        {
            if (t.a == 1)
            {
                cur.cb += DATA(3) * (t.b * cur.sq + t.b.sqre() * cur.sm) + t.b.cube() * len;
                cur.sq += DATA(2) * t.b * cur.sm + t.b.sqre() * len;
                cur.sm += t.b * len;
            }
            else
            {
                cur.cb = t.b.cube();
                cur.sq = t.b.sqre();
                cur.sm = t.b;
            }
        }

        void down(int id, int l, int r)
        {
            if (LZ[id].empty()) return;

            if (l != r)
            {
                int mid = MID(l, r);

                apply(ST[id << 1], LZ[id], mid - l + 1);
                apply(ST[id << 1 | 1], LZ[id], r - mid);
                
                LZ[id << 1].compose(LZ[id]);
                LZ[id << 1 | 1].compose(LZ[id]);
            }

            LZ[id].reset();
        }

        void build(int id, int l, int r)
        {
            if (l == r)
            {
                ST[id] = Node(
                    DATA(a[l]).cube(),
                    DATA(a[l]).sqre(),
                    DATA(a[l])
                );

                return;
            }

            int mid = MID(l, r);

            build(id << 1, l, mid);
            build(id << 1 | 1, mid + 1, r);

            ST[id] = ST[id << 1] + ST[id << 1 | 1];
        }

        void update(int id, int l, int r, int u, int v, ll a, ll b)
        {
            if (u <= l && r <= v)
            {
                apply(ST[id], Tag(a, b), r - l + 1);
                LZ[id].compose(Tag(a, b));
                return;
            }

            if (r < u || v < l) return;

            down(id, l, r);

            int mid = MID(l, r);

            update(id << 1, l, mid, u, v, a, b);
            update(id << 1 | 1, mid + 1, r, u, v, a, b);

            ST[id] = ST[id << 1] + ST[id << 1 | 1];
        }

        DATA get(int id, int l, int r, int u, int v)
        {
            if (u <= l && r <= v)
                return ST[id].cb;

            if (r < u || v < l) return 0;

            down(id, l, r);

            int mid = MID(l, r);

            return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
        }

        public:
        void build()
        {
            build(1, 1, N);
        }

        void update(int l, int r, ll w, bool mode)
        {
            if (mode)
                update(1, 1, N, l, r, 1, w);
            else
                update(1, 1, N, l, r, 0, w);
        }

        DATA get(int l, int r)
        {
            return get(1, 1, N, l, r);
        }
    } ST;

    void preprocess()
    {
        ST.build();
    }

    void query()
    {
        char type;
        cin >> type;

        if (type == '0')
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;

            ST.update(l, r, val, 0);
        }
        else if (type == '1')
        {
            int l, r;
            ll val;
            cin >> l >> r >> val;

            ST.update(l, r, val, 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;

            cout << ST.get(l, r).value << el;
        }
    }

    void run()
    {
        preprocess();
        while(Q--) query();
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    input();

    if (Subtask_1::constraint()) return Subtask_1::run(), 0;
    if (Subtask_5::constraint()) return Subtask_5::run(), 0;

    return 0;
}