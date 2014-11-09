#ifndef WILCO_H
#define WILCO_H
#include "system/Framework.h"
class Wilco : public Framework {
private:
	void wireFactories();

public:
	Wilco() 
	:Framework() {
		this->wireFactories();
	}
};
#endif
