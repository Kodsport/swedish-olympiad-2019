#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main(int argc, char **argv) {
  init_io(argc, argv);

  string start, goal;
  judge_in >> start >> goal;
  

  auto check = [&](istream& sol, feedback_function feedback){
    string from, to, current = start;
    rep(i, 0, 3){
        if(sol >> from){
            if(from.size()!=1) feedback("Character is wrong length");
            char c_from = toupper(from[0]);
            if(c_from<'A'||c_from>'C') feedback("Character was not A, B or C");
            if(sol >> to){
                if(to.size()<1||to.size()>3) feedback("Pattern is wrong length");
                for(char& c : to) c = (char)toupper(c);
                for(char &c : to)if(c<'A'||c>'C') feedback("Pattern was not A, B or C");
                string next = "";
                for(char &c : current){
                    if(c == c_from)next+=to;
                    else next+=c;
                }
                current = next;
            }
            else feedback("Expected more output");
        }
    }
    string trailing;
    if(sol >> trailing) feedback("Trailing output");
    if(goal != current) feedback("Multation output not correct");
    return;
  };

  check(author_out, wrong_answer);

  accept();
}