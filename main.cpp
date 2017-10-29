#include "controller.h"
#include "library.h"
#include<gtkmm.h>
#include "main_window.h"
#include "dialogs.h"
#include "view.h"

int main(int argc, char* argv[]) {
 // Gtk::Main kit(argc, argv);
  //Library library;
  //Controller controller(library);
  //controller.cli();

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.cse1325.library");
	
	Main_window start;
	
	start.set_title("Library Management System");

	return app->run(start);	
}
