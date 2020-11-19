#include <iostream>
#include <math.h>
#include <string>
using namespace  std;
int binary(int n){
    int number=0,i=0;
    while (n!=0){
        number+=(n%10)*pow(2,i);
        n=n/10;
        i++;
    }
    return number;
}
int main(){
   int i,t,base,number;
   int decimal1,decimal2,decimal3,decimal4;
   int binary1,binary2,binary3,binary4;
   char temp;
   cin>>t;
   for(i=0;i<t;i++){
       scanf("%d%c%d%c%d%c%d",&decimal1,&temp,&decimal2,&temp,&decimal3,&temp,&decimal4);
       scanf("%d%c%d%c%d%c%d",&binary1,&temp,&binary2,&temp,&binary3,&temp,&binary4);
       if(decimal1==binary(binary1)&&decimal2==binary(binary2)&&decimal3==binary(binary3)&&decimal4==binary(binary4)){
           printf("Case %d: Yes\n",i+1);
       } else{
           printf("Case %d: No\n",i+1);
       }

   }
    return 0;
}
