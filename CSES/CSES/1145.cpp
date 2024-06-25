#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector <int> longest;
    longest.push_back(a[0]);

    for(int i = 1; i < n; ++i){
        if(binary_search(longest.begin(), longest.end(), a[i])){
            continue;
        }
        int x = lower_bound(longest.begin(), longest.end(), a[i]) - longest.begin();

        if(x == longest.size()){
            longest.push_back(a[i]);
        }
        else{
            longest[x] = a[i];
        }
    }

    cout << longest.size();



    return 0;
}
