////
//// Created by 전형진 on 2020-03-19.
////
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int arr[101];
//int temp[101];
//
//int n;
//struct team{
//    int num;
//    int idx;
//    int rank;
//};
//vector<team> v;
//
//void game(int team1, int team2,int t1score, int t2score ){
//
//    if(t1score > t2score){
//        arr[team1] += 3;
//    }
//    else if(t1score == t2score){
//        arr[team1]+=1;
//        arr[team2]+=1;
//    }
//    else if(t1score < t2score){
//        arr[team2]+=3;
//    }
//
//}
//
//int main(){
//    scanf("%d",&n);
//    int a,b,c,d;
//    for (int i = 0; i < n*(n-1)/2; ++i) {
//        scanf("%d %d %d %d",&a,&b,&c,&d);
//        game(a,b,c,d);
//    }
//
//    for (int i = 1; i <=n; ++i) {
//        int rank = 1;
//
//        for (int j = 1; j <=n ; ++j) {
//            if(arr[j]>arr[i]) rank++;
//        }
//        printf("%d\n",rank);
//    }
//}
//
// Created by 전형진 on 2020-03-19.
//
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
int temp[101];
int visit[101];

int n;
struct team{
    int num;
    int idx;
    int rank;
};
vector<team> v;

bool comp(const team &a,const team &b){

    return a.num>b.num;
}
bool comp2(const team &a,const team &b){

    return a.idx<b.idx;
}
void game(int team1, int team2,int t1score, int t2score ){

    if(t1score > t2score){
        arr[team1] += 3;
    }
    else if(t1score == t2score){
        arr[team1]+=1;
        arr[team2]+=1;
    }
    else if(t1score < t2score){
        arr[team2]+=3;
    }

}

int main(){
    scanf("%d",&n);
    int a,b,c,d;
    for (int i = 0; i < n*(n-1)/2; ++i) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        game(a,b,c,d);
    }
    for (int i = 1; i <= n; ++i) {
        v.push_back({arr[i],i});
    }

    sort(v.begin(),v.end(),comp);

    for (int i = 0 ; i <n ; ++i) {
        v[i].rank = i+1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(i==j) continue;
            if(v[i].num == v[j].num && visit[j] == 0){
                v[i].rank = i+1;
                v[j].rank = i+1;
                visit[j] = 1;
            }
        }
    }

    sort(v.begin(),v.end(),comp2);
    for (int i = 0 ; i < n ; ++i) {
        printf("%d\n",v[i].rank);
    }
}