#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int kadane(int numbers[], int s){
    int parc, ans;
    parc = ans = numbers[0];
    for(int i=1; i<s; i++){
        parc = max(numbers[i], parc + numbers[i]);
        ans = max(parc, ans);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //int arr[] = { };
    int arr[] = {-1, 1, 1, 1, -1};
    cout << kadane(arr, 9) << endl;

    return 0;
}
