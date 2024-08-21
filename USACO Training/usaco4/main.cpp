/*
    ID: axi21001
    TASK: beads
    LANG: C++
    */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin ("beads.in");
    ofstream fout;
    fout.open("beads.out");
    string line;
     getline(fin, line);
    int num = stoi(line);
    getline(fin, line);
   string sequence = line;
 
 //  string sequence = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
   sequence = sequence + sequence;
   //cout<<num;
   int lr[800][2];
   int rl[800][2];
 // std::fill(&lr[0][0], &lr[0][0] + 800 * 2, 0);
 // std::fill(&rl[0][0], &rl[0][0] + 800 * 2, 0);
   lr[0][0] = 0;
   lr[0][1] = 0;
   rl[2 *num][0] = 0;
   rl[2 * num][1] = 0;
  /* if(sequence[0] == 'w'){
       lr[0][1] = 1;
       lr[0][0] = 1;
   }
   if(sequence[0] == 'r'){
       lr[0][1] = 1;
   }
   if(sequence[0] == 'b'){
       lr[0][0] = 1;
   }
   
    if(sequence[num - 1] == 'w'){
       rl[num - 1][1] = 1;
       rl[num - 1][0] = 1;
   }
   if(sequence[num - 1] == 'r'){
       rl[num - 1][1] = 1;
   }
   if(sequence[num - 1] == 'b'){
       rl[num - 1][0] = 1;
   }*/
   for(int i = 1; i < 2 * num; i++){
       //cout<<sequence[i]<<" "<<lr[];
       if(sequence[i -  1] == 'w'){
           lr[i][0] = lr[i - 1][0] + 1;
        lr[i][1] = lr[i - 1][1] + 1;
       }
      else if(sequence[i - 1] == 'r'){
             lr[i][1] = lr[i - 1][1] + 1;
             lr[i][0] = 0;
       }
      else if(sequence[i - 1] == 'b'){
           lr[i][0] = lr[i - 1][0] + 1;
           lr[i][1] = 0;
       }
   }
   for(int i =2 *  num - 1; i >= 0; i--){
       if(sequence[i] == 'w'){
           rl[i][0] = rl[i + 1][0] + 1;
        rl[i][1] = rl[i + 1][1] + 1;
       }
      else if(sequence[i] == 'r'){
             rl[i][1] = rl[i + 1][1] + 1;
             rl[i][0] = 0;
       }
      else if(sequence[i] == 'b'){
           rl[i][0] = rl[i + 1][0] + 1;
           rl[i][1] = 0;
       }
   }
    int ans = 0;
    for(int i = 0; i < 2 * num; i++){
       
        int cur_ans = max(rl[i][0], rl[i][1])+ max(lr[i][1], lr[i][0]);
       // if(i == 2) cout<<cur_ans;
       //int cur_ans2 = max(rl[i][0] + lr[i][0], rl[i][1] + lr[i][1]);
       //cout<<rl[i][0]<<" ";
       // cur_ans = max(cur_ans, cur_ans2);
        ans = max(cur_ans, ans);
    }
    ans = min(2 * num , ans);
    fout<< ans<<endl;
    return 0;
}