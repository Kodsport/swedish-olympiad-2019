#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vi a;
vector<vi> mem;

//Räknar antal intillsittande par i vektorn v
int numPairs(vi v){
    int ans = 0;
    for(int i = 0; i< v.size()-1;i++)
        ans += (v[i]==v[i+1]);
    return ans;
}

int f(int index, int last){
    if(index==n) return 0;
    //Ifall värdet inte är -1 har vi redan räknat ut det
    if(mem[index][last]!=-1)
        return mem[index][last];

    int best = f(index+1, a[index]) + numPairs(vi({last, a[index]})); //Fall 1

    if(index<n-1)
        best = max(best, f(index+2, a[index]) + numPairs(vi({last, a[index+1], a[index]})));//Fall 2

    if(k==2){
        if(index<n-2)
            best = max(best, f(index+3, a[index]) + numPairs(vi({last, a[index+2], a[index+1], a[index]})));//Fall 3

        if(index<n-3)
            best = max(best, f(index+4, a[index+1]) + numPairs(vi({last, a[index+2], a[index+3], a[index], a[index+1]})));//Fall 4
    }


    return mem[index][last] = best;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(0);

    string str; cin>>str;
    n = str.size();
    a.resize(n);
    rep(i,0,n) {
        a[i] = str[i]-'A';
    }
    cin>>k;

    mem.resize(n,vi(5,-1)); //Sätt -1 som defaultvärde

    cout<<f(0,4)<<endl;
}
