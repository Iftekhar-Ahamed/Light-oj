#include <iostream>
using namespace  std;
bool check(int n){
    if(n>0)return true;
    return false;
}
int main(){
    int i,t,t2,n,sum;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>t2;
        sum=0;
        while (t2--){
            cin>>n;
            if(check(n))sum+=n;
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
