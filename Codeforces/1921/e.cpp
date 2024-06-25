#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
    int n, m, xa, xb, ya, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;

    if(xb <= xa){
    	cout << "Draw\n";
    	return;
    }

    char winner = ((xb - xa) % 2 == 0? 'b': 'a');

    int chances = (xb - xa);

    if(winner == 'a'){
    	int txa, txb, tya, tyb;
    	
    	txa = xa, tya = ya;
    	txb = xb, tyb = yb;

    	bool draw1 = 1; // 

    	while(txa <= txb){
    		++txa;
    		tya = max(1, tya - 1);
    		cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya <= tyb){
    			draw1 = 0;
    			break;
    		}

    		if(txa > txb){
    			break;
    		}


    		--txb;
    		tyb = max(1, tyb - 1);
    		cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya <= tyb){
    			draw1 = 0;
    			break;
    		}
    	}

    	cout << "\n\n";

    	txa = xa, tya = ya;
    	txb = xb, tyb = yb;

    	bool draw2 = 1; // 

    	while(txa <= txb){
    		++txa;
    		tya = min(m, tya + 1);
    		cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya >= tyb){
    			draw2 = 0;
    			break;
    		}

    		if(txa > txb){
    			break;
    		}

    		++txb;
    		tyb = min(m, tyb + 1);
    		cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya >= tyb){
    			draw2 = 0;
    			break;
    		}
    	}

    	if(draw1 | draw2){
    		cout << "Draw\n";
    	}
    	else{
    		cout << "Alice\n";
    	}
    }
    else{
    	int txa, txb, tya, tyb;
    	
    	txa = xa, tya = ya;
    	txb = xb, tyb = yb;

    	bool draw1 = 1; // 

    	while(txa <= txb){
    		++txa;
    		tya = max(1, tya - 1);

    		// cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya >= tyb){
    			draw1 = 0;
    			break;
    		}


    		if(txa > txb){
    			break;
    		}

    		--txb;
    		tyb = max(1, tyb - 1);
    		// cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya >= tyb){
    			draw1 = 0;
    			break;
    		}

    	}

    	txa = xa, tya = ya;
    	txb = xb, tyb = yb;

    	bool draw2 = 1; // 
    	// cout << "\n\n";

    	while(txa <= txb){
    		++txa;
    		tya = min(m, tya + 1);
    		// cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya <= tyb){
    			draw2 = 0;
    			break;
    		}

    		if(txa > txb){
    			break;
    		}


    		--txb;
    		tyb = min(m, tyb + 1);
    		// cout << txa << " " << tya << "  " << txb << " " << tyb << "\n";

    		if(tya <= tyb){
    			draw2 = 0;
    			break;
    		}
    	}

    	if(draw1 | draw2){
    		cout << "Draw\n";
    	}
    	else{
    		cout << "Bob\n";
    	}
    }
}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}