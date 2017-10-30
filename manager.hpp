/*
 * manager.hpp
 *
 *  Created on: Oct 30, 2017
 *      Author: damir
 */


#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "worker.hpp"


using namespace std;

class Manager : public Worker {

//protected:
//	vector<Worker> workerList;

public:
	vector<Worker> workerList;

	Manager(string name, long id, double salary)
	: Worker(name, id, salary) {}

	Manager(const Manager &other);


	bool addWorker(const Worker &w);

	bool removeWorker(const Worker &w);

	const string toString() const;

	inline bool operator==(const Manager& rhs) {
		return this->_name == rhs._name && this->_id == rhs._id
				&& this->_salary == rhs._salary;
	}

	~Manager(){}
};




#endif /* MANAGER_HPP_ */


