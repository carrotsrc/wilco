#include "SignalBank.h"

/**
 * The destructor handles the destruction of registered Signal object
 *
 * If there are any Signal objects, they are safely destroyed here
 */
SignalBank::~SignalBank() {
	int i = 0, sz = this->bank.size();
	for(; i < sz; i++) {
		delete (this->bank.at(i));
	}

	this->bank.clear();
}

/**
 * The method for registering a new instance of a Signal
 *
 * This is usuaully used by the SignalFactory to register
 * a new signal with the bank
 *
 * @param signal The pointer to the signal object to stash
 */
void SignalBank::reg(Signal *signal) {
	this->bank.push_back(signal);
}
