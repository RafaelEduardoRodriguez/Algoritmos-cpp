#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree{
private:
    vi st, A;
    int n;
    int left(int p){ return p << 1;}
    int right(int p){ return (p << 1) + 1;}
    void build(int p, int L, int R){
        if(L == R){
             st[p] = A[L];
        }
        else{
            build(left(p), L, (L + R)/2);
            build(right(p), (L + R)/2 + 1, R);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int rsq(int p, int L, int R, int i, int j){
        if(L > j || R < i) return -1;
        if(L >= i && R <= j) return st[p];
        int p1 = rsq(left(p), L, (L + R)/2, i, j);
        int p2 = rsq(right(p), (L + R)/2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return st[p] =  p1 + p2;
    }
public:
    SegmentTree(const vi &_A){
        A = _A;
        n = A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }

    int query(int i, int j){
        return rsq(1, 0, n-1, i, j);
    }
};

int main(){
    /*
        Ingresar los valores del vector y las respectivas consultas
    */
    vi num;
    int k, a, b;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> a;
        num.push_back(a);
    }
    SegmentTree st(num);
    cin >> k;
    while(k--){
        cin >> a >> b;
        cout << st.query(a, b) << endl;
    }

    return 0;
}
