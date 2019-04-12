////
//// Created by 전형진 on 2019-04-12.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int cnt =0;
//using namespace std;
//int N, M;
//string d[500001];
//string b;
//
//int main(){
//    vector<string> cal;
//    //ios::sync_with_stdio(false);
//    scanf("%d %d",&N,&M);
//    for(int i=0;i<N;i++){
//        cin>>d[i];
//    }
//    sort(d,d+N);
//    for(int i=0;i<M;i++){
//        cin>>b;
//        if(binary_search(d,d+N,b)){
//            cal.push_back(b);
//            cnt++;
//        }
//    }
//    sort(cal.begin(),cal.end());
//    printf("%d\n",cnt);
//    for(int i=0;i<cal.size();i++)
//    cout<<cal[i]<<"\n";
//}