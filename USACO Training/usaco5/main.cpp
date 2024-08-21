/*
    ID: axi21001
    TASK: milk2
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin ("milk2.in");
    ofstream fout;
    fout.open("milk2.out");
    string line;
     getline(fin, line);
    int num = stoi(line);
    vector<pair<int, int>> vec;
    while(getline(fin, line)){
        pair<int, int> p;
        p.first = stoi(line.substr(0, line.find(" ")));
        p.second = stoi(line.substr(line.find(" ") + 1));
        vec.push_back(p);
    }
   sort(vec.begin(), vec.end());
    vector<pair<int, int>> cur;
    pair<int,int> p = vec[0];
    vec.erase(vec.begin());
    int max_wait = p.first - 0;
    int l = p.first;
    int h = p.second;
    
    while(!vec.empty()){
        pair<int,int> pop = vec[0];
       // cout<<pop.first<<endl;
        
        vec.erase(vec.begin());
        if(pop.first > h){
            pair<int,int> n;
            n.first =l;
            n.second = h;
            cur.push_back(n);
            l = pop.first;
            h = pop.second;
        }
        else {
            h = max(l, pop.second);
        }
    }
    pair<int,int> last;
    last.first = l;
    last.second = h;
    cur.push_back(last);
    int longest_duration = cur[0].second - cur[0].first;
   // cout<<cur[0].first<<" ";
   // cout<<cur[0].second<<endl;
    for(int i =1; i < cur.size();i++){
         //cout<<cur[i].first<<" ";
  //  cout<<cur[i].second<<endl;
        longest_duration = max(cur[i].second - cur[i].first, longest_duration);
        max_wait = max(max_wait, cur[i].first - cur[i - 1].second);
    }
    fout<< longest_duration;
    fout<<" "<<max_wait<<endl;
    return 0;
}