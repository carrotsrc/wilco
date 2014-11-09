#include "domain/Wilco.h"
#include "common.h"
#include "system/factories/DirectoryModelFactory.h"
void Wilco::wireFactories() {
	this->megaFactory->registerFactory<DirectoryModel, DirectoryModelFactory>();
}
