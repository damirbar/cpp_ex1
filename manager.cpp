/*
 * manager.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: damir
 */

#include "manager.hpp"

Manager::Manager(const Manager &other) :
		Worker(other._name, other._id, other._salary) {
	for (auto iter : other.workerList) {
		Manager::addWorker(iter);
	}
}

bool Manager::addWorker(const Worker &w) {
	workerList.push_back(w);
	return true;
}

bool Manager::removeWorker(const Worker &w) {
	for (auto iter = workerList.begin(); iter != workerList.end(); ++iter) {
		if (*iter == w) {
			workerList.erase(iter);
			return true;
		}
	}
	return false;
}


const string Manager::toString() const {
	string ans1 = Worker::toString() + ", Worker list:\n\n";
	for (auto iter : workerList) {
		ans1 += "\t\t- ";
		ans1 += iter.Worker::toString() + "\n";
	}
	const string ans = "" + ans1;
	return ans;
}
