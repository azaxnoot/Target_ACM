/*
File : Mathematically Hard.cpp
Number Theory, Relative Prime .
*/




#include<bits/stdc++.h>
#define MAX 5000005
#define LL long long int
#define ULL unsigned long long

using namespace std;

int status[(MAX/32)+10], sz;
ULL relative[MAX];

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int SET(int n, int pos){ return n=n|(1<<pos);}

void sieve()
{
    int sqrtN= sqrt( (double)MAX);
    status[1>>5]=SET(status[1>>5],1&31);
    for(int j=4; j<MAX; j=j+2)
        status[j>>5]=SET(status[j>>5],j&31);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(int j=i*i; j<=MAX; j= j + (i<<1))
            {
                status[j>>5]=SET(status[j>>5],j&31);
            }
        }
    }
}

void PHI()
{
    relative[0] = 0;
    for(int i=1; i<MAX; i++)
    {
        relative[i] = i;
    }
    for(int i=2; i<MAX; )
    {
        if(check(status[i>>5], i&31)==0 && relative[i]==i)
        {
            for(int j=i; j<MAX; j = j + i)
            {
                relative[j] = relative[j] - (relative[j] / i);
            }
        }
        if(i>2) i = i + 2;
        else i++;
    }
}

void Solve()
{
    for(int i=2; i<=MAX-5; i++)
    {
        relative[i] = (relative[i]*relative[i]) + relative[i-1];
    }
}

int main()
{
    sieve();
    PHI();
    Solve();
    int test, n, m;
    scanf("%d", &test);
    for(int caseno = 1; caseno<=test; caseno++)
    {
        scanf("%d %d",&m, &n);

        printf("Case %d: %llu\n", caseno, relative[n] - relative[m-1]);
    }
    return 0;
}
