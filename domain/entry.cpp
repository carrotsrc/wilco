/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "common.h"
#include "glib_common.h"
#include "system/factories/MegaFactory.h"
#include "system/models/DirectoryModel.h"
#include "Wilco.h"

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	Wilco *framework = new Wilco();
	MegaFactory *f = framework->getMegaFactory();
	f->create<DirectoryModel>(DirectoryModelInit{"/home/charlie"});
	//DirectoryModel *model = framework->getMegaFactory()->create<DirectoryModel>(DirectoryModelInit{"/home/charlie"});
	gtk_main();
}
