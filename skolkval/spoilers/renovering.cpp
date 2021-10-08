#include<bits/stdc++.h>

using namespace std;

int main(){
   cin.sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   vector<int> x(n);
   vector<int> y(m);
   for(int i = 0; i<n; i++) cin>>x[i];
   for(int i = 0; i<m; i++) cin>>y[i];

   //Sortera så att de längsta spikarna hamnar sist
   sort(all(x)); 
   sort(all(y));

   vector<int> toBuy;

   while(x.size()){
      if(y.size()&&x[x.size()-1]<=y[y.size()-1]){ //Ifall den längsta spiken vi behöver är kortare än den längsta vi har
          //Då tar vi bort båda
         x.pop_back();
         y.pop_back();
      } else {
         //Annars kan den längsta vi behöver omöjligt paras ihop med någon, så vi säger att vi måste köpa den och tar sedan bort den.
         toBuy.push_back(x[x.size()-1]);
         x.pop_back();
      }
   }

   sort(all(toBuy));

   cout<<toBuy.size()<<endl;
   for(int i = 0; i<toBuy.size();i++){
      cout<<toBuy[i]<<" ";
   }
   cout<<endl;
}
