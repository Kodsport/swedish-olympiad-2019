#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<int,double>>> gettingLettersFrom;
//Här sparar vi för varje person v en lista av alla personer u den får brev från, 
//tillsammans med ett flyttal som beskriver andelen av u:s brev som den skickar till v

vector<double> M;
vector<double> output;

double getOutput(int v){
	if(output[v]!=-1) { //Ifall output inte är -1 har vi redan räknat ut den
		return output[v];
	}
	if(gettingLettersFrom[v].size()==0) return M[v];

    double in = 0;
    for(int i = 0; i<gettingLettersFrom[v].size(); i++){
        int u = gettingLettersFrom[v][i].first;
        double share = gettingLettersFrom[v][i].second;
        
        in += getOutput(u)*share;
    }

    double out = min(in,M[v]);

    return output[v] = out; //spara värdet i output och returnera det
}

int main(){
	cin.sync_with_stdio(false);
    int n;
    cin>>n;
    gettingLettersFrom.resize(n);
    M.resize(n);
	output.resize(n,-1); //Vi sätter -1 som defaultvärde innan det riktiga värdet är uträknat

    for(int i = 0; i<n;i++) {
        int k;
        cin>>M[i]>>k;
        for(int l = 0; l<k;l++) {
            int j;
            double w;
            cin>>j>>w;
            gettingLettersFrom[j-1].emplace_back(i,w/100.0);
        }
    }

    rep(i,0,n){
        if(getOutput(i)==M[i]) cout<<i+1<<" ";
    }
    cout<<endl;
}