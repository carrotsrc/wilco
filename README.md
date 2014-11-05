# Wilco
### Basic MVC C++ framework for GTK+

This is the *beginning stages* of a basic MVC framework (loosely speaking) for GTK+ that is being built underneath an application I am working on. It's been very fun and interesting so far. This has no language bindings, it's using the straight API.

This may be useful to someone so I've put it up here.

#### Models

There are two types of model regularly in use:
* Data model
* control model

Data model is used to handle the specific data, while the Control Model handles data bindings for the Widgets. The data bindings is with the data in the Data Model

#### Views

Currently Views are fairly passive; They take the Data Model and Control Model, they use the data addresses from the Data Model to find the Widget that is bound to that data and then places the widget on the layout. The view purely handles the visual layout of the widgets at this time.

There is one special framework defined View that is the WindowView and handles the display of the Window widget and whatever View is in focus.

#### Controllers

There are two sorts of Controller that are currently in use in the system:
* Tool Controllers
* Unit Controllers

A Tool Controller represents the entire application and it's states, it is used as the master controller if you will. Since it is currently designed for a single window with multiple views, the Tool Controller handles which Controller is currently in use as well as the creation of a WindowView. The entire application has a stack of Controllers that represent individual states of the application and the Tool Controller can put other controllers onto the stack or switch between them or remove them

A Unit Controller is the individual state. It is designed to represent one view at a time and one data model at a time. It is Unit Controllers that are pushed onto the Tool Controller stack to show the current context of the application. A Unit Controller can tackle one task or set of tasks of the application.

Controllers act as the handlers for signals from widgets, they use their class methods as the callbacks to the GTK signals. Controllers also handle generating widgets and binding them to data for the view to deal with.


#### License

This is released under the MIT license