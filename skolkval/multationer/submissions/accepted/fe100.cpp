#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vector<pair<char,string> > subs;

ll n = 3;
ll m = 3;
ll k = 3;

void genSubs(string str){
    if(str.size()!=0)
        rep(x,'A','A'+n) subs.emplace_back(x,str);
    if(str.size()<k)
        rep(y,'A','A'+n) genSubs(str+char(y));
}

string replace(string str, char from, string to){
    string out = "";
    rep(i,0,str.size()){
        if(str[i]==from) out += to;
        else out += str[i];
    }
    return out;
}

ll a,b;
string str1;
string str2;
vi bestSeq;

void rec(string str, vi seq){
    if(seq.size()>=bestSeq.size()) return;
    if(str == str2){
        bestSeq = seq;
        return;
    }
    if(seq.size()<m){
        rep(i,0,subs.size()){
            vi newSeq = seq;
            newSeq.push_back(i);
            rec(replace(str,subs[i].first,subs[i].second),newSeq);
        }
    }
}

int main(){
	cin.sync_with_stdio(false);
    cin>>str1>>str2;

    genSubs("");

    bestSeq = {0,0,0,0,0,0,0,0};

    rec(str1,vi(0));

    //cout<<bestSeq.size()<<endl;
    rep(i,0,bestSeq.size()){
        cout<<subs[bestSeq[i]].first<<" "<<subs[bestSeq[i]].second<<endl;
    }
}