// we can calculate the prime factors of a number in O(logn) time if n <= 1e7

const int mx = 1e7;
vector<int> spf(mx + 1) ;  // stores the smallest prime factor of ith number

vector<int> pr_factors(int n) {
    vector<int> ans;
    while(n > 1)
    {
        ans.push_back(spf[n]);
        n /= spf[n] ; 
    }
    
    sort(ans.begin(), ans.end()) ;
    return ans;
}

int main() {
    // some code.   
    for(int i = 2; i<=mx; i++)
    {
        // if i is a prime number, set i as the spf of all its multiples
        if(!spf[i]) {
            for(int j = i; j<=mx; j+=i) 
                spf[j] = i;
        }
    }
}
