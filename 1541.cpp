#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int val=0;
    int store=0;
    int mf=0;
    string cur="";

    for(int i=0;i<s.length();i++){
        if(s[i]!='-'&&s[i]!='+'){
            cur=cur+s[i];
        }
        else{
            if(s[i]=='-'){
                if(mf==0){
                    store=val+stoi(cur);
                    val=0;
                    cur="";
                    mf=1;
                }
                else if(mf==1){
                    store=store-(val+stoi(cur));
                    val=0;
                    cur="";
                }
            }
            if(s[i]=='+'){
                val+=stoi(cur);
                cur="";
            }
        }
    }
    if(mf==1){
        cout<<store-(val+stoi(cur))<<"\n";
    }
    else
        cout<<val+stoi(cur)<<endl;
}
