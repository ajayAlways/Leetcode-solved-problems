// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string smallest=arr[0];
        for(int i=0;i<N;i++){
            if(arr[i].length()<smallest.length()) smallest = arr[i];
        }
        for(int i=smallest.size();i>0;i--){
            string comp=smallest.substr(0,i);
            int flag=1;
            for(int i=0;i<N;i++){
                if(arr[i].substr(0,comp.length())!=comp){
                    flag=0;
                    break;
                }
            }
            if(flag) return comp;
        }
        return "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends