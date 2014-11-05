#ifndef TOOLCONTROLLER_H
#define TOOLCONTROLLER_H
#include "common.h"
#include "system/Controller.h"

/**
 * A framework level Controller that acts as the base for the main application Controller
 *
 * This controller handles the current state of the application by having a context stack
 * and the current context. A context is the current Controller that is active.
 */
class ToolController : public Controller {
	protected:
		vector<Controller*> contextStack; ///< The current stack on controller contexts
		Controller *context; ///< The current controller that is the context
		void switchContext(int);
		void popContext(int);


		virtual void onchangeContext() = 0;

	public:
		ToolController();

		~ToolController();
		void pushContext(Controller *context);

};
#endif
