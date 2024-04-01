#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  int n,c;
  int arr[21][21]={0,};
  int fav[500][4];
  int seq[500];
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
  int total_val=0;


  cin>>n;

  for(int i=0;i<n*n;i++){
    cin>>c;
    seq[i]=c;
    for(int j=0;j<4;j++){
      cin>>fav[c][j];
    }
  }

  for(int i=0;i<n*n;i++){

    priority_queue<vector<int>> pq;
    priority_queue<vector<int>> npq;
    int big_cnt=0;
    int cur_cnt=0;

    for(int j=1;j<=n;j++){ //좋아하는 학생 인접 수 count
      for(int k=1;k<=n;k++){
        cur_cnt=0;
        if(arr[j][k]==0){
          for(int f=0;f<4;f++){
            for(int s=0;s<4;s++){
              if(0<j+dx[f]&&j+dx[f]<=n&&0<k+dy[f]&&k+dy[f]<=n){
                if(arr[j+dx[f]][k+dy[f]]==fav[seq[i]][s])
                  cur_cnt+=1;
              }
            }
          }
          vector<int> p;
          p.push_back(cur_cnt);
          p.push_back(j);
          p.push_back(k);
          pq.push(p);
        }
      }
    }

    big_cnt=pq.top()[0];

    while(!pq.empty()){
      if(pq.top()[0]!=big_cnt)
        break;
      npq.push(pq.top());
      pq.pop();
    }
    pq=npq;
    while(!npq.empty())
      npq.pop();

    if(pq.size()==1){ //하나만 있는 경우 넣고 넘어감
      arr[pq.top()[1]][pq.top()[2]]=seq[i];
      continue;
    }


    while(!pq.empty()){
      int j=pq.top()[1];
      int k=pq.top()[2];
      pq.pop();
      cur_cnt=0;
      for(int f=0;f<4;f++){
        for(int s=0;s<4;s++){
          if(0<j+dx[f]&&j+dx[f]<=n&&0<k+dy[f]&&k+dy[f]<=n) {
            if (arr[j + dx[f]][k + dy[f]] == 0)
              cur_cnt += 1;
          }
        }
      }
      vector<int> p;
      p.push_back(cur_cnt);
      p.push_back(j);
      p.push_back(k);
      npq.push(p);
    }


    big_cnt=npq.top()[0];
    while(!npq.empty()){
      if(npq.top()[0]!=big_cnt)
        break;
      pq.push(npq.top());
      npq.pop();
    }
    while(!npq.empty())
      npq.pop();

    if(pq.size()==1){ //하나만 있는 경우 넣고 넘어감
      arr[pq.top()[1]][pq.top()[2]]=seq[i];
      continue;
    }

    while(!pq.empty()){
      int j=pq.top()[1];
      int k=pq.top()[2];
      pq.pop();
      vector<int> p;
      p.push_back(j*-1);
      p.push_back(k*-1);
      npq.push(p);
    }

    arr[npq.top()[0]*-1][npq.top()[1]*-1]=seq[i];
  }


  for(int j=1;j<=n;j++){ //좋아하는 학생 인접 수 count
    for(int k=1;k<=n;k++) {
      int cur_val=0;
      for(int f=0;f<4;f++){
        for(int s=0;s<4;s++){
          if(0<j+dx[f]&&j+dx[f]<=n&&0<k+dy[f]&&k+dy[f]<=n){
            if(arr[j+dx[f]][k+dy[f]]==fav[arr[j][k]][s]){
              if(cur_val==0)
                cur_val+=1;
              else
                cur_val*=10;
            }
          }
        }
      }
      total_val+=cur_val;
    }
  }

  cout<<total_val<<'\n';

}
