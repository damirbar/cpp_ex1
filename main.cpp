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

protected:
	string _name;
	long _id;
	double _salary;

public:
	Worker(string name, long id, double salary)
	: _name(name), _id(id), _salary(salary){}

	Worker(const Worker &other)
	: _name(other._name), _id(other._id), _salary(other._salary){}

	virtual const string toString() const {
		const string ans = "Name: " + _name + ", ID: " + to_string(_id) + ", Salary: " + to_string(_salary);
		return ans;
	}

	inline bool operator==(const Worker& rhs) {
		return this->_name == rhs._name && this->_id == rhs._id && this->_salary == rhs._salary;
	}

	virtual ~Worker(){}
};




/*               Manager                 */


class Manager : public Worker {

//protected:
//	vector<Worker> workerList;

public:
	vector<Worker> workerList;

	Manager(string name, long id, double salary)
	: Worker(name, id, salary) {}

	Manager(const Manager &other)
	: Worker(other._name, other._id, other._salary) {
		for (auto iter : other.workerList) {
			addWorker(iter);
		}
	}


	bool addWorker(const Worker &w) {
		workerList.push_back(w);
		return true;
	}

	bool removeWorker(const Worker &w) {
		for (auto iter = workerList.begin(); iter != workerList.end(); ++iter) {
			if (*iter == w) {
				workerList.erase(iter);
				return true;
			}
		}
		return false;
	}

	const string toString() const {
		string ans1 = Worker::toString() + ", Worker list:\n\n";
		for (auto iter : workerList) {
			ans1 += "\t\t- ";
			ans1 += iter.toString() + "\n";
		}
		const string ans = "" + ans1;
		return ans;
	}

	inline bool operator==(const Manager& rhs) {
		return this->_name == rhs._name && this->_id == rhs._id && this->_salary == rhs._salary;
	}

	~Manager(){}
};





/*             CEO                 */


class CEO : public Manager {

	vector<Manager> managerList;

public:
	CEO(string name, long id, double salary)
	: Manager(name, id, salary) {}

	CEO(const CEO &other)
	: CEO(other._name, other._id, other._salary){}

	bool addManager(const Manager &m) {
		managerList.push_back(m);
		return true;
	}

	bool removeManager(const Manager &m) {
		for (auto iter = managerList.begin(); iter != managerList.end(); ++iter) {
			if (*iter == m) {
				managerList.erase(iter);
				return true;
			}
		}
		return false;
	}

	const string toString() const {
		string ans1 = Worker::toString() + ", Manager list:\n\n";
		for (auto iter : managerList) {
			ans1 += "\t* ";
			ans1 += iter.toString() + "\n";
		}
		const string ans = "" + ans1;
		return ans;
	}

};



int main(){

	const string breaker = "----------------------------------------------------------------";

	Worker w1("WorkerA", 1, 1510);
	Worker w2("WorkerB", 2, 1300);
	Worker w3("WorkerC", 3, 1550);
	Worker w4("WorkerD", 4, 1600);
	Worker w5("WorkerE", 5, 1500);
	Worker wc(w1);

	Manager m1("ManagerA", 2345, 15000);
	m1.addWorker(w1);
	m1.addWorker(w2);
	m1.addWorker(w3);

	Manager m2("ManagerB", 3456, 15000);
	m2.addWorker(w4);
	m2.addWorker(w5);

	CEO c1("CEO-A", 11346, 30000);
	c1.addManager(m1);
	c1.addManager(m2);

	cout << "Worker w1 toString:" << endl;
	cout << w1.toString() << '\n' << breaker << endl;

	cout << "Worker wc, which is a copy of w1, toString:" << endl;
	cout << wc.toString() << '\n' << breaker << endl;

	cout << "Manager m1 toString:" << endl;
	cout << m1.toString() << breaker << '\n' << endl;

	cout << "Removing Worker w2 from Manager m1 and applying toString:" << '\n' << endl;
	m1.removeWorker(w2);
	cout << m1.toString() << breaker << endl;

	cout << "CEO c1 toString:" << endl;
	cout << c1.toString() << endl;

	return 0;
}

