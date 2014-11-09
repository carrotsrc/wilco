#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "system/factories/MegaFactory.h"
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
