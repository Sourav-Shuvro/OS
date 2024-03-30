#include<bits/stdc++.h>
using namespace std;
struct Process{
    string s;
    int a,pr;
} p[100];
bool cmp(Process x, Process y){
    return x.pr<y.pr;
}
int main(){
    freopen("in2.txt", "r", stdin);
    int n,gt[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p[i].s>>p[i].a>>p[i].pr;
    }
    sort(p,p+n, cmp);
    for(int i=0; i<n; i++){
        cout<<p[i].s<<" "<<p[i].a<<" "<<p[i].pr<<endl;
    }
    int s=0;
    gt[0]=0;
    for(int i=0; i<n; i++){
        s=s+p[i].a;
        gt[i+1]=s;

    }
    for(int i=0; i<n; i++){
        cout<<" "<<p[i].s<<" ";
    }
    cout<<endl;
    for(int i=0; i<n+1; i++){
        cout<<gt[i]<<"  ";
    }

//    ///AVG Wt Time
    s=0;
    for(int i=0; i<n; i++){
        s=s+gt[i];
    }
//    //cout<<endl<<s<<endl;
    cout<<"\nAverage Waiting Time=" <<(double)s/n<<endl;
    s=0;
    for(int i=0; i<n+1; i++){
        s=s+gt[i];
    }
    cout<<"Average Turnaround Time=" <<(double)s/n<<endl;
}
