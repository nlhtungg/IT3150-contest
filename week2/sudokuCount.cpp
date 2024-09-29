#include<bits/stdc++.h>

using namespace std;

int countSudokuSolutions(int a[9][9]){
    int count = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(a[i][j] == 0){
                for(int k=1; k<=9; k++){
                    bool check = true;
                    for(int l=0; l<9; l++){
                        if(a[i][l] == k || a[l][j] == k){
                            check = false;
                            break;
                        }
                    }
                    if(check){
                        for(int l=0; l<3; l++){
                            for(int m=0; m<3; m++){
                                if(a[(i/3)*3+l][(j/3)*3+m] == k){
                                    check = false;
                                    break;
                                }
                            }
                        }
                    }
                    if(check){
                        a[i][j] = k;
                        count += countSudokuSolutions(a);
                        a[i][j] = 0;
                    }
                }
                return count;
            }
        }
    }
    return 1;
}

int main(){
    int a[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> a[i][j];
        }
    }
    cout << countSudokuSolutions(a) << endl;
}