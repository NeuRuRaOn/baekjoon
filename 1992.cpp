#include <iostream>
using namespace std;
#define MAX 64


int arr[MAX][MAX];
void div(int x,int y,int n){
    //printf("x: %d y: %d n: %d \n",x,y,n);
    if(n==1){
        cout<<arr[x][y];
        return;
    }
    int chk=0;
    int first=arr[x][y];
    for(int j=y;j<y+n;j++){
        for(int i=x;i<x+n;i++){
            if(first!=arr[i][j]){
                //printf("chk x: %d y: %d n: %d i:%d j:%d \n",x,y,n,i,j);
                chk=1;
                break;
            }
        }
        if(chk==1)
            break;
    }
    if(chk==0){
        cout<<first;
    }
    else{
        int half=n/2;
        cout<<"(";
        div(x,y,half);
        div(x+half,y,half);
        div(x,y+half,half);
        div(x+half,y+half,half);
        cout<<")";
    }
}

int main(){
    int N;
    cin>>N;
    string cur;
    for(int j=0;j<N;j++){
        cin>>cur;
        for(int i=0;i<N;i++){
            if(cur[i]=='1')
                arr[i][j]=1;
            if(cur[i]=='0')
                arr[i][j]=0;
        }
    }


    div(0,0,N);
}