#include<bits/stdc++.h>
using namespace std;

void topo_sort(vector<vector<int>>&adj, stack<int>&s1, vector<bool>&visit,int i){
    if(visit[i]){
        return ;
    }
    visit[i] = 1;
    for(int j=0; j<adj[i].size(); j++){
        topo_sort(adj, s1, visit, adj[i][j]);
    }

    s1.push(i);
}

void topo_sort_bfs(vector<vector<int>>&adj, vector<int>&indegree, vector<bool>&visit, vector<int>&ans){
    queue<int>q1;
    for(int j =0; j<indegree.size(); j++){
        if(indegree[j] == 0){
            q1.push(j);
        }
    }

    while(!q1.empty()){
        int top = q1.front();
        q1.pop();
        for(int i =0; i<adj[top].size(); i++){
            indegree[adj[top][i]]--;
            if(indegree[adj[top][i]]==0){
                visit[adj[top][i]] = 1;
                q1.push(adj[top][i]);
            }
        }
        ans.push_back(top);
    }
}

int main(){
    int u,v;
    cout<<"enter the edges and vertex: "<<endl;
    cin>>u>>v;
    
    vector<vector<int>>adj(v);
    for(int i=0; i<u; i++){
        cout<<"enter the edges: ";
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);   
    }

    int choice;
    cout<<"menu:\n 1.toposort using dfs\n 2.toposort using bfs\n";
    cout<<"enter the choice :\n";
    cin>>choice;

    while(choice){
        if(choice == 1){
            stack<int>s1;
            cout<<"sort is:"<<endl;
            vector<bool>visit(v,0);
            for(int i = 0; i<v; i++){
                if(!visit[i]){
                    topo_sort(adj,s1,visit,i);
                }
            }
            while(!s1.empty()){
                cout<<s1.top()<<" ";
                s1.pop();
            }
            cout<<"Enter the choice: "<<endl;
            cin>>choice;
        }

        else if(choice == 2){
            vector<bool>visit(v,0);
            vector<int>indegree(v,0);
            vector<int>ans;
            for(int i=0; i<v; i++){
                for(int j= 0; j<adj[i].size();j++){
                    indegree[adj[i][j]]++;
                }
            }

            topo_sort_bfs(adj, indegree, visit, ans);

            cout<<"sort is: "<<endl;
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<"enter the choice: "<<endl;
            cin>>choice;
        }
    }

}