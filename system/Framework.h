#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "system/factories/MegaFactory.h"

/**
 * The object representing the base framework
 *
 * Derived classes as as the initialiser for the
 * framework
 */
class Framework {

protected:
	virtual void wireFactories() = 0;
	MegaFactory *megaFactory;

public:
	Framework() {
		this->megaFactory =  new MegaFactory();
	}

	MegaFactory *getMegaFactory() {
		return this->megaFactory;
	}
};
#endif
