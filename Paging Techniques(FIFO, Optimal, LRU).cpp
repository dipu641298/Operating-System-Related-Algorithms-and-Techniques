/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

int n;
int frameSize;
int totPage;
vector<int> pages;
bool check[30];
int pos[5];

int fifo()
{
    int cnt = 0;
    queue<int> q;

    for(int i=0; i<frameSize; i++){
        q.push(pages[i]);
        check[pages[i]] = true;
    }

    for(int i=frameSize; i<totPage; i++){
        if(!check[pages[i]]){
            int x = q.front();
            q.pop();
            check[x] = false;
            q.push(pages[i]);
            check[pages[i]] = true;
        }
        else{cnt++;}
    }

    return totPage-cnt;
}


int optimal()
{
    int cnt = 0;
    vector<int> v;

    for(int i=0; i<frameSize; i++){
        v.push_back(pages[i]);
        check[pages[i]] = true;
    }

    for(int i=frameSize; i<totPage; i++){
        if(!check[pages[i]]){
            int mx = -1;
            int val;
            for(int j=0; j<frameSize; j++){
                bool f = false;
                for(int k=i+1; k<totPage; k++){
                    if(pages[k] == v[j]){
                        if(k>mx){mx = k; val = v[j]; }
                        f = true;
                        break;
                    }
                }
                if(!f){val = v[j], mx = INT_MAX;}
            }

            for(int j=0; j<frameSize; j++){
                if(v[j]==val){v[j] = pages[i]; check[pages[i]] = true; check[val] = false;}
            }
        }
        else{cnt++;}
    }

    return totPage-cnt;

}


int lru()
{
    int cnt = 0;
    vector<int> v;

    for(int i=0; i<frameSize; i++){
        v.push_back(pages[i]);
        check[pages[i]] = true;
    }

    for(int i=frameSize; i<totPage; i++){
        if(!check[pages[i]]){
            int mn = INT_MAX;
            int val;
            for(int j=0; j<frameSize; j++){
                bool f = false;
                for(int k=i-1; k>=0; k--){
                    if(pages[k] == v[j]){
                        if(k<mn){mn = k; val = v[j]; }
                        f = true;
                        break;
                    }
                }
                if(!f){val = v[j], mn = INT_MIN;}
            }

            for(int j=0; j<frameSize; j++){
                if(v[j]==val){v[j] = pages[i]; check[pages[i]] = true; check[val] = false;}
            }
        }
        else{cnt++;}
    }

    return totPage-cnt;

}

int main()
{
    cin >> n;
    cin >> totPage;
    cin >> frameSize;
    int x;
    for(int i=0; i<totPage; i++){
        cin >> x;
        pages.push_back(x);
    }

    memset(check,false,sizeof check);
    int fi = fifo();

    cout << "page fault in fifo : " << fi << endl;
    cout << "rate : "<< (fi*100)/totPage << endl;

    memset(check,false,sizeof check);
    int op = optimal();

    cout << "page fault in optimal : " << op << endl;
    cout << "rate : "<< (op*100)/totPage << endl;

    memset(check,false,sizeof check);
    int lr = lru();

    cout << "page fault in lru : " << lr << endl;
    cout << "rate : "<< (lr*100)/totPage << endl;



    return 0;
}
