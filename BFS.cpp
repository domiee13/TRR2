#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#define MAX 100

using namespace std;

class doThi{
    int n;
    int A[MAX][MAX];
    public:
        int s;
        bool chuaxet[MAX];
        void khoiTao();
        void nhap1Dinh();
        bool docDuLieu(string filename);
        void BFS(int u);
};

void doThi::khoiTao(){
    for(int i = 1;i<= n;i++){
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

void doThi::BFS(int u){
    queue<int> hangdoi;
    int s;
    hangdoi.push(u);
    chuaxet[u] = false;
    while(!hangdoi.empty()){
        s= hangdoi.front(); //Lay dinh dau tien cua hang doi
        hangdoi.pop();      //Loai dinh dau tien cua hang doi
        cout<<s<<" ";
        for(int t= 1;t<=n;t++){
            if(A[s][t] && chuaxet[t]){
                hangdoi.push(t);    //Cho t vao hang doi
                chuaxet[t] = false;
            }
        }
    }
}

int main(){
    doThi G;
    if(G.docDuLieu("3_2_BFS.inp")){
        G.khoiTao();
        G.nhap1Dinh();
        G.BFS(G.s);
    }
    return 0;
}
