/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "system/models/ControlModel.h"

/**
 * The destructor also destroys all the widgets and data bindings
 *
 * Because the ControlModel is the repository of widgets the Controller
 * has spawned, it is also given the responability of destroying all the
 * bindings, which will in turn destroy the widgets
 */
ControlModel::~ControlModel() {
	int i = 0, sz = this->bindings.size();
	for(; i < sz; i++) {
		delete (this->bindings.at(i));
	}

	this->bindings.clear();
}

/**
 * The method for adding a data binding
 *
 * This method creates a new data binding for a widget
 *
 * @param widget The pointer to the widget for the binding
 * @param data The void pointer to arbitrary data to bind to the widget
 */
void ControlModel::addBinding(GtkWidget *widget, void *data) {
	this->bindings.push_back(new WidgetBinding(widget, data));
}

/**
 * The method for getting a widget based on the data
 *
 * This method will return the widget - if any - that is
 * bound to the address provided for the data
 *
 * @param data The void pointer to the arbitrary data
 * @returns GtkWidget if there is a widget bound to the data; NULL otherwise
 */
GtkWidget *ControlModel::getWidget(void *data) {
	int i = 0, sz = this->bindings.size();
	WidgetBinding *bind = NULL;
	for(; i < sz; i++) {
		bind = this->bindings.at(i);

		if(bind->data == data)
			return bind->widget;
	}

	return NULL;
}
