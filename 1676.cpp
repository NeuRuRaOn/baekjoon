#include <iostream>
using namespace std;

int main(){
    int two_counter=0;
    int five_counter=0;
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int div=i;
        while(div%2==0||div%5==0){
            if(div%2==0){
                div=div/2;
                two_counter++;
            }
            else if(div%5==0){
                div=div/5;
                five_counter++;
            }
        }
    }
    cout<<min(two_counter,five_counter)<<endl;

}