class Solution {
public:
    
    bool isValid(vector <long long> &a, long long n, long long p, long long m){
        
        vector <long long> tmp = a;
        long long cnt = 0;
        
        vector <bool> done(n, 0);
        
        for(long long i = 0; i < n - 1; ++i){
            if(done[i]) continue;
            
            if(abs(a[i] - a[i + 1]) <= m){
                ++cnt;
                ++i;
            }
            
            if(cnt >= p) return 1;
        }
        return 0;
    }
    
    long long minimizeMax(vector<long long>& a, long long p) {
        
        sort(a.begin(), a.end());
        long long n = a.size();
        
        long long l = 0;
        long long h = long long_MAX;
        long long ans = long long_MAX;
        
        while(l < h){
            long long mid = (l + h) / 2;
            
            if(isValid(a, n, p, mid)){
                ans = mid;
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        
        return ans;
        
    }
};