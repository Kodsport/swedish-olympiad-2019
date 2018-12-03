#include <iostream>

using namespace std;

int main(){
   cin.sync_with_stdio(false); cin.tie(0);

   int n;
   cin>>n;
   int aScore = 0;
   int bScore = 0;
   int aSet = 0;
   int bSet = 0;
   for(int i = 0; i<n;i++){
      char c;
      cin>>c;
      
      if(c=='A') aScore++;
      if(c=='B') bScore++;
      
      int winScore;
      if(aSet+bSet==2) winScore = 15;
      else winScore = 25;
      
      if(aScore>=winScore&&aScore>=2+bScore){
         aSet++;
         aScore=0;
         bScore=0;
      }
      if(bScore>=winScore&&bScore>=2+aScore){
         bSet++;
         aScore=0;
         bScore=0;
      }
   }

   cout<<aSet<<" "<<bSet<<endl;
}
