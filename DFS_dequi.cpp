#include <iostream>
#include <string>
#include <fstream>
#define MAX 100

using namespace std;

class doThi{
    int n;
    int A[MAX][MAX]; // Luu ma tran ke cua do thi
    public:
        int s;
        string myName = "My graph";
        bool chuaxet[MAX] = {true};
        void rep();
        void khoiTao();
        bool docDuLieu(string filename); //Doc file 
        void nhap1Dinh();
        void DFS_dequy(int u); //DFS tu dinh u
};

void doThi::rep(){
    cout<<myName<<endl;
}

void doThi::khoiTao(){
    for(int i= 1;i<=n;i++){
        chuaxet[i] = true;
    }
}

void doThi::nhap1Dinh(){
    cout<<"s = ";
    cin>>s;
}

bool doThi::docDuLieu(string filename){
    ifstream inp(filename.c_str(),ios::in);
    if(inp.is_open()){
        inp>>n;
        cout<<"So dinh cua do thi la: "<<n<<endl;
        cout<<"Ma tran ke la: "<<endl;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                inp>>A[i][j];
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    return false;
}

void doThi::DFS_dequy(int u){
    cout<<u<<" "; //Thăm đỉnh u
    chuaxet[u] = false;
    for(int v = 1;v<=n;v++){
        if(chuaxet[v] && A[u][v]){
            DFS_dequy(v);
        }
    }
}


int main(){
    doThi G;
    G.rep();
    if(G.docDuLieu("maTranKe.inp")){
        cout<<"Doc file OK"<<endl;
        G.khoiTao();
        G.nhap1Dinh();
        G.DFS_dequy(G.s);
    };
    return 0;
}