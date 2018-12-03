#include <bits/stdc++.h>
using namespace std;

int big = 1000000007;

string s,t;
vector<string> moves;
vector<vector<int> > move_sequences;

void generate_moves(string s2){
    if(s2.length() >= 2){
        moves.push_back(s2);
    }
    if(s2.length() >= 4)return;
    generate_moves(s2+'A');
    generate_moves(s2+'B');
    generate_moves(s2+'C');
    return;
}

void generate_move_sequences(vector<int> mvs){
    if(mvs.size() > 0){
        move_sequences.push_back(mvs);
    }
    if(mvs.size() >= 3)return;
    for(int c1 = 0; c1 < moves.size(); c1++){
        mvs.push_back(c1);
        generate_move_sequences(mvs);
        mvs.pop_back();
    }
}

string make_move(string s2, string mov){
    string res = "";
    for(int c1 = 0; c1 < s2.length(); c1++){
        if(s2[c1] != mov[0]){
            res += s2[c1];
        }
        else{
            for(int c2 = 1; c2 < mov.length(); c2++){
                res += mov[c2];
            }
        }
    }
    return res;
}

int main(){
    int a,b,c;
    generate_moves("");
    generate_move_sequences({});
    cin >> s >> t;
    int best = big;
    int best_sequence = -1;

    int solutions[11] = {0};

    for(int c1 = 0; c1 < move_sequences.size(); c1++){
        if(move_sequences[c1].size() >= best)continue;
        string s2 = s;
        for(int c2 = 0; c2 < move_sequences[c1].size(); c2++){
            s2 = make_move(s2,moves[move_sequences[c1][c2]]);
            if(s2.length() > t.length())break;
        }
        if(s2 == t){
            solutions[move_sequences[c1].size()]++;
            best = move_sequences[c1].size();
            best_sequence = c1;
        }
    }
    assert(best_sequence != -1);
    for(int c1 = 0; c1 < move_sequences[best_sequence].size(); c1++){
        string mv = moves[move_sequences[best_sequence][c1]];
        cout << mv[0] << " ";
        for(int c2 = 1; c2 < mv.length(); c2++){
            cout << mv[c2];
        }cout << "\n";
    }

    //cerr << "Number of solutions: " << solutions[best] << "\n";


    return 0;
}
