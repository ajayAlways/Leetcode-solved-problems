// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int t[101][101];
public:
    
    int solve(int arr[], int i, int j){
        int mini=INT_MAX;
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        for(int k=i;k<=j-1;k++){
            int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mini = min(mini,temp);
        }
        return t[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(arr,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends