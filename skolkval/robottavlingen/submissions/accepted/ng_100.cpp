#include <iostream>
using namespace std;

int main()
{
    int n;
    int R[10] = {0};
    int C[10] = {0};
    int low = 0;
    int high = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }
    for(int i = 0; i < n; i++){
        cin >> C[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            high += min(R[i],C[j]);
        }
    }

    low = n*n;
    for(int i = 1; i <= 5; i++){
        int rows = 0;
        int columns = 0;
        for(int j = 0; j < n; j++){
            if(R[j] == i)rows++;
        }
        for(int j = 0; j < n; j++){
            if(C[j] == i)columns++;
        }
        low += (i-1)*max(rows,columns);
    }
    cout << low << " " << high << "\n";
    return 0;
}

