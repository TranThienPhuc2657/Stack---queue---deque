#include <bits/stdc++.h>
using namespace std;
#define file(name) if (fopen(name".inp","r")) {freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define REP(i,n) for (int i=0; i<n; i++)
#define REPD(i,n) for (int i=n-1; i>=0; i--)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define ll long long
#define vi vector <int>
#define pii pair <int,int>
#define INF LLONG_MAX
const int N=1e6+5;

ll n,a[N],maxl[N],maxr[N],minl[N],minr[N],res;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    file("WEIGHT");

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    stack <int> maxx,minn;
    FOR(i,1,n) {
        while (!maxx.empty() and a[maxx.top()]<a[i]) {maxr[maxx.top()]=i-1-maxx.top(); maxx.pop();}
        while (!minn.empty() and a[minn.top()]>a[i]) {minr[minn.top()]=i-1-minn.top(); minn.pop();}
        if (maxx.empty()) maxl[i]=i-1; else maxl[i]=i-maxx.top()-1;
        if (minn.empty()) minl[i]=i-1; else minl[i]=i-minn.top()-1;
        maxx.push(i); minn.push(i);
    }
    while(!maxx.empty()) {maxr[maxx.top()]=n-maxx.top(); maxx.pop();}
    while(!minn.empty()) {minr[minn.top()]=n-minn.top(); minn.pop();}
    FOR(i,1,n) res+=((maxl[i]+1)*(maxr[i]+1)-(minl[i]+1)*(minr[i]+1))*a[i];
    cout << res;
    return 0;
}

