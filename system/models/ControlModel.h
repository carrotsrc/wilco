/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef CONTROLMODEL_H
#define CONTROLMODEL_H

#include "system/Model.h"
#include "system/WidgetBinding.h"

/**
 * The framework Model that is used for keeping track of widget controls and data bindings
 *
 * Because the Controller does not keep track of the widgets it has created, it hands the 
 * management over to it's ControlModel. This also keeps track of data bindings, so when
 * a widget is bound to a bit of arbitrary data, the View can get the associated widget
 * based on the data address.
 */
class ControlModel : public Model {
	vector<WidgetBinding*> bindings; ///< A list of widget data bindings

	public:
		TModel ControlModel(PACK)
		: BModel(Model) { };

		~ControlModel();
		void addBinding(GtkWidget *, void *);
		GtkWidget *getWidget(void *);
};

#endif
