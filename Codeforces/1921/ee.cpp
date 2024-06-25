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
    int n, m, xa, ya, xb, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;

    if(xb <= xa){
    	cout << "Draw\n";
    	return;
    }

    int lya, rya, lyb, ryb;

    lya = ya, lyb = yb;
    rya = ya, ryb = yb;

    int txa = xa;
    int txb = xb;

    bool draw = 0;

    int chances = (xb - xa);

    if(chances % 2 == 1){
	    while(txa <= txb){
	    	++txa;
	    	lya = max(1, lya - 1);
	    	rya = min(m, rya + 1);

	    	// cout << txa << " " << txb << "  " << lya << " " << rya << "  " << lyb << " " << ryb << "\n";


	    	if(txa == txb){
	    		if(lya > lyb || ryb > rya){
	    			draw = 1;
	    		}

	    		break;
	    	}


	    	--txb;
	    	lyb = max(1, lyb - 1);
	    	ryb = min(m, ryb + 1);

	    	// cout << txa << " " << txb << "  " << lya << " " << rya << "  " << lyb << " " << ryb << "\n";

	    	if(txa == txb){
	    		if(lya > lyb || ryb > rya){
	    			draw = 1;
	    		}

	    		break;
	    	}
	    }

	    if(!draw){
	    	cout << "Alice\n";
	    }
	    else{
	    	cout << "Draw\n";
	    }
	}
	else{
		while(txa <= txb){
	    	++txa;
	    	lya = max(1, lya - 1);
	    	rya = min(m, rya + 1);


	    	// cout << txa << " " << txb << "  " << lya << " " << rya << "  " << lyb << " " << ryb << "\n";

	    	if(txa == txb){
	    		if(lya < lyb || ryb < rya){
	    			draw = 1;
	    		}

	    		break;
	    	}

	    	--txb;
	    	lyb = max(1, lyb - 1);
	    	ryb = min(m, ryb + 1);


	    	// cout << txa << " " << txb << "  " << lya << " " << rya << "  " << lyb << " " << ryb << "\n";

	    	if(txa == txb){
	    		if(lya < lyb || ryb < rya){
	    			draw = 1;
	    		}

	    		break;
	    	}
	    }

	    if(!draw){
	    	cout << "Bob\n";
	    }
	    else{
	    	cout << "Draw\n";
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