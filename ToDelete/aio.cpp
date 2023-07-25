#include <iostream>
#include <map>

using namespace std;

int main(){

    map <string, int> mp;

    for(int i = 0; i < 5; ++i){
        string tmpName;
        int age;

        cin >> tmpName >> age;
        mp[tmpName] = age;
    }

    cout << mp.size() << "\n";
    mp.erase("Mukund");

    string var;
    cin >> var;

    if(mp.find(var) != mp.end()){
        cout << "ABC!\n";
    }

    for(auto it : mp){
        cout << it.first << " : " << it.second << "\n";
    }

    return 0;
}