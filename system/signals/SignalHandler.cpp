#include "SignalHandler.h"

/** @file **/

/**
 * A method for connecting a signal to a widget event
 *
 * This calls the GTK+ API to connect a signal to the specified event of a widget. This
 * also takes a Signal object that is bound to a class method
 *
 * @param widget The widget to connect the signal to
 * @param name The name of the event
 * @param signal The signal object that has been bound to a method
 */
void SignalHandler::signalCallback(GtkWidget *widget , const gchar *name, Signal *signal) {
	g_signal_connect((gpointer)widget, name, G_CALLBACK(FW_ONCLICK), (gpointer)signal);
}

/**
 * The method used to inject a SignalFactory into the handler
 *
 * This allows the external injection of a factory used correctly
 * generate a BoundSignal
 *
 * @param factory Pointer to the SignalFactory object
 */
void SignalHandler::setSignalFactory(SignalFactory *factory) {
	if(this->signalFactory == NULL)
		this->signalFactory = factory;
}

/**
 * The procedual function for handling the routing of Signals back
 * to a SignalHandler.
 *
 * This is used by the framework as the router and is assigned as
 * the global signal callback for GTK. It also assigns the
 * widget that generated the event to the signal
 *
 * @param widget The pointer to widget that generated the signal
 * @param data The data - most likely a Signal
 */
void signal_callback_onclick(GtkWidget *widget, gpointer data) {
		((Signal*)data)->widget = widget;
		((SignalHandler*) ((Signal*)data)->handler)->handleSignal((Signal*)data);
}
