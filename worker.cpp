/*
 * worker.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: damir
 */


#include "worker.hpp"

const std::string Worker::toString() const {
	const std::string ans = "Name: " + _name + ", ID: " + to_string(_id) + ", Salary: " + to_string(_salary);
	return ans;
}


