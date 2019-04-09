/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

int memholes, requests,x;
vector<int> holes,req;
bool taken[100];

void print()
{
    for(int i=0; i<memholes; i++){
        cout << holes[i] << " ";
    }
    cout << endl;
}

int firstFit()
{
    for(int i=0; i<requests; i++){
        if(!taken[i]){
            for(int j=0; j<memholes; j++){
                if(holes[j] >= req[i]){
                    holes[j] -= req[i];
                    taken[i] = true;
                    print();
                    break;
                }
            }
        }
    }
    int frag = 0;
    for(int i=0; i<memholes; i++){
        frag += holes[i];
    }
    return frag;
}


int bestFit()
{
    for(int i=0; i<requests; i++){
        if(!taken[i]){
            int ind = -1;
            int mn = INT_MAX;
            for(int j=0; j<memholes; j++){
                if(holes[j]-req[i] >= 0 && holes[j]-req[i]<mn){
                    mn = holes[j]-req[i];
                    ind = j;
                }
            }

            if(ind != -1){
                holes[ind] -= req[i];
                taken[i] = true;
                print();
            }
            else{break;}
        }
    }
    int frag = 0;
    for(int j=0; j<requests; j++){
        if(!taken[j]){
            for(int i=0; i<memholes; i++){
                frag += holes[i];
            }
            break;
        }
    }
    return frag;

}

int worstFit()
{
    for(int i=0; i<requests; i++){
        if(!taken[i]){
            int ind = -1;
            int mx = INT_MIN;
            for(int j=0; j<memholes; j++){
                if(holes[j]-req[i] >= 0 && holes[j]-req[i]>mx){
                    mx = holes[j]-req[i];
                    ind = j;
                }
            }

            if(ind != -1){
                holes[ind] -= req[i];
                taken[i] = true;
                print();
            }
            else{break;}
        }
    }
    int frag = 0;
    for(int j=0; j<requests; j++){
        if(!taken[j]){
            for(int i=0; i<memholes; i++){
                frag += holes[i];
            }
            break;
        }
    }
    return frag;

}




int main()
{
    cin >> memholes >> requests;
    for(int i=0; i<memholes; i++){
        cin >> x;
        holes.push_back(x);
    }
    for(int i=0; i<requests; i++){
        cin >> x;
        req.push_back(x);
    }

    memset(taken, false, sizeof taken);

    int x ;
    ///x = firstFit();
    ///x = bestFit();
    x = worstFit();

    cout << x << endl;

    return 0;
}


