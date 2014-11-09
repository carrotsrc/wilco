#include "DirectoryModelFactory.h"

void *DirectoryModelFactory::create() {
	cout << "creating new DirectoryModel" << endl;
	return (void*) new DirectoryModel("/home/charlie");
}
