/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mx = 105;

int need[mx][mx];
int avail[mx];
int mmax[mx][mx];
int alloc[mx][mx];
int p,r;
bool finish[mx];
vector<int> safeSeq;

void isSafe()
{
    int cnt = 0;
    while(cnt < p){
        bool f = false;
        for(int i=0; i<p; i++){
            if(!finish[i]){
                bool ch1 = true;
                for(int j=0; j<r; j++){
                    if(avail[j] < need[i][j]){ch1 = false; break;}
                }

                if(ch1){
                    for(int j=0; j<r; j++){
                        avail[j] += alloc[i][j];
                    }
                    safeSeq.push_back(i);
                    f = true;
                    cnt++;
                    finish[i] = true;
                    //break;
                }
            }
        }
        if(!f){cout << "Not safe" << endl; return;}
    }

    cout << "Safe" << endl;
    for(int i=0; i<safeSeq.size(); i++){
        cout << safeSeq[i] << " ";
    }
    cout << endl;
}



int main()
{
    cin >> p >> r;
    for(int i=0; i<r; i++){
        cin >> avail[i];
    }
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            cin >> mmax[i][j];
        }
    }
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            cin >> alloc[i][j];
        }
    }
    cout << endl << endl;
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            need[i][j] = mmax[i][j]-alloc[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    memset(finish,false,sizeof finish);

    isSafe();

    return 0;
}
