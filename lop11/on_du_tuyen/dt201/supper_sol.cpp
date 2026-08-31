#include <bits/stdc++.h>
#define MAXA 1000001
#define MAXP 78498

using namespace std;

struct node{
    long long p,q;
    node()
    {
        p = 1;
        q = 0;
    }
};

node IT[MAXP * 8];
int p[MAXA];
int primes[MAXP];
int d[MAXP];
int n_primes;
int q,t,a,b;
int BASE;

void sangnt()
{
    n_primes = 0;
    memset(p,-1,sizeof(p));
    for (int i = 2; i < MAXA; ++i)
    {
        if (p[i] != -1) continue;
        primes[n_primes] = i;
        p[i] = n_primes;
        long long j = (long long)(i) * i;
        while (j < MAXA)
        {
            p[j] = n_primes;
            j += i;
        }
        ++n_primes;
    }
//    for (int i = 0; i < n_primes; ++i)
//        cout << primes[i] << endl;
}

long long GCD(long long a, long long b)
{
    while (a > 0 && b > 0)
    {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

long long pow(long long a, long long b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    long long res = pow(a,b/2);
    res = res * res % BASE;
    if (b % 2) res = res * a % BASE;
    return res;
}

void update_IT(int i,int l, int r, int x)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        IT[i].p = primes[x];
        IT[i].q = d[x];
        //cout << i << " " << l << " " << r << " " << x << " " << IT[i].p << " " << IT[i].q << endl;
        return;
    }
    int m =(l+r)/2;
    update_IT(2*i+1,l,m,x);
    update_IT(2*i+2,m+1,r,x);
    IT[i].q = GCD(IT[2*i+1].q,IT[2*i+2].q);
    if (IT[i].q == 0) IT[i].p = 1;
    else IT[i].p = pow(IT[2*i+1].p,IT[2*i+1].q/IT[i].q) * pow(IT[2*i+2].p,IT[2*i+2].q/IT[i].q) % BASE;
    //cout << i << " " << l << " " << r << " " << x << " " << IT[i].p << " " << IT[i].q << endl;
}

void update(int a, int b, int c)
{
    int i;
    while (a > 1)
    {
        i = p[a];
        d[i] += b * c;
        a /= primes[i];
        //cout << i << " " << primes[i] << " " << d[i] << endl;
        update_IT(0,0,MAXP-1,i);
    }
}

int main()
{
    freopen("supper.inp","r",stdin);
    freopen("supper.out","w",stdout);
    sangnt();
    cin >> BASE >> q;
    while(q--)
    {
        cin >> t;
        //cout << "Q: " << 100 - q << " " << t << endl;
        if (t == 1)
        {
            cin >> a >> b;
            update(a,b,1);
            //cout << IT[0].p << " " << IT[0].q << endl;
        }
        else if (t == 2)
        {
            cin >> a >> b;
            update(a,b,-1);
            //cout << IT[0].p << " " << IT[0].q << endl;
        }
        else if (t == 3)
        {
            if (IT[0].q == 0) cout << "1 1" << endl;
            else cout << IT[0].p << " " << IT[0].q << endl;
        }
    }
    return 0;
}
