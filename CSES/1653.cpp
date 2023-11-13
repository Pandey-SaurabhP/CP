#include <bits/stdc++.h>

using namespace std;

long dp[(1 << 21)];
vector <long> a(21);
long n, x, req;

inline long countEmpty(long x){
    long cnt = 0;
    long pos = 0;

    while(x){
        if(!(x & 1)){
            ++cnt;
        }
        x >>= 1;
        ++pos;
    }

    return cnt + (n - pos);
}

long unset[21];

inline long expand(long x, long bits){
    for(long i = 0; i < n; ++i){
        unset[i] = 1;
    }

    long pos = 0;
    while(bits){
        if(bits & 1){
            unset[pos] = 0;
        }
        ++pos;
        bits >>= 1;
    }

    long y = 0;
    long ans = 0;

    for(long i = 0; i < n; ++i){
        if(unset[i]){
            if((x >> y) & 1){
                ans += (1 << i);
            }
            ++y;

        }
    }
    return ans;
}

inline long solve(long bits){
    if(bits == req){
        return 0;
    }

    if(dp[bits] != -1){
        return dp[bits];
    }

    long ans = 31;

    long emptyCnt = countEmpty(bits);
    emptyCnt = (1 << emptyCnt);

    long sm, pos, val;
    for(long j = 1; j <= emptyCnt - 1; ++j){

        sm = 0;
        pos = 0;
        val = expand(j, bits);

        for(long k = val; k > 0; k >>= 1){
            if(k & 1){
                sm += a[pos];
            }

            ++pos;
        }

        if(sm <= x && sm > 0){
            ans = min(ans, 1 + solve(bits | val));
        }


    }

    return dp[bits] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    memset(dp, -1, sizeof(dp));

    cin >> n >> x;

    for(long i = 0; i < n; ++i){
        cin >> a[i];
    }

    req = (1 << n) - 1;

    cout << solve(0);


    return 0;
}

//20 1000000000
//609930576 743367699 654625611 652866556 246630130 678361938 373274223 514238771 672226971 676674414 617262649 65406509 512255879 571630744 592623811 666860991 221901431 468770389 579856619 374517264

