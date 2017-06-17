/** Jai Shree Ram **/
/** ssavi. ICT-4 CoU **/

#include<bits/stdc++.h>
#define DIST(x1,x2, y1, y2) sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define CLR(a) a.clear()
#define VCLR(a, n) for(int i=0; i<=n+3; i++) a[i].clear()
#define SIZE(a) a.size()
#define ERASE(a, b) memset(a, b, sizeof a)
#define pb push_back
#define LL long long
#define ULL unsigned long long
#define DBG cout<<"I Am Here"<<endl
#define DBGA(a) cout<<a<<endl
#define DBGI(b,a) cout<<b<<' '<<a<<endl
#define DBGL(i,s,e,b) or(int i=s; i<=e; i++) cout<<b<<endl
#define INF 1e9
#define INV 1e-6
#define SF(a) scanf("%I64d", &a)
#define PF(a) printf("%I64d\n", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d\n", a)
#define pii pair<int,int>
#define PIS pair<double,string>
#define PII pair<LL,LL>
#define MAX 600005
#define CASE(i) printf("Case %d:", i);
#define PI acos(-1)
#define piis pair<int, string>
#define fast1 ios_base::sync_with_stdio(false);
#define fast2 cin.tie(0)
#define CHECK_BIT(var,pos) ((var & (1 << pos)) == (1 << pos))
#define LOOP(i, b, n) for(int i=b; i<=n; i++)
#define nl puts("")
#define sp printf(" ");
#define popcount __builtin_popcount
#define valid(i,j,m,n) (i>=0 && i<n && j>=0 && j<m)
#define all(v) v.begin(), v.end()

using namespace std;

/** -------------------------------------------------**/
/** Header And Definitions Ends Here.               **/
/** -----------------------------------------------**/

int dx4[] = {0, 0, 1, -1}; int dy4[] = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1}; int dy8[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dxH[] = {2, 2, -2, -2, 1, 1, -1, -1}; int dyH[] = {1, -1, 1, -1, 2, -2, 2, -2};

const double GRS = (1 + sqrt(5))/2;

template<typename T> T power(T X, T P)
{
    T ans = (T)1;
    for(T i=1; i<=P; i++){
        ans = ans * X;
    }
    return ans;
}

template<typename T> T ABS(T A, T B)
{
    T ret = A - B;
    if(ret<0) return -ret;
    return ret;
}

const LL MOD = 1000000007;
const LL BIGMAX = power(2,63) - 1;

template<typename T> T ADD(T X, T Y, T M)
{
    if(X+Y<0)
        return (X - M) + Y;
    else if(X+Y>=M)
        return X+Y-M;
    else
        return X+Y;
}

template<typename T> T prod(T a, T b, T c) // CUSTOM PRODUCT FUNCTION FOR BIG NUMBER MULTIPLICATION
{
    T x = 0, y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = ADD(x, y, c);
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

template<typename T> T bigmod(T a, T b, T c){
    T x = (T)1, y = a%c;
    while(b > 0) {
        if(b%(T)2 == (T)1) {
            x = (x * y)%c;
        }
        y = (y * y)%c;
        b /= (T)2;
    }
    return x;
}


template <typename T> T MODINVERSE(T a){
    return bigmod(a, MOD-2);
}

template<typename T> T GCD(T x, T y) {
  while ( y != 0 ) {
    T z = x % y;
    x = y;
    y = z;
  }
  return x;
}

bool isvowel(char ch)
{
    ch = toupper(ch);
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ) return true;
    return false;
}

template<typename T>T isleap (T year)
{
    if (year%(T)400 == (T)0 || (year%(T)100 != (T)0 && year%(T)4 == (T)0)) return true;
    return false;
}

/**----------------------------------------------------------------------------**/
/** Template Ends Here. Main Function And User Defined Functions Starts Here. **/
/**--------------------------------------------------------------------------**/

LL vec[4100];
LL bin[]= {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};

LL fun(LL val)
{
    LL ret = 0;
    for(int i=0; i<12; i++){
        if(val>=bin[i]){
            val = val - bin[i];
            ret = ret * 10LL + 1LL;
        }
        else{
            ret = ret * 10LL + 0LL;
        }
    }

    return ret;
}

const int MAXN = 1000005;
int status[(MAXN/32)+10];
int primelist[MAXN], primesz;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN=int (sqrt(MAXN));
    for(int i=3; i<=sqrtN; i=i+2){
        if(check(status[i>>5],i&31)==0){
            for(int j=i*i; j<=MAXN; j= j + (i<<1)){
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
    primelist[primesz++] = 2;
    for(int i=3; i<=MAXN; i=i+2){
        if(check(status[i>>5],i&31)==0){
            primelist[primesz++] = i;
        }
    }
}

map<LL, LL>mymap;
int freq[1000005];
LL facval[1000005];
int idx; int total = 0;

void facto(LL n)
{
    LL temp = n;
    LL sqT = sqrt(temp);
    idx = 0; int tt = total;
    for(int i=0; i<primesz; i++){
        LL val = (LL)primelist[i];
        if(val>sqT){
            break;
        }
        int cnt = 0;
        while(temp%val==0){
            temp = temp / val;
            cnt++;
        }

        if(cnt>0){
            if(total==tt)total++;
            freq[idx] = cnt;
            facval[idx] = (LL)val;
            idx++;
            sqT = sqrt(temp);
        }
    }

    if(temp>1){
        freq[idx] = 1;
        facval[idx] = temp;
        idx++;
    }

//    cout << "prime factorization : " << endl;
//    for(int i=0;i<idx;i++)
//    {
//        cout << facval[i] << " : " << freq[i] << endl;
//    }
}

void rec(int pos, LL val, LL num)
{
    if(pos>=idx){
        LL here = mymap[val];
        if(here==0) mymap[val] = num;

        return;
    }

    LL cal = 1;
    for(int i=0; i<=freq[pos]; i++){
        rec(pos+1, cal*val, num);
        cal = cal * facval[pos];
    }
}

int main()
{
    for(LL i=0; i<4096; i++){
        vec[i] = fun(i);
    }
    sieve();
    for(int i=0; i<4096; i++){
        if(vec[i]==0) continue;
        facto(vec[i]);
        rec(0, 1, vec[i]);
    }
    
    LL n;
    while(scanf("%lld", &n)==1){
        LL val = mymap[n];
        printf("%lld\n", val==0?-1:val);
    }
}
