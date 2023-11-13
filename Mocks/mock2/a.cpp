#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> vc;
        int splitCost = 0;

        for(int i = 0; i < n; ++i){
            int k;
            cin >> k;

            vector <int> tmp(k);
            for(int i = 0; i < k; ++i){
                cin >> tmp[i];
            }

            int last = -1;
            vector <int> splits;

            for(int i = 0; i < k - 1; ++i){
                if(tmp[i] > tmp[i + 1]){
                    // breakpoint at i
                        vc.push_back(i - last);
                        splits.push_back(i - last);


                    last = i;
                }
            }
            vc.push_back(k - last - 1);
            splits.push_back(k - last - 1);

            int x = 0;
            int y = splits.size() - 1;


            while(x < y){
                if(splits[x] <= splits[y]){
                    splitCost += splits[x];
                    ++x;
                }
                else if(splits[x] > splits[y]){
                    splitCost += splits[y];
                    --y;
                }
            }
        }

        priority_queue <int, vector <int>, greater <int>> pq;
        for(auto it : vc){
            pq.push(it);
        }

        int mergeCost = 0;

        while(!pq.empty()){
            int tp = pq.top(); pq.pop();
            if(pq.empty()) break;
            int sp = pq.top(); pq.pop();

            mergeCost += (tp + sp);
            pq.push(tp + sp);
        }

        cout << splitCost + mergeCost << "\n";
    }
    return 0;
}
