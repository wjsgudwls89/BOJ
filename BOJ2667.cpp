////
//// Created by 전형진 on 2019-04-08.
////
//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int n;
//int map[26][26];
//int visit[26][26];
//int cnt=0;
//int house=0;
//int dx[]={0,1,0,-1};
//int dy[]={1,0,-1,0};
//vector<int> v;
//
//void bfs(int y,int x){
//    queue<int> xq;
//    queue<int> yq;
//
//    visit[y][x] = true;
//    xq.push(x);
//    yq.push(y);
//    house =0;
//    while(!xq.empty()){
//        int x = xq.front();
//        int y = yq.front();
//        xq.pop();yq.pop();
//
//        for(int i=0;i<4;i++) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if(nx>=0 && ny>=0 && nx<n && ny<n){
//                if(map[ny][nx] !=0 && !visit[ny][nx]){
//                    visit[ny][nx] = true;
//                    xq.push(nx);
//                    yq.push(ny);
//                }
//            }
//        }
//        house++;
//    }
//    v.push_back(house);
//}
//
//int main(){
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            scanf("%1d",&map[i][j]);
//        }
//    }
//
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++) {
//            if (map[i][j] == 1 && !visit[i][j]) {
//                bfs(i,j);
//                cnt++;
//            }
//        }
//    }
//    printf("%d\n",cnt);
//    sort(v.begin(),v.end());
//    for (int i = 0; i < v.size(); ++i) {
//        printf("%d\n",v[i]);
//    }
//}