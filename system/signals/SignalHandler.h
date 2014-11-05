#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H
#include "glib_common.h"
#include "system/signals/Signal.h"
#include "system/factories/SignalFactory.h"

/**
 * The base class to define a router level signal handler.
 *
 * The routing layer can interface with a signal handler as
 * the object to route the signal to.
 */
class SignalHandler : public CommonHandler {
	private:

	protected:
		SignalFactory *signalFactory; ///< The factory used to generate BoundSignals 
		
		/**
		 * An inheritable template method binding a signal to a class method
		 *
		 * Derived SignalHandler objects use this method to bind a signal to one of their class methods,
		 * to act as a callback when an event is triggered. The template class Handler is used
		 * to specialise the Signal to the handler.
		 *
		 * @param void(Handler::\*method)(Signal\*) The specified callack class method
		 * @param handler The pointer to a the SignalHandler object that will act as the destination
		 * @return A pointer to a new Signal object
		 */
		template<class Handler>
		Signal *bindSignal(void(Handler::*method)(Signal*), SignalHandler *handler) {
			return this->signalFactory->create<Handler>(method, (CommonHandler*)handler);
		}

	public:
		/**
		 * A pure virtual function prototype that acts as the interface for the routing layer
		 *
		 * This is the method that is called by the routing layer to pass in the signal.
		 * It should be defined by derived objects in order to call the correct callback
		 * methods. This prototype takes a pointer to a singal
		 */
		virtual void handleSignal(Signal*) = 0;
		void signalCallback(GtkWidget*, const gchar*, Signal*);

		virtual void setSignalFactory(SignalFactory *factory);
};

/**
 * The procedual callback which acts as the signal router
 *
 *
 */
void signal_callback_onclick(GtkWidget *widget, gpointer data);
#define FW_ONCLICK signal_callback_onclick
#endif

