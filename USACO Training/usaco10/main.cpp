/*
    ID: axi21001
    TASK: milk
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define PB push_back;
#define FOR(i, a , b) for(int i = a; i <= b; i++)
ofstream fout;
bool compareInterval(pair<int,int>  i1, pair<int,int> i2) 
{ 
    return (i1.first < i2.first); 
} 
int main()
{
    ifstream fin ("milk.in");
    
    fout.open("milk.out");
    string line;
     getline(fin, line);
     int n = stoi(line.substr(0, line.find(" ")));
     int m = stoi(line.substr(line.find(" ") + 1));
     vector<pair<int,int>> vec;
     FOR(i, 2, m + 1){
        
            getline(fin, line);
            pair<int,int> x;
            x.first = stoi(line.substr(0, line.find(" ")));
            x.second = stoi(line.substr(line.find(" ") + 1));
            vec.push_back(x);
     }
     sort(vec.begin(), vec.end(), compareInterval);
     int i = 0;
     int sum = 0;
     while(n > 0){
        // cout<<vec[i].first * min(vec[i].second, n)<<endl;
         sum += (vec[i].first * min(vec[i].second, n));
         n -=vec[i].second;
         i++;
     }
     fout<<sum<<endl;
    exit(0);
}
