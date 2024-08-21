/*
    ID: axi21001
    TASK: wormhole
    LANG: C++17
*/

#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define FOR(i, a , b) for(int i = a; i <= b; i++)

ofstream fout;
int sol = 0;
vector<pair<int, int>> points;
map<pair<int, int>, pair<int, int>> wormholeMap;
vector<pair<pair<int, int>, pair<int, int>>> pairs;
int  isCycle = 0;

void DFS(set<pair<int, int>>& visited, pair<int,int> &cur) {
    if (isCycle == 1 || isCycle == 2) return;
    auto p1 = cur;
     //cout<<p1.first<<" "<<p1.second<<endl;
    if (visited.count(p1)) {
       // cout<<" worked"<<p1.first<<". "<<p1.second;
        isCycle = 1;
        sol++;
        return;
    }
   
   visited.insert(p1);
    if (wormholeMap.find(p1) == wormholeMap.end()) {
        
       // cout<<"ok"<<endl;
        isCycle = 2;
        return;
    }
    auto next = wormholeMap[p1];
    /*if (visited.count(next)) {
        isCycle = 1;
        sol++;
        cout<<"worked";
        return;
    }*/
     
    for (int j = 0; j < pairs.size(); j++) {
        auto [np1, np2] = pairs[j];
        if (np1 == next) {
            return DFS(visited, pairs[j].second);
        }
        else if(np2 == next){
           
            return DFS(visited, pairs[j].first);
        }
    }
    //if (nextIndex != -1) DFS(nextIndex, visited);
}

void backtrack(int i, vector<bool>& used) {
    if (i >= points.size()) {
        
        for (int j = 0; j < pairs.size(); j++) {
            if (isCycle == 1) break;
            isCycle = 0;
            set<pair<int, int>> visited;
            visited.clear();
            DFS(visited, pairs[j].first);
           // cout<<endl;
             if (isCycle == 1) break;
            isCycle = 0;
            visited.clear();
            DFS(visited, pairs[j].second);
             if (isCycle == 1) break;
           // isCycle = 0;
            //cout<<endl;
        }
       // cout<<"done"<<'\n';
        isCycle = 0;
        return;
    }
    if(used[i]){
        return backtrack(i + 1, used);
    }
    
    for (int x = i + 1; x < points.size(); x++) {
        if (used[x]) continue;
        auto pt1 = points[i];
        auto pt2 = points[x];
        pairs.push_back({pt1, pt2});
        used[x] = true;
        backtrack(i + 1, used);
        pairs.pop_back();
        used[x] = false;
    }
}

int main() {
    ifstream fin("wormhole.in");
    fout.open("wormhole.out");

    int n;
    fin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < points.size(); i++) {
        auto current_point = points[i];
        pair<int, int> nearest = {INT_MAX, INT_MAX};
        for (int j = 0; j < points.size(); j++) {
            if (i == j) continue;
            auto nxt_pt = points[j];
            if (nxt_pt.second == current_point.second && nxt_pt.first > current_point.first) {
                if (nxt_pt.first < nearest.first) {
                    nearest = nxt_pt;
                }
            }
        }
        if (nearest.first != INT_MAX) {
            wormholeMap[current_point] = nearest;
        }
    }
  
    vector<bool> used(points.size(), false);
    
    backtrack(0, used);

    fout << sol << endl;
    return 0;
}
