#include "SignalFactory.h"
#include "system/signals/SignalHandler.h"
#include "system/signals/BoundSignal.h"

/**
 * The constructor handles the creation of a SignalBank
 *
 * The constructor create the central SignalBank instance for 
 * collecting the registered Signals
 */
SignalFactory::SignalFactory() {
	this->signalBank = new SignalBank();
}

/**
 * The destructor handles the destruction of the SignalBank
 *
 * When the SignalFactory is destroyed, the central SignalBank
 * is also destroyed
 */
SignalFactory::~SignalFactory() {
	delete this->signalBank;
}

