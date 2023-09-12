#include <iostream>
#include <queue>
using namespace std;
#define MAX 26

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[MAX][MAX]={0,};
int num[MAX][MAX]={0,};

void dfs(int x,int y,int cur_num){
    num[x][y]=cur_num;
    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(arr[new_x][new_y]==1&&num[new_x][new_y]==0){
            dfs(new_x,new_y,cur_num);
        }
    }
}

int main(){
    int N;
    priority_queue <int> cnt;
    cin>>N;
    string line;
    for(int j=0;j<N;j++){
        cin>>line;
        for(int i=0;i<N;i++){
            if(line[i]=='1')
                arr[i][j]=1;
            if(line[i]=='0')
                arr[i][j]=0;
        }
    }

    int cur_num=1;
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            if(arr[i][j]==1&&num[i][j]==0){
                dfs(i,j,cur_num);
                cur_num++;
            }
        }
    }

    for(int c=1;c<cur_num;c++){
        int cur_cnt=0;
        for(int j=0;j<N;j++){
            for(int i=0;i<N;i++){
                if(num[i][j]==c)
                    cur_cnt++;
            }
        }
        cnt.push(-1*cur_cnt);
    }
    cout<<cur_num-1<<"\n";
    while(cnt.empty()==0){
        cout<<cnt.top()*-1<<"\n";
        cnt.pop();
    }



}