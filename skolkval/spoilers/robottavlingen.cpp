#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.sync_with_stdio(false); cin.tie(0);

   int n;
   cin>>n;
   vector<int> r(n);
   vector<int> c(n);
   for(int i = 0;i<n;i++) cin>>r[i];
   for(int i = 0;i<n;i++) cin>>c[i];

   int mx = 0;
   for(int i = 0;i<n;i++)
      for(int j = 0;j<n;j++)
         mx += min(r[i],c[j]);

   map<int,int> x;
   map<int,int> y;

   for(int i = 0;i<n;i++){
      x[r[i]]++;
      y[c[i]]++;
   }

   int mn = 0;
   int numPlaced = 0;

   for(int i = 1;i<6;i++){
      //Placera ut max(y[i],x[i]) stycken av sifran "i"
      mn += max(y[i],x[i])*i; 
      numPlaced += max(y[i],x[i]);
   }

   mn += n*n - numPlaced; //Lägg till alla ettor


   cout<<mn<<" "<<mx<<endl;

}
