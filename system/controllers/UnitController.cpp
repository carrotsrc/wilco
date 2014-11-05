#include "UnitController.h"

/**
 * The constructor instantiates a new ControlModel
 */
UnitController::UnitController() {
	this->ctlModel = new ControlModel();
	this->parent = NULL;
}

/**
 * The ControlModel is destroyed when the UnitContoller is destroyed
 */
UnitController::~UnitController() {
	delete this->ctlModel;
}

/**
 * A method for pushing a new Controller onto the context stack
 *
 * This method pushes a new Controller onto the context stack
 * of the ToolController that is handling this instance.
 *
 * This behaviour is outside of the pattern but will remain until
 * another way is built in. The problem is that the derived UnitController
 * will have to know about the types of Controllers that it will push
 * onto the stack but it's the only way for state change at the moment.
 *
 * @param context The Controller instance to push onto the stack
 */
void UnitController::pushContext(Controller *context) {
	this->parent->pushContext(context);
}

/**
 * Set ToolContoller that handles this Controller
 */
void UnitController::setParentController(ToolController *parent) {
	if(this->parent != NULL)
		return;

	this->parent = parent;
}
