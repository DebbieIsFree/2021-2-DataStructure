#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


struct OLD {
	int gender;
	int id;
	int order;
};

struct ADULT {
	int gender;
	int id;
	int order;
};


struct Oldcomp {
	bool operator()(OLD& o1, OLD& o2){
		if (o1.gender != o2.gender)
			return o1.gender < o2.gender;
		else
			return o1.order > o2.order;
	}
};


struct Adultcomp {
	bool operator()(ADULT &a1, ADULT &a2) {
		if (a1.gender != a2.gender)
			return a1.gender < a2.gender;
		else
			return a1.order > a2.order;
	}
};



int main() {
	priority_queue<OLD, vector<OLD>, Oldcomp> Old;
	priority_queue<ADULT, vector<ADULT>, Adultcomp> Adult;
	queue<int>Child;

	int Aorder = 0;
	int Oorder = 0;
	int N;	cin >> N;

	for (int i = 0; i < N; i++) {
		int id;		cin >> id;
		int age;	cin >> age;
		char gender;	cin >> gender;

		if (age <= 15) {		
			Child.push(id);
		}
		else if (age <= 60) {	
			++Aorder;
			ADULT ad;

			if (gender == 'F') 
				ad.gender = 10;
			else
				ad.gender = 0;
				
			ad.id = id;
			ad.order = Aorder;
			Adult.push(ad);
		}
		else {		
			++Oorder;
			OLD old;
			if (gender == 'M') 
				old.gender = 10;
			else 
				old.gender = 0;

			old.id = id;
			old.order = Oorder;
			Old.push(old);
		}
	}



	while (!Old.empty()) {
		cout << Old.top().id << endl;
		Old.pop();
	}

	while (!Child.empty()) {
		cout << Child.front() << endl;
		Child.pop();
	}

	while (!Adult.empty()) {
		cout << Adult.top().id << endl;
		Adult.pop();
	}

	return 0;
}
