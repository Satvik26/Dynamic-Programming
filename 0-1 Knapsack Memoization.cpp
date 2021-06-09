#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

 int t[2005][2005];


int max(int a , int b){
    
    return (a>b) ? a : b;
}

int knap(int wt[] , int val[], int w,  int n){
    
   if(n==0 || w==0){
        return 0;
   } 
  /*  if(w==0){
        return 0;
    }*/
    
  if(t[n][w] != -1){
        return t[n][w];
  }
    
    
    if(wt[n-1]>w)
        return t[n][w] = (knap(wt , val , w, n-1));
    
    
    else
        return t[n][w] = max((val[n-1] + knap(wt, val, w-wt[n-1],n-1)),knap(wt, val, w, n-1));
    
} 




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    
    memset(t , -1 , sizeof(t));
    
    int test ;
    cin >> test ;
   while (test--) {
        
        int n, w;
       cin >> w >> n;
       int wt[n];
       int val[n];
       
       for (int l=0; l <n ;l++){
           
           cin >> wt[l] >> val[l];
       }
       
       
       int ans = knap(wt, val, w , n);
       
       cout << ans;
        
        
        
    }
    return 0;
}
