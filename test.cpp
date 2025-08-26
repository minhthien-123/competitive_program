#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
//#include<conio.h>

using namespace std;

struct node{
     int gt,id;
};

struct query{
      int k,id,dau,cuoi;
};
int a[31111],n;
int f[31111];
int s[31111];
int KQ[211111];
node A[31111];
query Q[211111];

inline bool cmp(const node &a,const node &b){ return a.gt > b.gt;}
inline bool cmp2(const query &a, const query &b){ return a.id < b.id;}
inline bool cmp1(const query &a, const query &b){ return a.k > b.k;}

inline int count(int x){
     int kq = 0;
     while(x){
          kq+= a[x], x-=x&-x;
     }
     return kq;
}

inline void update(int x,const int tang){
     while(x<=n){
          a[x]+=tang;
          x+=x&-x;
     }
}

int main(){
    // freopen("KQUERY.in","r",stdin);
     int so,a,b,c;
     scanf("%d",&n);
     for(int i = 1;i<=n;i++){
          scanf("%d",&a);
          A[i].gt = a;
          A[i].id = i;
     }
     scanf("%d",&so);
     for(int i = 1;i<=so;i++){
          scanf("%d %d %d",&a,&b,&c);
          Q[i].dau = a;
          Q[i].cuoi = b;
          Q[i].k = c;
          Q[i].id = i;
          KQ[i] = b-a+1;
     }
     //sort(A+1,A+n+1,cmp);
     sort(Q+1,Q+so+1,cmp1);
     int st = 1;
     for(int i = 1;i<=so && st<=n;){
          if(st<=n && Q[i].k<A[st].gt){
                update(A[st].id,1);
                ++st;
          }
          else{
                KQ[Q[i].id] = count(Q[i].cuoi) - count(Q[i].dau-1);
                ++i;
          }
     }
     for(int i = 1;i<=so;i++) printf("%d\n",KQ[i]);
    // getch();
}
