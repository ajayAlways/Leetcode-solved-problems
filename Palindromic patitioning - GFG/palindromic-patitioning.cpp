// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int t[501][501];
public:
    bool isPalindrome(string &s, int i, int j){
        if(i>j) return false;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string s,int i,int j){
        if(t[i][j]!=-1) return t[i][j];
        if(i>=j || isPalindrome(s,i,j)) return 0;
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int left, right;
            if(t[i][k]!=-1) left = t[i][k];
            else{
                left = solve(s,i,k);
                t[i][k] = left;
            }
            
            if(t[k+1][j]!=-1) right = t[k+1][j];
            else{
                right = solve(s,k+1,j);
                t[k+1][j] = right;
            }
            int temp = left+right+1;
            ans = min(ans,temp);
        }
        return t[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends