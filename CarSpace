#include <iostream>
#include <list>
using namespace std;

list<int> lst;

int Car_count = 0;
int Car_space = 0;

void Parking(int Car) {
	if (Car > 0) {

		if (lst.empty()) {
			lst.push_back(Car);
			Car_count++;
			return;
		}

		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter == 0) {
				*iter = Car;
				Car_count++;
				return;
			}
		}
		lst.push_back(Car);
		Car_count++;
	}

	else {
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter == -1 * Car) {
				*iter = 0;
				Car_count--;
			}
		}
	}
	if (Car_count == Car_space)
		Car_space *= 2;
}


int main() {
	int n, k;
	cin >> n >> k;

	Car_space = n;


	while (k--) {
		int car;
		cin >> car;

		Parking(car);
	}


	if (Car_space / 3 >= Car_count) {

		int i = 1;
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter != 0) {
				cout << i << ' ' << *iter << "\n";
				i++;
			}
		}
	}
	else {
		int slot_num = 1;

		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter != 0) {
				cout << slot_num << " " << *iter << "\n";
			}
			slot_num++;
		}
	}



	return 0;
}
