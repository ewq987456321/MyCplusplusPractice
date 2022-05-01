#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int T,num;
    cin >> T;
    for(int j = 0; j < T; j++){
        cin >> num;
        int **arr = (int **)malloc(sizeof(int *) * num);
        int count_operation;
        string strArr;
        for(int i = 0; i < num; i++){
            arr[i] = (int *)malloc(sizeof(int) * num);
        }
        /*
        for(int i = 0; i<num; i++){
            for(int j = 0; j<num; j++){
                cin >> arr[i][j];
            }
        }
        */
        for(int i = 0; i < num; i++){
            cin >> strArr;
            for(int k = 0;k < num; k++){
                arr[i][k] = strArr[k] - '0';
            }
        }
        cin >> count_operation;
        for(int i = 0; i < count_operation; i++){
            string operation;
            cin >> operation;
            if(operation == "row"){
                int a, b;
                cin >> a >> b;
                a -= 1;
                b -= 1;
                int *temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;

            }
            else if(operation == "col"){
                int a, b;
                cin >> a >> b;
                a -= 1;
                b -= 1;
                int *temp =(int *)malloc(sizeof(int) * num);
                for(int m = 0; m < num; m++){
                    temp[m] = arr[m][a];
                    arr[m][a] = arr[m][b];
                    arr[m][b] = temp[m];
                }
                free(temp);
            }
            else if(operation == "inc"){
                for(int m = 0 ;m < num; m++){
                    for(int n = 0; n < num; n++){
                        arr[m][n] += 1;
                        if(arr[m][n] == 10)
                            arr[m][n] = 0;
                    }
                }
            }
            else if(operation == "dec"){
                for(int m = 0 ;m < num; m++){
                    for(int n = 0; n < num; n++){
                        arr[m][n] -= 1;
                        if(arr[m][n] == -1)
                            arr[m][n] = 9;
                    }
                }

            }
            else if(operation == "transpose"){
                int temp;
                for(int m = 0; m < num; m++){
                    for(int n = 0; n < m; n++){
                        temp = arr[m][n];
                        arr[m][n] = arr[n][m];
                        arr[n][m] = temp;
                    }
                }
            }
        }
        cout << "\nCase #" << j+1 << endl;
        for(int m = 0;m < num; m++){
            for(int n = 0;n < num; n++){
                cout << (int)arr[m][n];
            }
            cout << "\n";
        }
        for(int i = 0; i < num; i++)
            free(arr[i]);
        free(arr);
    }
}
