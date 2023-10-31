#include <iostream>
#include <vector>
#include <map>
using namespace std;
void winner(vector<string> Votes){
        map<string,int> mp1;
    for(string v : Votes){
        mp1[v]++;
    }
    int tmp =0;
    string tp;
    int tpp = 0 ;
    for(auto x : mp1){
        if(tmp < x.second){
            tmp = x.second;
            tp = x.first;
        }
    }
    vector<string>v1;
    for(auto x : mp1){
        if(x.second == tmp ){
            v1.push_back(x.first);
            tpp++;
        }
    }
    int count =0;
    if(tpp > 1){
        for(string s : v1){
            if(s.size()<count){
                count  = s.size();
                tp = s;
            }
        }
    }
    cout<<tp<<" : "<<tmp;
}
int main(){
    vector<string> Votes = {"john","jackie","johnny","john","jackie","jamie","jamie","john","johnny","jamie","johnny","john","hn","hn","hn","hn"};
    winner(Votes);
}