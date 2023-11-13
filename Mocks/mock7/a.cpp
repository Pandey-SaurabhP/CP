#include <bits/stdc++.h>

using namespace std;

int main(){

    int b, n;
    cin >> b >> n;

    int mod = b + 1;

    vector <int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int oddSum = 0;
    int evenSum = 0;

    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            evenSum += a[i];
        }
        else{
            oddSum += a[i];
        }
    }

    bool already = 0;

    if(abs(oddSum - evenSum) % mod == 0){
        cout << "0 0";
        already = 1;
    return 0;
    }


    int dist = abs(oddSum - evenSum) % mod;

    int a1, a2;
    a1 = a2 = -1;

    if(evenSum > oddSum){

        for(int i = 0; i < n; ++i){
            if(i % 2 == 0 && a[i] - dist >= 0){
                a1 = i + 1;
                a2 = a[i] - dist;
                break;
            }
            else if(i % 2 == 1 && (dist + a[i]) >= mod){
                a1 = i + 1;
                a2 = mod - dist - 1;
                break;
            }
        }
    }
    else{
        for(int i = 0; i < n; ++i){
            if(i % 2 == 1 && a[i] - dist >= 0){

                if(a1 == -1 || i + 1 < a1){
                    a1 = i + 1;
                    a2 = a[i] - dist;
                }

                break;
            }
            else if(i % 2 == 0 && (dist + a[i]) >= mod){
                if(a1 == -1 || i + 1 < a1){
                    a1 = i + 1;
                    a2 = mod - dist - 1;
                }

                break;
            }
        }
    }

//
//        for(auto it : a){
//            cout << it << " ";
//        }
//        cout << "\n";

    cout << a1 << " " << a2 << "\n";

    return 0;
}
