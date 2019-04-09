/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
vector<int> v[mx];
int visited[mx];
int n,m;
vector<int> cycle;
int parent[mx];

void cycleTrack(int p,int endpoint)
{
    cycle.push_back(p);
    if(parent[p]==endpoint){cycle.push_back(parent[p]);  return;}
    cycleTrack(parent[p],endpoint);
}

void cyclePrint()
{
    reverse(cycle.begin(),cycle.end());
    cout << "cycle : ";
    for(int i=0; i<cycle.size(); i++){
        cout << cycle[i] << " ";
    }
    cout << endl;
}

void dfs(int s)
{
    /// during entering coloring it as 1
    visited[s] = 1;
    for(int i=0; i<v[s].size(); i++){
        if(visited[v[s][i]]==0){
            parent[v[s][i]] = s;
            dfs(v[s][i]);
        }

        /// to detect a cycle checking if any node colored 1 is trying to access another node colored with 1
        if(visited[v[s][i]]==1){
            cycle.push_back(v[s][i]);
            cycle.push_back(s);
            cycleTrack(parent[s],v[s][i]);
            cyclePrint();
            cycle.clear();
            //return;
        }
    }
    /// during getting back from it coloring it as 2
    visited[s] = 2;

}


int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    #endif

    cin >> n >> m;
    int x,y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        //v[y].push_back(x);
    }

    /// initially making all the node 0
    memset(visited,0,sizeof visited);
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            dfs(i);
        }
    }


    return 0;
}


/*
sample input :
8 9
1 2
2 3
3 4
4 5
5 6
6 3
4 7
7 8
8 3
*/
