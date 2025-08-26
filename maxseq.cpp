#include<bits/stdc++.h>
using namespace std;

const int MaxN = 5 + 1e5;

long long n, a[MaxN], q;

class SegmentTree{

    long long low[4 * MaxN], high[4 * MaxN], TNode[4 * MaxN], leaf[MaxN], qi, qj;

    long long Find(long long index){
        if(qi > high[index] || qj < low[index]) return -1e9;
        if(qi <= low[index] && high[index] <= qj) return TNode[index];
        return max(Find(index * 2), Find(index * 2 + 1));
    }

    public:
        void Build(long long index, long long l, long long r){
            low[index] = l;
            high[index] = r;
            if(l == r){
                TNode[index] = a[l];
                leaf[l] = index;
                return;
            }
            Build(index * 2, l, (l + r) / 2);
            Build(index * 2 + 1, (l + r) / 2 + 1, r);
            TNode[index] = max(TNode[index * 2], TNode[index * 2 + 1]);
        }

        long long Query(long long l, long long r){
            qi = l;
            qj = r;
            return Find(1);
        }
} SegmentTree;

int main(){
    freopen("maxseq.inp","r",stdin);
    freopen("maxseq.out","w",stdout);
    cin >> n >> q;
    for(long long i = 1 ; i <= n ; ++i) cin >> a[i];
    SegmentTree.Build(1, 1, n);
    while(q--){
        long long x, y;
        cin >> x >> y;
        cout << SegmentTree.Query(x, y) << endl;
    }

    return 0;
}
