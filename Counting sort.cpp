#include <bits/stdc++.h>

using namespace std;

void printing(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

vector<int> counting_sort(vector<int> v, int infR = 0, int supR = 10) {
  vector<int> counting;
  vector<int> sorted;
  counting.assign(supR + 1, 0);
  sorted.assign(v.size(), 0);
  for(int i = 0; i < v.size(); i++) {
    counting[v[i]]++;
  }
  for(int i = infR + 1; i <= supR; i++) {
    counting[i] += counting[i - 1];
  }
  for(int i = 0; i < v.size(); i++) {
    sorted[--counting[v[i]]] = v[i];
  }
  return sorted;
}

int main() {

  //int arr[] = {10, 9, 9, 8, 8, 8, 7, 6, 6, 6, 5, 4, 3, 3, 3, 3, 2, 1, 1, 1};
  int arr[] = {33, 65, 14, 83, 99, 11, 57, 25};

  vector<int> a(arr, arr + 8);
  cout << "Array antes del ordenamiento: ";
  printing(a);
  cout << "Array después de aplicar Counting Sort: ";
  a = counting_sort(a, 10, 99);
  printing(a);
  cout << endl;

  return 0;
}
