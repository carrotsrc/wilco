/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef WIDGETBINDING_H
#define WIDGETBINDING_H
#include "glib_common.h"

/**
 * A data binding class for GTK Widgets
 *
 * This acts as a binding between a widget and some data based
 * on it's address. Really the widget is bound to a specific address
 * which makes the data arbitrary.
 *
 * The widget also has it's reference count increased so the binding object
 * alone will handle the destruction of the widget; the reason being that 
 * widgets are generated by Controllers but not held in the controller, rather
 * they are held in a ControlModel - the Controller has a pointer to it's
 * ControlModel instance, but it does not have a reference to any of it's
 * widgets that it created.
 */
class WidgetBinding {
	public:
		GtkWidget *widget; ///< The widget in the binding
		void *data; ///< The pointer to the data the widget is bound to

		/**
		 * The constructor binds the widget to the data
		 *
		 * The constructor will bind the widget to the data and 
		 * increment the reference count on the widget
		 *
		 * @param widget A pointer to the widget
		 * @param data A void type address to abitrary data
		 */
		WidgetBinding(GtkWidget *widget, void *data) {
			this->widget = widget;
			this->data = data;
			g_object_ref(widget);
		}

		/**
		 * The destructor will unreference the widget
		 * which should allow GTK to destroy it
		 *
		 * This should be the final reference for a widget
		 * allowing the GC to free the memory
		 */
		~WidgetBinding() {
			if(G_IS_OBJECT(this->widget))
				g_object_unref(this->widget);
		}
};
#endif
