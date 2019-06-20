#include <iostream>
#include <fstream>
using namespace std;
struct student{
    char num[10];
    char xueyuan[10];
    char xingming[10];
    char x[10];
    int score[8]={0};
    double pj;
    double pj2;
    int t;
};
struct zuida{
    int e;
    int max;
};
struct zuixiao{
    int w;
    int min;
};
int main (){
    int n=4,y=0;
    student m[n];
    zuida a[n];
    zuixiao b[n];
    
    ifstream outf("/Users/s20181106279/Desktop/ggg.txt");
    ifstream out("/Users/s20181106279/Desktop/eee.txt");
    for(int i=0;i<n;i++){
        out>>m[i].num>>m[i].xueyuan>>m[i].xingming;
    }
    for(int i=0;i<n;i++){
        outf>>m[i].x;
        for(int j=0;j<7;j++){
            outf>>m[i].score[j];
        }
    }
    for(int i=0;i<n;i++){
        a[i].max=m[i].score[0];
        a[i].e=0;
        b[i].min=m[i].score[0];
        b[i].w=0;
        for(int j=1;j<7;j++){
            if(a[i].max<m[i].score[j]){
                a[i].max=m[i].score[j];
                a[i].e=j;
            }
            if(b[i].min>m[i].score[j]){
                b[i].min=m[i].score[j];
                b[i].w=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        double v=0;
        for(int k=0;k<7;k++){
            if(k!=a[i].e&&k!=b[i].w){
                v=v+m[i].score[k];
            }
        }
        m[y].pj=v*1.0/5;
        m[y].pj2=v*1.0/5;
        y++;
    }
    double gg;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(m[j].pj2<m[j+1].pj2){
                gg=m[j].pj2;
                m[j].pj2=m[j+1].pj2;
                m[j+1].pj2=gg;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i].pj2==m[j].pj){
                m[i].t=j;
            }
        }
    }
    ofstream in("/Users/s20181106279/Desktop/88.txt");
    if(in.is_open())
    {
        for(int i=0;i<4;i++){
            in<<m[m[i].t].num<<" "<<m[m[i].t].xueyuan<<" "<<m[m[i].t].xingming
            <<" "<<"paiming:"<<i+1<<" "<<"pingjunfen:"<<m[i].pj2<<endl;
        }
        in.close();
    }
    return 0;
    
}





