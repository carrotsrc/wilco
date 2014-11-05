#ifndef CONTROLLERUNIT_H
#define CONTROLLERUNIT_H

#include "system/Controller.h"
#include "system/controllers/ToolController.h"
#include "system/models/ControlModel.h"

/**
 * A base class for any controllers that can be placed onto the contextStack
 *
 * Derived classes are self contained units that represent some function of the
 * system. A UnitController is placed onto the ToolController context stack
 * and is used as the current state of the application
 */
class UnitController : public Controller {
	private:
		ToolController *parent; ///< A pointer to the ToolController that is handling this Controller

	protected:
		ControlModel *ctlModel; ///< A ControlModel for data binding widget - a UnitController will need one of thes

		UnitController();
		virtual ~UnitController();


		void pushContext(Controller*);

	public:
		void setParentController(ToolController *parent);
};
#endif
