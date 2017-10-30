/*
 * ceo.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: damir
 */


#include "ceo.hpp"


bool CEO::addManager(const Manager &m) {
		managerList.push_back(m);
		return true;
}

bool CEO::removeManager(const Manager &m) {
		for (auto iter = managerList.begin(); iter != managerList.end(); ++iter) {
			if (*iter == m) {
				managerList.erase(iter);
				return true;
			}
		}
		return false;
}


const string CEO::toString() const {
		string ans1 = Worker::toString() + ", Manager list:\n\n";
		for (auto iter : managerList) {
			ans1 += "\t* ";
			ans1 += iter.toString() + "\n";
		}
		const string ans = "" + ans1;
		return ans;
}

