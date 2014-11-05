/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "WindowView.h"

/**
 * The constructor handles the initialisation of a window with a specified caption title
 *
 * The constructor sets up the window and adds the grid container, it also sets up
 * the gkt signal for destroying the window on close
 *
 * @param title The string title of the window
 */
WindowView::WindowView(string title) {
	this->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(this->window), 1200, 600);
	g_signal_connect_swapped(G_OBJECT(this->window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	this->windowTitle = title;

	this->grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(this->window), grid);

}

WindowView::~WindowView() {
}

/*
 * The method for generating the window widget and setting the title
 *
 * Even though this returns a GtkWidget, it will always return NULL
 * because this is the central View of the application
 *
 * @return NULL
 */
GtkWidget *WindowView::generate() {

	gtk_widget_show_all(this->window);
	gtk_window_set_title(GTK_WINDOW(this->window), (const gchar*)this->windowTitle.c_str());

	return NULL;
}

/*
 * This method switches current View that is in focus
 *
 * This will remove all the old widgets from the container
 * and re-apply the widgets from the new view
 *
 * @param view The pointer to the View object to set in focus
 */
void WindowView::setFocus(View *view) {
	this->focus = view;
	GList *children, *iter;
	children = gtk_container_get_children(GTK_CONTAINER(this->grid));
	int i = 0;
	for(iter = children; iter != NULL; iter = iter->next)
		gtk_container_remove(GTK_CONTAINER(this->grid), GTK_WIDGET(iter->data));

	g_list_free(children);
	gtk_grid_attach(GTK_GRID(this->grid), view->generate(), 0,0,1,1);
}

/**
 * The method that is called when the Window needs to be reshown
 *
 * This is usually called after a new View has been set in focus
 */
void WindowView::refresh() {
	gtk_widget_show_all(this->grid);
}
