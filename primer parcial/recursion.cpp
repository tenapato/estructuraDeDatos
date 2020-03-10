#include <iostream>
using namespace std;


int factorial(int num){
    int res=1;
    for(int i = num; i>0;i--){
        res*=i;
    }
    return res;
}

int factorialRecursivo(int n){

    if(n==0){
        return 1;
    }
    else{
        return n*factorialRecursivo(n-1);
    }
}

 
int main(){

    int res=factorial(5);
    cout<<res<<endl;
    int res2=factorialRecursivo(5);
    cout<<res2<<endl;
}
