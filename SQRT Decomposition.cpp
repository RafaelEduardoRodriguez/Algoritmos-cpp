/*
Estructura: sqrt-decomposition
Complejidad: -> Construcción O(n)
             -> Consultas: 3*sqrt(n) -> aprox: O(sqrt(n))
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> buckets;

void preprocessing(vector<int> arr, int len) {
  buckets.assign(len, 0);
  for (int i = 0; i < (int)arr.size(); i++)
    buckets[i / len] += arr[i];
}

int query(vector<int> arr, int l, int r, int len) {
  int b_l = l / len, b_r = r / len, sum = 0;
  if (b_l == b_r) {
    for (int i = l; i <= r; i++)
      sum += arr[i];
    return sum;
  } else {
    for (int i = l; i <= len*(b_l + 1) - 1; i++)
      sum += arr[i];
    for (int i = b_l + 1; i <= b_r - 1; i++)
      sum += buckets[i];
    for (int i = len*b_r; i <= r; i++)
      sum += arr[i];
    return sum;
  }
}

int main() {

  vector<int> arr = {1, 2, 3 ,4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int len = (int)sqrt(arr.size() + .0) + 1;
  preprocessing(arr, len);
  // ...][][][()][][...
  cout << query(arr, 5, 5, len) << endl;
  // ([][][]...[][][])
  cout << query(arr, 0, 14, len) << endl;
  // ...][]([]...[)][][...
  cout << query(arr, 0, 4, len) << endl;
  // ...][(][]...[][)][...
  cout << query(arr, 2, 9, len) << endl;
  // ...]([]...[])[][][][...
  cout << query(arr, 0, 3, len) << endl;
  // ...][][(][]...[])[][...
  cout << query(arr, 1, 7, len) << endl;
  cout << query(arr, 2, 13, len) << endl;

  return 0;
}
