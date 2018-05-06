#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define dream_hyojooslh

using namespace std;
const int N=51,base=1000000007;
int n,m,f[N][1<<5][1<<5][1<<5],a[N],nn[1<<5],nn1[1<<5],nn2[1<<5],lay[1<<5][1<<5],rev[1<<5];

inline int getbit(int i,int j) {
    return ((i>>(j-1))&1);
}

inline void onbit(int &i,int j) {
    i=i|(1<<(j-1));
}

inline int chuyen(int i) {
    int a=0;
    For(j,1,m-1) if (getbit(i,j+1)) onbit(a,j);
    return a;
}

inline int chuyen1(int i) {
    int a=0;
    For(j,2,m) if (getbit(i,j-1)) onbit(a,j);
    return a;
}

inline int chuyen2(int i) {
    int a=0;
    For(j,1,m) if (!getbit(i,j)) onbit(a,j);
    return a;
}

inline void them(int &a,int b) {
    a=(a+b)%base;
}

void Init(){
    int nnn=1<<m;
    memset(f,0,sizeof(f));
    f[0][0][0][0]=1;
    For(i,0,nnn-1) {
        nn[i]=i;
        nn1[i]=chuyen(i);
        nn2[i]=chuyen1(i);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("dream_hyojooslh.inp","r",stdin);
    int t ;
    int nnn=1<<5;
    cin>>t;
    For(i,0,nnn-1) {
            For(j,0,nnn-1) if ((i&j)==j) {
                lay[i][j]=true;
                For(x,1,5) For(y,x+1,5) if (getbit(j,x)&&getbit(j,y)) {
                    bool st=true;
                    For(k,x,y) if (getbit(i,k)==0) st=false;
                    if (st) lay[i][j]=false;
                }
            }
        }
    For(i,1,t) {
        cin>>n>>m;
        int nnn=1<<m;
        Init();
        For(i,1,n) {
            a[i]=0;
            For(j,1,m) {
                char s;
                cin>>s;
                if (s=='.') onbit(a[i],j);
            }
        }
        For(i,0,nnn-1) rev[i]=chuyen2(i);
        int res=0;
        For(i,1,n) For(j,0,nnn-1) For(k,0,nnn-1) For(h,0,nnn-1) if (f[i-1][j][k][h]) {
            int t=nn[j]|nn1[k]|nn2[h];
            t=rev[t];
            int nnn3=(nn[j]&a[i]);
            int nnn1=(nn1[k]&a[i]);
            int nnn2=(nn2[h]&a[i]);
            For(mmm,0,nnn-1) if (lay[a[i]][mmm]&&((t&mmm)==mmm))
                them(f[i][nnn3|mmm][nnn1|mmm][nnn2|mmm],f[i-1][j][k][h]);
        }
        For(j,0,nnn-1) For(k,0,nnn-1) For(h,0,nnn-1) them(res,f[n][j][k][h]);
        printf("%d\n",res-1);
    }
    return 0;
}
