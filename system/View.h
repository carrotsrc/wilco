#ifndef VIEW_H
#define VIEW_H
#include "glib_common.h"
#include "system/models/ControlModel.h"

/**
 * The base class for Views
 *
 * The views are the visual aspect of the system. They
 * take data models and control models and generate an interface
 * of widgets on a layout. They are used to display the data in
 * the models for the user
 */
class View {
	private:
	
	protected:

	public:
		/**
		 * The method that is called to get the generated layout of the view
		 *
		 * This method is called by whatever is handling the view to get the
		 * GTK layout of widget.
		 *
		 * This method is defined by derived classes to produce the layout
		 *
		 * @return A pointer to the GtkWidget acting as a layout container
		 */
		virtual GtkWidget *generate() { return NULL; }

		/**
		 * The method to set the ControlModel for the view
		 *
		 * The control model holds the data bindings of the widget
		 * which are represented by BoundWidget objects.
		 *
		 * @param ControlModel A pointer to the ControlModel
		 */
		virtual void setControlModel(ControlModel*) = 0;

};
#endif
