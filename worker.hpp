#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <string>

class Worker {

protected:
	std::string _name;
	long _id;
	double _salary;

public:
	Worker(std::string name, long id, double salary)
	: _name(name), _id(id), _salary(salary){}

	Worker(const Worker &other)
	: _name(other._name), _id(other._id), _salary(other._salary){}

	virtual const std::string toString() const;

	inline bool operator==(const Worker& rhs) {
		return this->_name == rhs._name && this->_id == rhs._id && this->_salary == rhs._salary;
	}

	virtual ~Worker(){}
};

#endif
