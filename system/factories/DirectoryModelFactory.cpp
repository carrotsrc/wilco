#include "DirectoryModelFactory.h"

Buildable *DirectoryModelFactory::create(BInit params) {
	GFile *dir = g_file_new_for_path(((DirectoryModelInit*)&params)->path);
	return new DirectoryModel(dir);
}
