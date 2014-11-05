#ifndef COMMONHANDLER_H
#define COMMONHANDLER_H
/**
 * This is the base class for a handler with respect to the signals system
 *
 * This is used to avoid any circular dependencies with the signal system
 * and it's factories. This is the base class for passing around when
 * generating the bound signals, further up the line
 */
class CommonHandler { };
#endif
