#include <iostream>
#include <cmath>
using namespace std;
#define  MAX 2187

int arr[MAX][MAX];
int cnt[3];
void div(int n,int x,int y){
    //printf("n: %d x: %d y: %d\n",n,x,y);
    if(n==0) {
        cnt[arr[x][y] + 1]++;
        return;
    }
    int chk=0;
    int first=arr[x][y];
    for(int i=x;i<x+pow(3,n);i++){
        for(int j=y;j<y+pow(3,n);j++){
            if(arr[i][j]!=first)
            {
                chk=1;
                break;
            }
        }
        if(chk==1)
            break;
    }
    if(chk==0) {
        cnt[first + 1]++;
        return;
    }
    else {
        int cut=pow(3,n-1);
        div(n-1,x,y);
        div(n-1,x+cut,y);
        div(n-1,x+2*cut,y);
        div(n-1,x,y+cut);
        div(n-1,x+cut,y+cut);
        div(n-1,x+2*cut,y+cut);
        div(n-1,x,y+2*cut);
        div(n-1,x+cut,y+2*cut);
        div(n-1,x+2*cut,y+2*cut);

    }
}

int main(){
    int N;
    int n;
    cin>>N;
    int pow3[8]={1,3,9,27,81,243,729,2187};
    for(int i=0;i<8;i++){
        if(pow3[i]==N)
            n=i;
    }
    int cur;
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            cin>>cur;
            arr[i][j]=cur;
        }
    }
    div(n,0,0);
    cout<<cnt[0]<<"\n"<<cnt[1]<<"\n"<<cnt[2]<<"\n";
}
