/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef SIGNALFACTORY_H
#define SIGNALFACTORY_H

#include "system/signals/Signal.h"
#include "system/signals/SignalBank.h"
#include "system/signals/CommonHandler.h"
#include "system/signals/BoundSignal.h"

/**
 * The factory for generating a correctly bound signal.
 *
 * This handles generating BoundSignal instances, but casts them to Signal
 * for being sent through the routing system.
 *
 * It also handles the central SignalBank and registering Signal instances with
 * the bank, as well as destroying the bank when the object is freed
 */
class SignalFactory {
	private:
		SignalBank *signalBank; ///< The interally handled SignalBank instance
	public:
		SignalFactory();
		~SignalFactory();
		
		/**
		 * A template method for creating BoundSignal objects
		 *
		 * This method is used to create and register BoundSignal objects
		 * which are cast down to Signal objects for routing.
		 *
		 * @param void(Handler::*method)(Signal*) A class method function pointer to act as the callback (&Class::method)
		 * @param handler The pointer to the SignalHandler cast down to a CommonHandler type
		 * @return A pointer to a BoundSignal that is cast down to a Signal instance
		 */
		template<class Handler>
		Signal *create(void(Handler::*method)(Signal*), CommonHandler *handler) {
				BoundSignal<Handler> *signal = new BoundSignal<Handler>(method, handler);
				this->signalBank->reg((Signal*) signal);
				return (Signal*)signal;
		}
};
#endif
