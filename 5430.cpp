#include <iostream>
#include <vector>
using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
        vector <int> arr;
        string op;
        int n;
        string string_arr;
        int err=0;
        cin>>op;
        cin>>n;
        cin>>string_arr;
        string cur_string="";
        if(n>0) {
            for (int i = 1; i < string_arr.size(); i++) {
                if ((string_arr[i] == ',' || string_arr[i] == ']') && cur_string.empty() == 0) {
                    arr.push_back(stoi(cur_string));
                    cur_string = "";
                } else {
                    cur_string.push_back(string_arr[i]);
                }
            }
        }

        int start=0;
        int end=arr.size()-1;
        int r_cnt=0;


        for(int i=0;i<op.length();i++){
            if(op[i]=='D'){
                if(start>end) {
                    err = 1;
                    break;
                }
                else{
                    if(r_cnt%2==0)
                        start++;
                    else
                        end--;
                }
            }
            if(op[i]=='R'){
                r_cnt++;
            }
        }
        if(err==1)
            cout<<"error\n";
        else if(start>end)
            cout<<"[]\n";
        else {
            if (r_cnt % 2 == 0) {
                cout << "[";
                for (int i = start; i < end; i++)
                    cout << arr[i] << ",";
                cout << arr[end] << "]\n";
            } else {
                cout << "[";
                for (int i = end; i > start; i--)
                    cout << arr[i] << ",";
                cout << arr[start] << "]\n";
            }
        }
    }
}
