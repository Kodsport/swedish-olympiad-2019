#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(){
   cin.sync_with_stdio(false);
   int r,c,k;
   cin>>r>>c>>k;
   vector<vector<bool>> fire(r,vector<bool>(c));
   for(int i = 0; i<r; i++)
      for(int j = 0; j<c; j++){
         char c;
         cin>>c;
         fire[i][j] = c=='#';
      } 
   if(r+c<=k){
      cout<<r-1+c-1<<endl;
      return 0;
   }
   
   queue<tuple<int,int,int,int>> q;
   q.emplace(0,0,0,0);

   //Det här är den 3-dimensionella matrisen där vi håller koll på om vi redan processat en nod eller inte 
   vector<vector<vector<bool>>> seen(r,vector<vector<bool>>(c,vector<bool>(r+c)));
   while(q.size()>0){ //Så länge det finns noder att processa
      int x,y,fires,distance;
      tie(x,y,fires,distance) = q.front();
      q.pop();
      if(x<0||x>=r||y<0||y>=c) continue; //Ifall vi är utanför rutnätet, ignorera denna och gå vidare

      fires += fire[x][y];

      if(fires>k||seen[x][y][fires]) continue; //Ifall vi har gått genom för många eldar eller redan har processat rutan, ignorera denna och gå vidare

      seen[x][y][fires] = true;

      if(x==r-1&&y==c-1){ //Ifall vi är vid mål
         cout<<distance<<endl; 
         return 0;
      }

      //Lägg till alla grannar i kön
      q.emplace(x,   y-1, fires, distance+1);
      q.emplace(x+1, y,   fires, distance+1);
      q.emplace(x,   y+1, fires, distance+1);
      q.emplace(x-1, y,   fires, distance+1);
   }

   //Ifall vi kommer hit kunde vi aldrig nå slutnoden
   cout<<"nej"<<endl;
}

