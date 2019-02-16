/*
    Implementación de un Segment Tree, para solucionar el problema de
    Range Minimum Query (RMQ) (Sin la operación de Update).
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree{
private:
    vi st, A;
    int n;
    int left(int p){ return p << 1; }
    int right(int p){ return (p << 1) + 1;}
    void build(int p, int L, int R){
        if(L == R) st[p] = L;
        else{
            build(left(p), L, (L + R)/2);
            build(right(p), (L + R)/2 + 1, R);

            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j){
        if(L > j || R < i) return -1;
        if(L >= i && R <= j) return st[p];

        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_A){
        A = _A;
        n = (int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int query(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }
};

int main(){
    //Arreglo original
    int arr[] = {23, 44, 14, 95, 35, 37, 72, 9, 87, 63};
    vi A(arr, arr + 10);
    SegmentTree st(A);
    cout << "Printing 'A': [";
    for(int i=0; i<A.size(); i++)cout << " " << A[i];
    cout << " ]" << endl;
    cout << "RMQ(0, 0) = " << st.query(0, 0) << endl;
    cout << "RMQ(0, 9) = " << st.query(0, 9) << endl;
    cout << "RMQ(0, 3) = " << st.query(0, 3) << endl;
    cout << "RMQ(6, 9) = " << st.query(6, 9) << endl;
    cout << "RMQ(3, 7) = " << st.query(3, 7) << endl;

    return 0;
}
