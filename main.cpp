#include <iostream>
#include <queue>

using namespace std;


// Horse moviments
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};


class mNode {
private:
    int ind1, ind2, cost;

public:
    mNode();
    mNode(int, int, int);
    int getInd1();
    int getInd2();
    int getCost();
};

mNode::mNode(int ind1, int ind2, int cost) {
    this->ind1 = ind1;
    this->ind2 = ind2;
    this->cost = cost;
}

int mNode::getInd1() {
    return this->ind1;
}

int mNode::getInd2() {
    return this->ind2;
}

int mNode::getCost() {
    return this->cost;
}

int DFS(int a, int b, int m, int n) {
    queue<mNode> Q;

    mNode *temp = new mNode(a, b, 0);
    Q.push(*temp);

//    delete temp;

    while (!Q.empty()) {
        mNode aux = Q.front();
        Q.pop();

        if(aux.getInd1() == m && aux.getInd2() == n) return aux.getCost();

        for (int i = 0; i < 8; i++) {
            int I = aux.getInd1() + dx[i];
            int J = aux.getInd2() + dy[i];

            if(I>=1 && J>=1 && I<=8 && J<=8) {
                mNode *temp2 = new mNode(I,J, aux.getCost() + 1);
                Q.push(*temp2);
//                delete temp2;
            }
        }
    }
}

int main() {
    std::string s1, s2;
    int x1, y1, x2, y2;

    while (cin >> s1 >> s2) {
        x1=s1[0]-'a'+1;
        y1=s1[1]-'0';
        x2=s2[0]-'a'+1;
        y2=s2[1]-'0';

        cout << "To get from " << s1 << " to " << s2 ;
        cout << " takes " << DFS(x1,y1,x2,y2) << " knight moves." << endl;
    }
    return 0;
}