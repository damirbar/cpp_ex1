/*
 * main.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: damir
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Worker {
	string _name;
	long _id;
	double _salary;

public:
	Worker(string name, long id, double salary)
	: _name(name), _id(id), _salary(salary){}
	//TODO
//	Worker(const Worker &other) {
//		if (*this != other) {
//			_name = other._name;
//			_id = other._id;
//			_salary = other._salary;
//		}
//			return this;
//	}
	virtual const string toString() const {
		const string ans = "Name: " + _name + ", ID: " + to_string(_id) + ", Salary: " + to_string(_salary);
		return ans;
	}

	virtual ~Worker(){}
};

class Manager : public Worker {

	vector<Worker> _wv;

public:
	Manager(string name, long id, double salary)
	: Worker(name, id, salary) {}

	//TODO
//	Manager(const Manager &other) {
//
//	}

	//TODO
	bool addWorker(const Worker &w) {
		_wv.push_back(w);
		return true;
	}
	//TODO
//	bool removeWorker(const Worker &w) {
//
//	}

	const string toString() const {
		string ans1 = Worker::toString() + ", Worker list:\n\n";
		int counter = 1;
		for (auto iter : _wv) {
			ans1 += to_string(counter++) + ") ";
			ans1 += iter.toString() + "\n";
		}
//		for (auto iter = _wv.begin(); iter != _wv.end(); ++iter) {
//
//		}
		const string ans = "" + ans1;
		return ans;
	}


};



int main(){

	Worker w1("WorkerA", 1, 1510);
	Worker w2("WorkerB", 2, 1300);
	Worker w3("WorkerC", 3, 1550);
	Worker w4("WorkerD", 4, 1600);
	Worker w5("WorkerE", 5, 1500);

	Manager m1("ManagerA", 2345, 15000);
	m1.addWorker(w1);
	m1.addWorker(w2);
	m1.addWorker(w3);
	m1.addWorker(w4);
	m1.addWorker(w5);

	cout << w1.toString() << '\n' << endl;
	cout << m1.toString() << endl;

	return 0;
}

