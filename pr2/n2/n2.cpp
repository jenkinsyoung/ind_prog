#include "circle.h"
#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	circle mas[3];
	float r, x, y;
	for (int i = 0; i < 3; i++) {
		cout << "Введите radius, x_centre, y_centre для окружности № " << i + 1 << " через пробел: " << endl;
		cin >> r >> x >> y;
		mas[i].set_circle(r, x, y);
	}
	float a, b, c;
	cout << "Введите a, b и c для треугольника через пробел: " << endl;
	cin >> a >> b >> c;
	float r2, x2, y2;
	cout << "Введите r, x_cntr и y_cntr для новой окружности: " << endl;
	cin >> r2 >> x2 >> y2;
	
	
	for (int i = 0; i < 3; i++) {
		cout << "Площадь круга №"<<i+1<< " : " << mas[i].square() << endl;
		
		if (mas[i].triangle_around(a, b, c)){
			cout<<"Треугольник МОЖНО описать данной окружностью" << endl;
		} 
		else cout << "Треугольник НЕЛЬЗЯ описать данной окружностью" << endl;
		if (mas[i].triangle_in(a, b, c)) {
			cout << "В треугольник МОЖНО вписать данную окружность" << endl;
		}
		else cout << "В треугольник НЕЛЬЗЯ вписать данную окружность" << endl;
		
		
		if (mas[i].check_circle(r2, x2, y2)) {
			cout << "Окружности пересекаются"<<endl;
		}
		else cout << "Окружности НЕ пересекаются"<<endl;
	}
	return 0;
}