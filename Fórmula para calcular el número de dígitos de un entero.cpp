#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int k = 123456789;
	cout << "El numero de digitos de " << k << " obtenido por la formula es: " << floor(log10(abs(k))) + 1 << endl;
	cout << "El numero de digitos de " << k << " obtenido de forma iterativa es: ";
	int temp = k;
	int count = 0;
	while(temp!=0){
		count++;
		temp /= 10;
	}
	cout << count << endl;
	
	
	return 0;
}