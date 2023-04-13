bool cmp(string a, string b){
    
    for(int i = 0; i < min(a.size(), b.size()); ++i){
        if(a[i] < b[i]){
            return 0;
        }
        if(b[i] < a[i]){
            return 1;
        }
    }
    
    if(a.size() < b.size()){
        return 0;
    }
    if(b.size() < a.size()){
        return 1;
    }
    return 0;
}

bool binarySearch(vector <string> &a, int &n, string &key){
    
    int l = 0;
    int h = n - 1;
    
    while(l < h){
        int mid = (l + h) / 2;
        
        if(a[mid] == key){
            return 1;
        }
        else if(a[mid] < key){
            l = mid;
        }
        else{
            h = mid;
        }
    }
    
    return 0;
}

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        map <string, long long int> mp;
        
        long long int n = creators.size();
        
        for(long long int i = 0; i < n; ++i){
            if(mp.find(creators[i]) == mp.end()){
                mp[creators[i]] = 0;
            }
            
            mp[creators[i]] += views[i];
        }
        
        long long int mx = 0;
        
        for(auto it : mp){
            mx = max(mx, it.second);
        }
        
        vector <string> mostViewed;
        
        for(auto it : mp){
            if(it.second == mx){
                mostViewed.push_back(it.first);
            }
        }
        
        sort(mostViewed.begin(), mostViewed.end(), cmp);
        
        mp.clear();
        
        for(long long int i = 0; i < n; ++i){
            if(binarySearch(mostViewed, mostViewed.size(), creators[i])){
                
                if(mp.find(creators[i]) == mp.end()) mp[creators[i]] = i;
                else if(views[mp[creators[i]]] < views[i]){
                    mp[creators[i]] = i;
                }
            }
        }
        
        vector <vector <string>> ans;
        
        for(auto it: mp){
            ans.push_back({it.first, ids[it.second]});
        }
        
        return ans;
    }
};

int main(){

	
	return 0;
}