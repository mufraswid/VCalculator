#include <bits/stdc++.h>
using namespace std;

int main(){
	int i;
	double N;
	queue<double> q;

	for (i = 1; i <= 3; i++){
		cout << "Input " << i << ": ";
		cin >> N;
		q.push(N);
	}

	while (!q.empty()){
		N = q.front();
		cout << "Head: "<< N << endl;
		q.pop();
	}

	for (i = i; i <= 10; i++){
		cout << "Input " << i << ": ";
		cin >> N;
		q.push(N);
	}

	for (int j = 0; j < 3; j++){
		N = q.front();
		cout << "Head: "<< N << endl;
		q.pop();
	}

	for (i = i; i <= 15; i++){
		cout << "Input " << i << ": ";
		cin >> N;
		q.push(N);
	}

	while (!q.empty()){
		N = q.front();
		cout << "Head: "<< N << endl;
		q.pop();
	}
	return 0;
}
