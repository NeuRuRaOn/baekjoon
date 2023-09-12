#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int arr[MAX][MAX];
int cnt[MAX][MAX];
int N,M;
int main(){
    cin>>M>>N;
    queue <int> x;
    queue <int> y;
    for(int j=1;j<=M;j++){
       string line;
       cin>>line;
       for(int i=1;i<=N;i++){
           if(line[i-1]=='1')
               arr[i][j]=1;
           if(line[i-1]=='0')
               arr[i][j]=0;
       }
    }
    x.push(1);
    y.push(1);
    cnt[1][1]=1;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    while(x.empty()==0){
        int cur_x=x.front();
        int cur_y=y.front();
        //printf("curx:%d cury:%d cnt:%d \n",cur_x,cur_y,cnt[cur_x][cur_y]);
        int cur_val=cnt[cur_x][cur_y];
        x.pop();
        y.pop();
        for(int i=0;i<4;i++){
            int new_x=cur_x+dx[i];
            int new_y=cur_y+dy[i];
            if(arr[new_x][new_y]==1 && cnt[new_x][new_y]==0){
                cnt[new_x][new_y]=cur_val+1;
                x.push(new_x);
                y.push(new_y);
            }
        }
    }
    cout<<cnt[N][M]<<"\n";
}