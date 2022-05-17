// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    unordered_map<string,long>m;
public:
    long solve(string s, int i, int j, bool isTrue){
        if(i>j) return false;
        if(i==j){
            if(isTrue) return s[i]=='T';
            else return s[i]=='F';
        }
        string key=to_string(i);
        key.push_back(' ');
        key.append(to_string(j));
        key.push_back(' ');
        key.append(to_string(isTrue));
        if(m.find(key)!=m.end()) return m[key]%1003;
        long ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lT = solve(s,i,k-1,true);
            int lF = solve(s,i,k-1,false);
            int rT = solve(s,k+1,j,true);
            int rF = solve(s,k+1,j,false);
            
            if(s[k]=='|'){
                if(isTrue) ans+=((lT*rT) + (lF*rT) + (lT*rF));
                else ans+=(lF*rF);
            }
            else if(s[k]=='&'){
                if(isTrue) ans+=(lT*rT);
                else ans+=((lT*rF) + (lF*rT) + (lF*rF));
            }
            else if(s[k]=='^'){
                if(isTrue) ans+=((lF*rT) + (lT*rF));
                else ans+=((lT*rT) + (lF*rF));
            }
        }
        return m[key]=ans%1003;
    }
    int countWays(int N, string S){
        // code here
        return solve(S,0,N-1,true)%1003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends