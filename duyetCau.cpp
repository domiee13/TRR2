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
        void Reset();
        void nhap1Dinh();
        bool docDuLieu(string filename);
        void DFS(int u); //DFS stack
        bool isDuyetHet(); //Check xem DFS/BFS co duyet het cac phan tu khong
        bool stronglyConnective();
        void duyetTru();
        void duyetCau();
};

void doThi::khoiTao(){
    for(int i = 1;i<=n;i++){
        chuaxet[i] = true;
    }
}

void doThi::Reset(){
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
        cout<<"Ma tran ke: "<<endl;
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

void doThi::DFS(int u){
    stack<int> nganxep;
    nganxep.push(u);
    cout<<u<<" ";
    chuaxet[u] = false;
    while(!nganxep.empty()){
        int u = nganxep.top();
        nganxep.pop();
        for(int t = 1;t<=n;t++){
            if(chuaxet[t] && A[u][t]){
                nganxep.push(u);
                nganxep.push(t);
                cout<<t<<" ";
                chuaxet[t]=false;
                break;
            }
        }
    }
    cout<<endl;
}

//ham nay xac dinh xem DFS(u) hoac BFS(u) co duyet het duoc cac dinh ko?
// tra lai gia tri true neu DFS(u)=V hoac BFS(u)=V <=> chuaxet[1..n]=false
bool doThi::isDuyetHet(){
    for(int i = 1;i<=n;i++){
        if(chuaxet[i]) return false;
    }
    return true;
}

//Xet xem do thi co lien thong manh hay khong ( kiem tra DFS(BFS) 
//voi moi dinh u thuoc do thi)
bool doThi::stronglyConnective(){
    for(int u = 1;u<=n;u++){
        cout<<"Duyet DFS tu dinh "<<u<<": "<<endl;
        DFS(u);
        if(!isDuyetHet()){
            cout<<"Do thi khong lien thong manh"<<endl;
            return false;
        }
        Reset();
    }
    cout<<"Do thi lien thong manh"<<endl;
    return true;
}

void doThi::duyetTru(){
    Reset();
    for(int u = 1;u<=n;u++){
        chuaxet[u] = false;
        if(u==1){
            cout<<"Duyet DFS tu dinh 2: "<<endl;
            DFS(2);
        }
        else{
            cout<<"Duyet DFS tu dinh 1: "<<endl;
            DFS(1);
        }
        if(!isDuyetHet()){
            cout<<"Dinh "<<u<<" la dinh tru."<<endl;
        }
        // else cout<<"Dinh "<<u<<" khong la dinh tru."<<endl;
        Reset();
    }
}

void doThi::duyetCau(){
    Reset();
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(A[i][j]){
                A[i][j] = 0;
                A[j][i] = 0;
                cout<<"Duyet DFS tai dinh 1:"<<endl;
                DFS(1);
                if(!isDuyetHet()){
                    cout<<"Canh ("<<i<<", "<<j<<" ) la canh cau"<<endl;
                }
                A[i][j] = 1;
                A[j][i] = 1;
                Reset();
            }
           
        }
    }
}

int main(){
    doThi G;
    if(G.docDuLieu("3_7_DinhTru.inp")){
        G.khoiTao();
        G.duyetCau();
    }
    return 0;
}