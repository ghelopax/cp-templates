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

struct Data
{
    ll value;

    Data() : value(0) {}
    Data(ll _value) 
    {
        value = (_value % MOD + MOD) % MOD;
    }

    void operator=(const ll w)
    {
        value = w;
    }

    bool operator==(const ll w)
    {
        return value == w;
    }

    Data operator+(const Data &o) const
    {
        return Data(value + o.value);
    }

    Data operator*(const Data &o) const
    {
        return Data(value * o.value);
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
        return true;
    }

    struct Segment_Tree
    {
        private:
        ll *p;

        struct Tag
        {
            Data a, b;

            Tag() : a(1), b(0) {}
            Tag(ll _a, ll _b) : a(_a), b(_b) {}
            Tag(Data _a, Data _b) : a(_a), b(_b) {}

            void compose(const Tag o)
            {
                a = o.a * a;
                b = o.a * b + o.b;
            }

            bool empty()
            {
                return (a == 1 && b == 0);
            }

            void reset()
            {
                a = 1; b = 0;
            }
        } LZ[4 * maxN];

        struct Node
        {
            Data sum;

            Node() : sum(0) {}
            Node(Data _sum) : sum(_sum) {}

            Node operator+(const Node &o) const
            {
                return Node(sum + o.sum);
            }

            void apply(Tag t, Data len)
            {
                sum = t.a * sum + t.b * len;
            }
        } ST[4 * maxN];

        void build(int id, int l, int r)
        {
            if (l == r)
            {
                ST[id] = Node(
                    Data(p[l])
                );
                return;
            }

            int mid = MID(l, r);

            build(id << 1, l, mid);
            build(id << 1 | 1, mid + 1, r);

            ST[id] = ST[id << 1] + ST[id << 1 | 1];
        }

        void down(int id, int l, int r)
        {
            if (LZ[id].empty()) return;

            if (l != r)
            {
                int mid = MID(l, r);

                ST[id << 1].apply(LZ[id], mid - l + 1);
                ST[id << 1 | 1].apply(LZ[id], r - mid);

                LZ[id << 1].compose(LZ[id]);
                LZ[id << 1 | 1].compose(LZ[id]);
            }

            LZ[id].reset();
        }

        void update(int id, int l, int r, int u, int v, Tag t)
        {
            if (r < u || v < l) return;

            if (u <= l && r <= v)
            {
                ST[id].apply(t, r - l + 1);
                LZ[id].compose(t);
                return;
            }

            down(id, l, r);

            int mid = MID(l, r);

            update(id << 1, l, mid, u, v, t);
            update(id << 1 | 1, mid + 1, r, u, v, t);

            ST[id] = ST[id << 1] + ST[id << 1 | 1];
        }

        Data get(int id, int l, int r, int u, int v)
        {
            if (r < u || v < l) return Data(0);

            if (u <= l && r <= v)
                return ST[id].sum;

            down(id, l, r);

            int mid = MID(l, r);

            return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
        }

        public:
        Segment_Tree(ll *_p) : p(_p) {}

        void build()
        {
            build(1, 1, N);
        }

        void update(char type, int l, int r, ll w)
        {
            if (type == '1')
                update(1, 1, N, l, r, Tag(1, w));
            else if (type == '2')
                update(1, 1, N, l, r, Tag(w, 0));
            else
                update(1, 1, N, l, r, Tag(0, w));
        }

        ll get(int l, int r)
        {
            return get(1, 1, N, l, r).value;
        }
    } ST(a);

    void preprocess()
    {
        ST.build();
    }

    void query()
    {
        char type;
        int l, r;
        cin >> type >> l >> r;

        if (type != '4')
        {
            ll x; cin >> x;

            ST.update(type, l, r, x);
        }
        else
            cout << ST.get(l, r) << el;
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

    return 0;
}