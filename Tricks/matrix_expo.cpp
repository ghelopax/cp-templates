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
#define mat vector<vector<ll>>

const int maxN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFLL = 4e18;
const int LG = 62;

#define el "\n"
#define pb push_back
#define eb emplace_back
#define MASK(i) (1LL << (i))
#define BIT(msk, i) (((msk) >> (i)) & 1LL)
#define MID(l, r) ((l) + (((r) - (l)) >> 1))
#define lsb(x) ((x) & -(x))

// Matrix Exponentiation
void add(ll &x, ll w)
{
    x = (x + w % MOD) % MOD;
}

struct matrix
{
    int row, col;
    mat m;

    matrix() {}
    matrix(int _row, int _col) : row(_row), col(_col), m(_row, vector<ll>(_col, 0)) {}
    matrix(mat v) : row(v.size()), col(v[0].size()), m(v) {}

    void iden()
    {
        for (int i = 0; i < row; ++i)
            m[i][i] = 1;
    }
    
    vector<ll>& operator[](int i) { return m[i]; }

    matrix operator*(matrix &o)
    {
        matrix res(row, o.col);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < o.col; ++j)
            {
                for (int k = 0; k < col; ++k)
                {
                    add(res[i][j], m[i][k] * o[k][j]);
                }
            }
        }

        return res;
    }

    matrix expo(ll x)
    {
        matrix res(row, row);
        res.iden();
        matrix b = *this;

        for (ll i = 0; i < LG; ++i)
        {
            if (BIT(x, i))
                res = res * b;
            
            b = b * b;
        }
        
        return res;
    }

    void print()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << m[i][j] << ' ';
            }
            cout << el;
        }
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    

    return 0;
}