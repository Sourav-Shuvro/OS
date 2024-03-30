#include<bits/stdc++.h>
using namespace std;
struct Process{
    string s;
    int a;
} p[100];
int check(int n){
    for(int i=0; i<n; i++){
        if(p[i].a>0){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("in3.txt", "r", stdin);
    int n,tq,gt[1000];
    string pn[1000];
    cin>>n>>tq;
    for(int i=0; i<n; i++){
        cin>>p[i].s>>p[i].a;
    }
    int i=0,j=0;
    gt[j]=0;
     while(1){
        if(check(n)==0)
            break;
        if(p[i].a>0)
        {
            if(p[i].a<tq)
                gt[j+1]=gt[j]+p[i].a;
            else{
                gt[j+1]=gt[j]+tq;
            }
            p[i].a=p[i].a-tq;
            pn[j]=p[i].s;
            j++;
        }
        i++;
        if(i>4)
            i=0;

     }
     for(int k=0; k<j; k++){
        cout<<" "<<pn[k]<<" ";
     }
     cout<<endl;
      for(int k=0; k<j+1; k++){
        cout<<" "<<gt[k]<<" ";
     }
     int s=0;
     for(int l=0; l<j; l++){
        s=s+gt[l];
     }
     cout<<"\nAverage Waiting Time="<<(double)s/n<<endl;
     s=0;
     for(int l=0; l<j+1; l++){
        s=s+gt[l];
     }
    cout<<"Average Turnaround Time="<<(double)s/n<<endl;

}
