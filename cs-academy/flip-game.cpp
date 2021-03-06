#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define SCD(t) scanf("%d",&t);
#define SCLD(t) scanf("%ld",&t);
#define SCLLD(t) scanf("%lld",&t);
#define SCC(t) scanf("%c",&t);
#define SCS(t) scanf("%s",t);
#define SCF(t) scanf("%f",&t);
#define SCLF(t) scanf("%lf",&t);
#define Pd(t) printf("%d", t);
#define Pc(t) printf("%c", t);
#define NN putchar('\n');
#define SS putchar(' ');
#define MEM(a, b) memset(a, (b), sizeof(a));
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int ar[60][60];

void reverse(int i, int m){
    for(int j = 0;j<m;j++){
        ar[i][j] = !ar[i][j];
    }
    //printf("reverse:%d\n", i);
}

int main() {
#ifdef TTINPUT
    freopen("in.txt", "r", stdin);
#endif
    int m, n;
    //cin>>n>>m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i<n;i++){
        for(int j = 0; j<m;j++){
            //cin>>ar[i][j];
            scanf("%d", &ar[i][j]);
        }
    }

    for(int i = 0;i<n;i++){
        //printf("## %d\n", ar[i][0]);
        if(ar[i][0] == 0){
            reverse(i, m);
        }
    }

    long long ans = 0;
    long long posval = 1L << (m-1);
    ans += posval * n;

    for(int c = 1;c<m;c++){
        int pos = 0;
        for(int r = 0;r<n;r++){
            pos+= ar[r][c];
        }
        if(pos <= (n-pos)){
            pos = n - pos;
        }
        posval = posval >> 1;
        ans += posval * pos;
        //printf("c:%d count:%d ans:%lld\n", c, pos, posval);
    }
    //cout<<ans<<endl;
    printf("%lld\n", ans);
    return 0;
}