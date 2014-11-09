/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "DirectoryModel.h"
DirectoryModel::DirectoryModel(GFile *dir) {
	this->dir = dir;
}

DirectoryModel::~DirectoryModel() {
}

/**
 * The method for listing the children of the directory
 *
 * This will enumerate all the children of the directory and pass
 * back a vector list of string names
 *
 * @param type The GFileType of the files to list
 * @return vector<string> of the files found from the enumeration
 */
vector<string> DirectoryModel::ofType(GFileType type) {
	GFileInfo *gfi = NULL;
	GError *error = NULL;
	GFileEnumerator *info = g_file_enumerate_children(dir, "standard::name,standard::type", G_FILE_QUERY_INFO_NONE, NULL, &error);
	vector<string> list;

	while((gfi = g_file_enumerator_next_file(info, NULL, &error)) != NULL) {
		if(g_file_info_get_file_type(gfi) == type)
			list.push_back(g_file_info_get_name(gfi));
		g_object_unref(gfi);
		gfi = NULL;
	}

	g_file_enumerator_close(info, NULL, NULL);

	g_object_unref(info);
	g_object_unref(dir);
	return list;
}
