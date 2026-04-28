#include<bits/stdc++.h>
#define I first
#define II second
#define ii pair<int,int>
#define lg2(n) (31 - __builtin_clz(n))
#define ll long long
#define it array<int, 3>
using namespace std;
const long long P = 1e9+7;
const int N = 1e5+10;
const int INF = 1e9;
void input()
{
    #define TASKNAME ""
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        if (fopen(TASKNAME".inp","r" )) {
            freopen(TASKNAME".inp","r",stdin);
            freopen(TASKNAME".out","w",stdout); }
}
bool vis[N];
int col[N];
int d[N];
vector<int> g[N];
it A[N];
int n, m, k;
void bfs(int u, int r, int c) {
  d[u]=r;
  if(col[u]==0) col[u]=c;
    queue<int> q;
    q.push(u);
    while (q.empty()==0) {
        int x=q.front();
        q.pop();
        for (auto i:g[x]) {
          if ( d[x]>=d[i]+1 && d[i]>=0 ) {
            if(col[i]==0) col[i]=c;
            d[i]=d[x]-1;
        q.push(i);
                }
        }
    }
}
int main () {
    input ();
    fill(col+1, col+1+N, 0);
    bool check=0;
cin >> n >> m;
int cnt=0;
for (int i=1; i<=m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    }
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
      cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    for (int i=q; i>=1; i--) {
      bfs(A[i][0], A[i][1], A[i][2]);
    }
    for (int i=1; i<=n; i++) {
      cout << col[i] << '\n';
    }
    return 0;
}   