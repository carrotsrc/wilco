/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/

#include "Controller.h"

/*
 * The constructor Nullifies the signalFactory
 *
 * This allows a single instance of a SignalFactory
 * to be injected
 */
Controller::Controller () {
	this->signalFactory = NULL;
}

Controller::~Controller () {
}

/**
 * The view initialiser - probably unused
 *
 * @param view The pointer to the View
 */
void Controller::initView(View *view) {
	
}
