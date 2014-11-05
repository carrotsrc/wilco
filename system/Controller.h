/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "system/View.h"
#include "system/signals/SignalHandler.h"
#include "system/signals/SignalBank.h"

/**
 * The base class for Controller objects
 *
 * The controllers handle the loading of views,
 * loading the models and injecting the view with
 * the models, it also generates widget controls 
 * for those views and handling any signals from 
 * callbacks
 */
class Controller : public SignalHandler {
	protected:
		void initView(View *view);

	public:
		Controller();
		virtual ~Controller();
		/**
		 * A pure virtual function for initialising the Controller
		 *
		 * This is defined by the derived class
		 */
		virtual void init() = 0;

		/**
		 * A pure virtual function for running the Controller
		 *
		 * This is defined by the derived class
		 */
		virtual void run() = 0;

		/**
		 * A pure virtual function for getting the view
		 *
		 * This will be the method called for getting the view
		 * from the controller
		 */
		virtual View *view() = 0;
};

#endif
