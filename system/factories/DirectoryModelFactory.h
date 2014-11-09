#ifndef DIRECTORYMODELFACTORY
#define DIRECTORYMODELFACTORY
#include "system/interfaces/IFactory.h"
#include "system/models/DirectoryModel.h"

class DirectoryModelFactory : public IFactory {
public:
	Buildable *create(BInit params);
};
#endif
