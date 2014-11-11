#ifndef IFACTORY_H
#define IFACTORY_H
#include "system/Buildable.h"
#include "common.h"
class IFactory {
public:
	virtual Buildable *create(BuilderInit params) { };
};

#endif
