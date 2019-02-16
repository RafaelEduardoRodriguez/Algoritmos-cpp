#include <bits/stdc++.h>

using namespace std;

void print(vector<double> v) {
  for(int i = 0; i < (int)v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<double> insertion_sort(vector<double> v) {
  vector<double> aux = v;
  for(int i = 1; i < (int)aux.size(); i++) {
    double key = aux[i];
    int j = i - 1;
    while(j >= 0 && key < aux[j]) {
      aux[j + 1] = aux[j];
      j--;
    }
    aux[j + 1] = key;
  }
  return aux;
}

vector<double> bucket_sort(vector<double> v) {
  vector<double> aux;
  vector<double> buckets[10];
  aux.reserve(v.size());
  for(int i = 0; i < (int)v.size(); i++) {
    buckets[(int)floor(10*v[i])].push_back(v[i]);
  }
  int flag = 0;
  for(int i = 0; i < 10; i++) {
    vector<double> temp = buckets[i];
    temp = insertion_sort(temp);
    aux.insert(aux.begin() + flag, temp.begin(), temp.end());
    flag += (int)temp.size();
  }
  return aux;
}

int main() {
  double arr[] = {0.95, 0.71, 0.86, 0.10, 0.10, 0.88, 0.16, 0.00, 0.08, 0.25, 0.53, 0.64, 0.00, 0.93, 0.94, 0.47, 0.02, 0.48, 0.50, 0.81};
  vector<double> data(arr, arr + 20);
  //Generamos una distribución normal
  //default_random_engine generator;
  //normal_distribution<double> distribution(5.0,2.0);
  data = bucket_sort(data);
  print(data);

  return 0;
}
