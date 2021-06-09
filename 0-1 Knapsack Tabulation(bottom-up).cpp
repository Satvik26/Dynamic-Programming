#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


 int max(int a , int b){
    
    return (a>b) ? a : b;
}


 int knap( int wt[] ,  int val[],  int w ,  int n){
    int i, j;
    int t[n+1][w+1];
    
 
    
    
   for( i=0 ; i <= n ; i++){
        for(  j=0 ;j<=w ; j++){
            
              if (i== 0 || j==0)
                
                t[i][j] = 0;
            
            
           else if( wt[i-1] <= j)
                
                t[i][j] = max( val[i-1] + t[i-1][j- wt[i-1]]   , t[i-1][j]);
                
        
            
            else
                t[i][j]  = t[i-1][j];
            
            
    }
   
   }
    return t[n][w];
    
    
}

int main() {
   
    int test;
    cin >> test;
    
    while(test--){
        
        int w , n;
        cin >> w >> n;
        
        int wt[n];
         int val[n];
        
        for(int l=0;l<n;l++){
            cin >> wt[l] >> val[l];
            
        }
        
        
        cout << knap(wt , val , w , n);
        
        
        
        
        
    }
      

}
