#include <iostream>
#include <list>
using namespace std;

// 일렬 주차장 (선형 주차장) --> list 자료형으로 구현
// 해당 번호로 주차된 차가 없을 때(들어온 적이 없을 떄), 음수 값(나가는 차)이 있으면 그냥 무시한다.
// 주차된 차가 있을 때, 그 차가 나가면은 (음수 값)
// 진짜로 해당 양수 값을 가지는 리스트 요소를 삭제하는 게 아니라, 그 리스트 요소의 값을 0으로 바꾼다.
// 리스트 요소가 0값을 가진다 == 이전에 차가 주차되었다 나간 것

int Car_space = 0;	// 주차장 공간(면적) -> 2배씩 늘어날 수 있음
int Parked_Car = 0;	// 주차장에 남아 있는 자동차 수

list<int> lst;

void Parking(int CarNum) {
	// 양숫값 : 차가 들어옴
	if (CarNum > 0) {
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter == 0) {	// 주차되었다 나간 자리라면 == 0
				*iter = CarNum;	// 맨 뒤가 아닌, 빈 공간에 주차한다.
				Parked_Car++;
				return;
			}
		}
		// list가 비었을 때  or 빈 공간 없이 차례대로 주차가 잘 되었을 때
		lst.push_back(CarNum);
		Parked_Car++;

	} // 음숫값 : 차가 나감
	else {
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter == -1 * CarNum) {	// 주차되었다 나간 자리라면 == 0
				*iter = 0;
				Parked_Car--;
			}
		}
	}
	if (Car_space == Parked_Car)
		Car_space = Car_space * 2;
}


void Print() {
	if (Car_space / 3 >= Parked_Car) {	// 주차된 차 수 <= 주차장 공간의 1/3
		int slot = 1;
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter != 0) {	// 주차되었다 나간 자리라면 == 0
				cout << slot << " " << *iter << "\n";
				slot++;
			}
		}
	}
	else {
		int slot = 1;
		for (list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter != 0) {	// 주차되었다 나간 자리라면 == 0
				cout << slot << " " << *iter << "\n";
			}
			slot++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	Car_space = n;

	while (k--) {
		int Cnum;
		cin >> Cnum;
		Parking(Cnum);
	}

	Print();

	return 0;
}
