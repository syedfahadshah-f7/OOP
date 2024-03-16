#include<iostream>
using namespace std;
inline int strike_rate(int total_runs,int total_balls){
    return total_runs/total_balls*100;
}
inline int average_score(int total_runs, int total_outs){
    return total_runs/total_outs;
}
int main(){
    cout<<"STRIKE RATE OF BATSMAN: "<<strike_rate(164,42)<<endl;
    cout<<"Average SCore Of Batsman: "<< average_score(5550,15)<<endl;
    return 0;
}
