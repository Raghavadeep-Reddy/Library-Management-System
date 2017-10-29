#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "controller.h"
#include "library.h"
#include "patron.h"
#include "publication.h"
#include <string>
#include <gtkmm.h>
using namespace std;

class Main_window : public Gtk::Window{
	public:
		Main_window();
		virtual ~Main_window();
		//Controller control(Library library);
	protected:
		void on_quit_click();
		void on_list_click();
		void on_add_click();
		void on_checkout_click();
		void on_checkin_click();
		void on_about_click();
		void on_addpatron_click();
		void on_listpatron_click();
	private:
		//Library lib;
};
#endif
