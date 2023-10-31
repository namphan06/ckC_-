#include <iostream>
#include <vector>
using namespace std;
void kt(string a, string b){
    int count = 0;
    bool bl = false;
    vector<int> index;
    
    for(int i=0;i<a.size();i++){
        if(a[i] == b[count]){
            count++;
        }
        else{
            index.push_back(i);
        }
        
    }
    if(count==b.size()){
            bl = true;
    }
    if(!bl){
        cout<<"0"<<endl;
    }
    else{
        cout<<"1"<<endl;
        for(int i : index){
            cout<<i<<"\t";
        }
    }
}
void check(string a, string b){
    if(a.size()>b.size()){
        kt(a,b);
    }
    else{
        cout<<"0"<<endl;
    }
}
int main(){
    string A = "abcef14&f";
    string B = "b1&";
    string C ="12";
    string D = "123";
    string A1 = "acef1b4&f";
    string B1 = "b1&";
    check(C,D);
}