/*
 * ceo.hpp
 *
 *  Created on: Oct 30, 2017
 *      Author: damir
 */

#ifndef CEO_HPP_
#define CEO_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "manager.hpp"


class CEO : public Manager {

	vector<Manager> managerList;

public:
	CEO(string name, long id, double salary)
	: Manager(name, id, salary) {}

	CEO(const CEO &other)
	: CEO(other._name, other._id, other._salary){}

	bool addManager(const Manager &m);

	bool removeManager(const Manager &m);

	const string toString() const;

};



#endif /* CEO_HPP_ */
