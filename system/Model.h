/* Copyright 2014, Charlie Fyvie-Gauld
*  Distributed under the MIT License (http://opensource.org/licenses/MIT)
*/
#ifndef MODEL_H
#define MODEL_H
#include "common.h"

/** @file */

/** Macro for defining a template Model constructor */
#define TModel template <typename ... Args>

/** Macro for The variadic argument parameter pack */
#define PACK Args ... args

/** Macro for custructing the parent model */
#define BModel(B) B(args...)

/**
 * The base class for a Model
 *
 * Models are used for different representations in the system. Derived classes
 * will allow the representation of data or controls
 */
class Model {
protected:
public:
	/**
	 * Template static factory method for creating an instance of a Model
	 *
	 * The method uses the template specialisation as the type of Model
	 * to instantiate. It takes a variadic list of arguments which is
	 * expands out to the constructor allowing the caller to inject
	 * the necessary dependencies
	 *
	 * @param <Type> The class of Model to instantiate
	 * @param args The variadic list of arguments
	 * @return A pointer to a Model of type Type
	 */
	template <class Type, typename ... Args>
	static Type *create(PACK) {
		return new Type(args...);
	}
};

#endif
