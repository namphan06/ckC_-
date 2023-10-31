#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
void find(string strl1, string strl2 ){
    vector<char> v1;
    for(int i=0;i<strl1.size();i++){
        v1.push_back(strl1[i]);
    }
    vector<char> v2;
    for(int i=0;i<strl2.size();i++){
        v2.push_back(strl2[i]);
    }
    string result ;
   
    for(int i=0;i<v1.size();i++){
         bool bl = false;
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                bl = true;
                break;
            }
        }
        if(!bl){
            result+=v1[i];
        }
    }
    
    for(int i=0;i<v2.size();i++){
        bool bl2 = false;
        for(int j=0;j<v1.size();j++){
            if(v2[i]==v1[j]){
                bl2 = true;
                break;
            }
        }
        if(!bl2){
            result+=v2[i];
        }
    }
    cout<<result;

}
int main(){
    string s = "htklfgh";
    string c = "ghjtf";
    find(s,c);
}