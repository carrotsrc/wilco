#ifndef MEGAFACTORY_H
#define MEGAFACTORY_H
#include "common.h"

#include <typeinfo>
#include <typeindex>
#include <map>
#include "system/interfaces/IFactory.h"
class MegaFactory : public IFactory {
private:
	map<type_index, IFactory*> factories;

public:
	template <class U>
	U *create() {
		type_index index = typeid(U);

		return (U*)this->factories[index]->create();
	}

	template <class T, class F>
	void registerFactory() {
		type_index ti = typeid(T);
		this->factories.insert(
				pair<type_index, IFactory*>(ti, (IFactory*) new F())
				);
	}
};
#endif
