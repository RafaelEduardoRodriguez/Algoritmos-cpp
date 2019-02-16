#include <bits/stdc++.h>
//La función (stringstream) pertenece a la librería sstream

#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//concatenar (con el constructor por defecto)...
	stringstream ss;
	ss << "Soy " << "una " << "cadena " << "partida " << 3.14 << " - " << 5 << " " << 'k';
	string cadena = ss.str();
	cout << cadena << endl;
	ss.clear();//limpiamos lo que hay en ss

	//Tokenizar
	//forma 1, recibiendo la linea por teclado
	int a, b, c;
	string line;
	getline(cin, line);
	ss.str(line);
	ss >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;
	ss.clear();
	//forma 2, pasandole le argumento directamente
	ss.str("Esta cadena 1 2.33 k");
	string s1, s2;
	int n; double m; char d;
	ss >> s1 >> s2 >> n >> m >> d;
	cout << s1 << " " << s2 << " " << n << " " << m << " " << d << endl;
	//forma 3, de una lista de largo indeterminado (del mismo tipo)
	ss.clear();
	cin.ignore();
	getline(cin, line);
	ss.str(line);
	int temp, sum = 0;
	stringstream ss2(line);
	//encontraremos la suma de los numeros de la lista por ejemplo
	while(ss2 >> temp) sum += temp;
	cout << sum << endl;

	return 0;
}
