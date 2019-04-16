////
//// Created by 전형진 on 2019-04-15.
////
//#include <stdio.h>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int bigNode[100];
//int smallNode[100];
//int n;
//int m;
//int times[100];
//int cnt=0;
//
//vector<int>v[100];
//
//void bfs(int i){
//    for (int j = 1; j <=n; ++j) {
//            times[j] =0;
//    }
//    queue<int> q;
//    int small=0;
//    q.push(i);
//
//    while(!q.empty()){
//        int x = q.front();
//        q.pop();
//        for(int a=0;a<v[x].size();a++){
//                int nx = v[x][a];
//                if(times[nx] == 0){
//                    bigNode[nx]++;
//                    small++;
//                    times[nx] = 1;
//                    q.push(nx);
//            }
//        }
//    }
//    smallNode[i] = small;
//}
//int main(){
//    int a,b;
//    scanf("%d %d",&n,&m);
//    for(int i=0;i<m;i++){
//        scanf("%d %d",&a,&b);
//        v[a].push_back(b);
//    }
//    for(int i=1;i<=n;i++){
//        bfs(i);
//    }
//    cnt=0;
//    for(int i=1;i<=n;i++){
//        if(bigNode[i] >= ((n+1)/2) || smallNode[i] >= ((n+1)/2))
//            cnt++;
//    }
//    printf("%d",cnt);
//}