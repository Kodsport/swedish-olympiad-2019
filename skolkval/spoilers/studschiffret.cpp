#include<bits/stdc++.h>

using namespace std;

int main(){
   cin.sync_with_stdio(false);
   int n,m;
   string str;
   cin>>n>>m>>str;

   vector<vi> g(n,vi(m,-1));

   int r = 0;
   int c = 0;
   int dr = 1;
   int dc = 1;
   int ind = 0;
   //Simulera:
   while(ind<str.size()){
      if(g[r][c]==-1){
         g[r][c] = ind;
         ind++;
      }

      r+=dr;
      c+=dc;

      if(r<0){ r = 1; dr = 1; }
      if(c<0){ c = 1; dc = 1; }
      if(r>=n){ r = n-2; dr = -1; }
      if(c>=m){ c = m-2; dc = -1; }
   }

   //Läs av rad för rad:
   vi encNum;
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         if(g[i][j]!=-1)
            encNum.push_back(g[i][j]);

   //Rekonstruera den ursprungliga strängen:
   string dec(str.size(),'.');
   for(int i = 0;i<str.size();i++)
      dec[encNum[i]] = str[i];

   cout<<dec<<endl;
}
