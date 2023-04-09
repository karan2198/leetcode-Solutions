//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   #define mod (int)(1e9+7)
    int Fact[100001];
    int binExp(int n,int x)
    {
        int ans=1;
        while(x)
        {
            if(x&1) ans=(ans*1LL*n)%mod;
            n=(n*1LL*n)%mod;
            x>>=1;
        }
        return ans;
    }
    void CreateFactorial()
    {
        Fact[0]=1; 
        for(int i=1;i<=100000;i++)
        {
            Fact[i]=(i*1LL*Fact[i-1])%mod;
        }
    }
    int nCr(int N,int i)
    {
        // N!/i!*(N-i)!
        int numerator=Fact[N];
        int denominator=(Fact[i]*1LL*Fact[N-i])%mod;
        return (numerator *1LL* binExp(denominator,mod-2))%mod;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
         CreateFactorial();
        long long ans=0;
        if(A==B) // When Both Numbers are same , only 1 arrangement is possible let's say A=2,B=2 So, 222222 only 1 arrangement
            // so check whether sum contains any of C or D
        {
            int sum=N*A;
            bool best=false;
            while(sum>0)
            {
                int rem=sum%10;
                if(rem==C || rem==D) 
                {
                    best=true;
                    break;
                }
                sum/=10;
            }
            if(best) return 1;
        }
        for(int i=0;i<=N;i++)
        {
            // i-> Number of A's
            // N-i -> Number of B's
            int sum=i*A+(N-i)*B;
            bool best=false;
            while(sum>0)
            {
                int rem=sum%10;
                if(rem==C || rem==D) // Also this condition is to check if atleast C or D is there , just break out get the answer
                {
                    best=true;
                    break;
                }
                sum/=10;
            }
            if(best)
            {
                ans=(ans+nCr(N,i)%mod)%mod;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends