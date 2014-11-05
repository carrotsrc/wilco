/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef SIGNALBANK_H
#define SIGNALBANK_H
#include "common.h"
#include "system/signals/Signal.h"
/**
 * The SignalBank holds all the instances of Signal
 *
 * This class is used as a central repository of Signal objects
 * so they can be destroyed correctly on tear-down
 */
class SignalBank {
	private:
		/** The vector of signals registered in the system */
		vector<Signal*> bank;
	
	public:
		~SignalBank();
		void reg(Signal*);
};
#endif
