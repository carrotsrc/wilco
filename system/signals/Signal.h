/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef SIGNAL_H
#define SIGNAL_H
#include "common.h"
#include "glib_common.h"
/**
 * The routing layer of the signal
 * 
 * This represents the layer of the signal that is understood by
 * the routing system; it explains where the signal is meant to
 * be going and what widget generated the signal
 */
class Signal {
	public:
		/** The pointer to a SignalHandler object cast to a void pinter */
		void *handler;

		/** The widget that generated the signal */
		GtkWidget *widget;

		virtual ~Signal() {
			this->handler = NULL;
		}
};

#endif
