#include <iostream>
#include <vector>
#include <string>

using namespace std;

//För varje par av klasser i och j
//är adj[i][j] = true ifall det går en
//kant mellan klasss i och klass j i grafen
bool adj[26][26]; 

bool visited[26];

int N, M, K;

void dfs(int _class) {
   if (visited[_class])
      return;
   visited[_class] = true;
   
   for (int nc = 0; nc < K; nc++) {
      if (adj[_class][nc]) {
         dfs(nc);
      }
   }
}

int main() {
   cin >> N >> M >> K;
   
   vector<string> rows(N);
   for (int r = 0; r < N; r++) {
      cin >> rows[r];
   }
   
   for (int c = 0; c < M; c++) {
      int cl0 = rows[0][c] - 'A';
      for (int r = 0; r < N; r++) {
         int cl1 = rows[r][c] - 'A';
         adj[cl0][cl1] = true;
         adj[cl1][cl0] = true;
      }
   }
   
   //Räkna komponenter:
   int numComponents = 0;
   for (int i = 0; i < K; i++) {
      if (!visited[i]) {
         numComponents++;
         dfs(i);
      }
   }
   
   cout << numComponents << endl;
}
