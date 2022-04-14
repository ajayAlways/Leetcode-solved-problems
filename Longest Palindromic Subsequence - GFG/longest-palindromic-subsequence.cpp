// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  private:
    int t[501][501];
  public:
    int solve(string s, int i, int j){
        // BC
        if(i>j) return 0;
        if(i==j) return 1;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]) return t[i][j] = 2 + solve(s,i+1,j-1);
        else return t[i][j] = max(solve(s,i,j-1),solve(s,i+1,j));
    }
    int longestPalinSubseq(string A) {
        //code here
        memset(t,-1,sizeof(t));
        return solve(A,0,A.length()-1);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends