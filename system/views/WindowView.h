/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef WINDOWVIEW_H
#define WINDOWVIEW_H
#include "common.h"
#include "glib_common.h"
#include "system/View.h"
/**
 * A framework view for handling the window
 *
 * This view handles the displaying of the window
 * with the current View placed in the container
 *
 * When the View changes, the window changes it's 
 * focus to the new View.
 */
class WindowView : public View {
	private:
		GtkWidget *window; ///< The main Window widget used by the system
		string windowTitle; ///< The title of the window

		View *focus; ///< The current View in focus

		GtkWidget *grid; ///< The main GtkGrid widget used as the View container

	public:
		WindowView(string title);
		~WindowView();
		GtkWidget *generate();

		void setFocus(View *view);
		void refresh();

		void setControlModel(ControlModel *) {};
};
#endif
