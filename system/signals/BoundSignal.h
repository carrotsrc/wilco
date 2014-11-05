#ifndef BOUNDSIGNAL_H
#define BOUNDSIGNAL_H
/** @file */

/**
 * The Contoller layer of the signal
 *
 * This layer is the binding to callback class method
 * for the event that generated the signal. The controller
 * uses this layer to find out which method to call
 *
 * It is a template class, specialised to the derived
 * SignalHandler object and it's method.
 */
template <class Handler> class BoundSignal : public Signal {
	public:
		/** The callback method used by the Controller */
		void(Handler::*callback)(Signal*);

		/**
		 * The destructor Nullifies the callback
		 */
		~BoundSignal() {
			this->callback = NULL;
		}

		/**
		 * The constructor takes a method and CommonHandler
		 *
		 * The callback is function pointer to a class method so uses &Class::method
		 *
		 * @param void(Handler::\*method)(Signal\*) The callback class method (&Class::method)
		 * @param handler The CommonHandle pointer to the handling object
		 */
		BoundSignal(void(Handler::*method)(Signal*), CommonHandler *handler) {
			this->handler = handler;
			this->callback = method;
		}

};

/** Macro for binding a signal in the signalHandler */
#define BIND_SIGNAL(type, method) (this->bindSignal<type>(&type::method, this))
#define CAST_SIGNAL(type, signal) ((BoundSignal<type>*)signal)
#endif

