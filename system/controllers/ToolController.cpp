/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#include "ToolController.h"
#include "UnitController.h"

/**
 * The constructor generates a new SignalFactory
 *
 * The SignalFactory is the one that is used by the entire application and
 * is injected into the other Controller instances
 */
ToolController::ToolController()
: Controller() {
	this->signalFactory = new SignalFactory();
};

/**
 * All Controller instances and SignalFactory are destroyed
 *
 * When the ToolController is destroyed, all the Controller instances that
 * are on the context stack are sequentially destroyed.
 *
 * The SignalFactory is also destroyed, which in turn destroys all the
 * registered Signal instances in the system.
 */
ToolController::~ToolController() {
	this->context = NULL;

	int sz = this->contextStack.size();
	for(int i = 0; i < sz; i++)
		delete (this->contextStack.at(i));

	this->contextStack.clear();

	delete this->signalFactory;
}

/**
 * The method to push a Controller onto the context stack
 *
 * The method that is called by Controller instances to
 * push a new Controller onto the context stack. This
 * will be a completely fresh instance of Controller, 
 * which has it's SignalFactory injected from the instance
 * held in this object.
 *
 * This method will then call the virtual method onchangeContext
 * which should be defined by the derived class.
 *
 * @param context The pointer to the Controller instance to push onto the context stack
 */
void ToolController::pushContext(Controller *context) {
	this->contextStack.push_back(context);
	context->setSignalFactory(this->signalFactory);
	((UnitController*)context)->setParentController(this);
	this->context = context;
	this->onchangeContext();
}

/**
 * The method for switching focus to another context already on the stack
 *
 * If the active context needs to switch to a Controller already on the stack
 * then the derived class can use this method to do so.
 *
 * @param id The int index ID of the context on the stack
 */
void ToolController::switchContext(int id) {
	if(id >= this->contextStack.size());
		return;

	this->context = this->contextStack.at(id);
	this->onchangeContext();
}

/**
 * This method pops the stack down to the index specified
 *
 * If the derived class needs to pop 1 or more context controllers
 * off the stack, it can use this method
 *
 * @param id The int index ID of the context to pop down to on the stack
 */
void ToolController::popContext(int id) {
	int sz = 0;
	if(id >= (sz = this->contextStack.size()-1));
		return;

	sz -= id;
	while(sz-- > 0)
		this->contextStack.pop_back();

	this->context = this->contextStack.back();
	this->onchangeContext();
}
