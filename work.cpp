#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define LL long long
using namespace std;
struct node{
    int k;
    int s;
}work[101100];
struct Student{
    int k;
    int id;
}a[101000];
bool cmp1(Student a,Student b){
    return a.k<b.k;
}
bool cmp(node a,node b){
    if(a.k==b.k){
        return a.s>b.s;
    }
    return a.k<b.k;
}
int n,m;
int max_s[101000];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&work[i].k,&work[i].s);
    }
    sort(work,work+n,cmp);
    for(int i=0;i<n;i++)
    {
        max_s[i]=0;
    }
    int q=0,ans=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i].k);
        a[i].id=i;
    }
    sort(a,a+m,cmp1);
    for(int i=0;i<m;i++){
        while(q<n&&a[i].k>=work[q].k){
            ans=max(work[q].s, ans);
            q++;
        }
        max_s[a[i].id]=ans;
    }
    for(int i=0;i<m;i++){
        printf("%d\n",max_s[i]);
    }
    return 0;
}

