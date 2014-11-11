#ifndef MEGAFACTORY_H
#define MEGAFACTORY_H
#include "common.h"

#include <typeinfo>
#include <typeindex>
#include <map>
#include "system/interfaces/IFactory.h"

/**
 * The go-to object for constructing Buildable in the system
 *
 * This object keeps a list of factories for types of buildables
 * so you can specify a type of derived Buildable and it will construct
 * it using the correct Factory. This way, caller objects don't need
 * to know which factory to use in order to build the object.
 *
 * This object needs 'wiring' up with classes and their factories
 * in the framework initialisation.
 *
 * The factories are stored based on the type_index of the class
 * of object that it is wired to; this is stored in a map with the
 * type_index as the key and the factory downcast to an IFactory as
 * the value
 */
class MegaFactory : public IFactory {
private:
	/** A std::map of objects and factories */
	map<type_index, IFactory*> factories;

public:
	/**
	 * Template function to create the specified object
	 *
	 * This method is called to construct an object of
	 * type U. If there is a factory then it will
	 * return a newly constructed U.
	 *
	 * @param <U> The type of object to construct
	 * @param params The BuilderInit derived structure to pass for initialisation
	 * @return A pointer to new U object
	 * @TODO Error checking
	 */
	template <class U>
	U *create(BuilderInit params) {
		type_index index = typeid(U);
		return (U*)this->factories[index]->create(params);
	}

	/**
	 * Template function to register a factory with a type
	 *
	 * This should be called when wiring up an Object T type
	 * with it's factory F.
	 *
	 * This allows for the specifics of factories to be handled
	 * in one source file without global access to the factory
	 * definitions.
	 *
	 * @param <T> The object type
	 * @param <F> The factory type
	 */
	template <class T, class F>
	void registerFactory() {
		type_index ti = typeid(T);
		this->factories.insert(
				pair<type_index, IFactory*>(ti, (IFactory*) new F())
				);
	}
};
#endif
