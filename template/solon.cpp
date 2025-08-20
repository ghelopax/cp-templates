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

#define int long long
#define pii pair<int, int>
#define el "\n"
#define ldb long double
#define INF LLONG_MAX
#define MOD (int)(1e9 + 7)
#define maxN (int)(1e5 + 5)
#define pb push_back
#define eb emplace_back
#define mask(i) (1LL << i)
#define _for(i, l, r) for (int i = l; i <= r; ++i)

string congSL(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.size() > b.size())
        b += "0";

    int sz = a.size();
    int rem = 0;
    string res = "";

    for (int i = 0; i < sz; ++i)
    {
        int nxt = (a[i] - '0') + (b[i] - '0');

        if (rem)
            ++nxt;

        if (nxt > 9)
            ++rem;

        res += ('0' + (nxt % 10));
    }

    reverse(res.begin(), res.end());

    return res;
}

string truSL(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while (a.size() > b.size())
        b += "0";

    int sz = a.size();
    int rem = 0;
    string res = "";

    for (int i = 0; i < sz; ++i)
    {
        int nxt = a[i] - b[i];

        if (rem)
            --nxt;

        if (nxt < 0)
            ++rem;

        res += ('0' + ((10 + nxt) % 10));
    }

    reverse(res.begin(), res.end());

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
