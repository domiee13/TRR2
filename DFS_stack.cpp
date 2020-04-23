#include <iostream>
#include <fstream>
#include <string>
#include <stack>
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
        void DFS_stack(int u);
};

void doThi::khoiTao(){
    for(int i = 1;i<=n;i++){
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
        cout<<"Ma tran ke cua do thi la: "<<endl;
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

void doThi::DFS_stack(int u){
    stack<int> tmp;
    tmp.push(u);
    cout<<u<<" ";
    chuaxet[u] = false;
    while(!tmp.empty()){
        int u = tmp.top(); //Lay phan tu dau tien cua stack
        tmp.pop(); //xoa phan tu dau tien khoi stack
        for(int t = 1;t<=n;t++){
            if(chuaxet[t] && A[u][t]){
                tmp.push(u);
                tmp.push(t);
                cout<<t<<" ";
                chuaxet[t]= false;
                break;
            }
        }
    }
}

int main(){
    doThi G;
    if(G.docDuLieu("maTranKe.inp")){
        G.khoiTao();
        G.nhap1Dinh();
        G.DFS_stack(G.s);
    }
    return 0;
}