#include<bits/stdc++.h>

using namespace std;

vector<pair<char,string> > subs;

int n = 3; //Alfabetets längd
int m = 3; //Maximalt antal byten
int k = 3; //Maximal längd på sträng man byter ut mot

//Generera rekursivt alla strängar vi kan byta ut mot
void genSubs(string replaceWith){ 
   if(replaceWith.size()!=0)
      for(char x = 'A'; x<'A'+n;x++) subs.emplace_back(x,replaceWith);
   if(replaceWith.size()<k)
      for(char x = 'A'; x<'A'+n;x++) genSubs(replaceWith+char(y));
}

//Utför det faktiska bytet
string replace(string str, char from, string to){ 
   string out = "";
   rep(i,0,str.size()){
      if(str[i]==from) out += to;
      else out += str[i];
   }
   return out;
}


string str1; //Strängen vi börjar med 
string str2; //Strängen vi ska till
vector<int> bestSeq; // Kortaste giltiga sekvensen vi hittat hittils

//str är hur strängen ser ut just nu, history är vilka multationer som hittils utförts
void rec(string str, vector<int> history){
   if(history.size()>=bestSeq.size()) return;
   if(str == str2){
      bestSeq = history;
      return;
   }
   if(history.size()<m){
      for(int i = 0; i<subs.size();i++){ //Testa alla möjliga multationer
         vector<int> newSeq = history;
         newSeq.push_back(i);
         // Utför multationen med hjälp av funktionen
         // "replace", och rekursera sedan
         rec(replace(str,subs[i].first,subs[i].second),newSeq);
      }
   }
}

int main(){
   cin.sync_with_stdio(false);
   cin>>str1>>str2;

   genSubs("");

   bestSeq = {0,0,0,0,0,0,0,0};

   rec(str1,vector<int>(0));

   for(int i =0; i<bestSeq.size();i++){
      cout<<subs[bestSeq[i]].first<<" "<<subs[bestSeq[i]].second<<endl;
   }
}