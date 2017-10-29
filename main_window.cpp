#include "main_window.h"
#include <gtkmm.h>

Library library;
Controller controller(library);
Main_window::~Main_window(){}
Main_window::Main_window(){
	set_default_size(400,200);
	
	

	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);
	
	//menu bar at the top
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar,Gtk::PACK_SHRINK,0);
	
	//file dropdown menu
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File",true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//append quit to the file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

	//publication dropdown menu
	Gtk::MenuItem *menuitem_pub = Gtk::manage(new Gtk::MenuItem("_Publication",true));
	menubar->append(*menuitem_pub);
	Gtk::Menu *pub_menu = Gtk::manage(new Gtk::Menu());
	menuitem_pub->set_submenu(*pub_menu);
	
	//append list to publication menu
	Gtk::MenuItem *list = Gtk::manage(new Gtk::MenuItem("_List",true));
	list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
	pub_menu->append(*list);

	//append add to publication menu
	Gtk::MenuItem *add = Gtk::manage(new Gtk::MenuItem("_Add",true));
	add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
	pub_menu->append(*add);	

	//append checkout to publication menu
	Gtk::MenuItem *checkout = Gtk::manage(new Gtk::MenuItem("_Check Out",true));
	checkout->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_checkout_click));
	pub_menu->append(*checkout);

	//append check in to publication menu
	Gtk::MenuItem *checkin = Gtk::manage(new Gtk::MenuItem("_Check In",true));
	checkin->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_checkin_click));
	pub_menu->append(*checkin);

	//patron dropdown menu
	Gtk::MenuItem *menuitem_pat = Gtk::manage(new Gtk::MenuItem("_Patron",true));
	menubar->append(*menuitem_pat);
	Gtk::Menu *pat_menu = Gtk::manage(new Gtk::Menu());
	menuitem_pat->set_submenu(*pat_menu);

	//append add patron in to patron menu
	Gtk::MenuItem *addpatron = Gtk::manage(new Gtk::MenuItem("_Add Patron",true));
	addpatron->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_addpatron_click));
	pat_menu->append(*addpatron);

	//append list patron in to patron menu
	Gtk::MenuItem *listpatron = Gtk::manage(new Gtk::MenuItem("_List Patron",true));
	listpatron->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_listpatron_click));
	pat_menu->append(*listpatron);

	//Help dropdown menu
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help",true));
	menubar->append(*menuitem_help);
	Gtk::Menu *help_menu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*help_menu);

	//append about to help menu
	Gtk::MenuItem *about = Gtk::manage(new Gtk::MenuItem("_About",true));
	about->signal_activate().connect(sigc::mem_fun(*this,&Main_window::on_about_click));
	help_menu->append(*about);

	//Create Toolbar
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    Gtk::Image *button_add_image = Gtk::manage(new Gtk::Image("stock_add_24.png"));
    Gtk::ToolButton *button_lms_add = Gtk::manage(new Gtk::ToolButton(*button_add_image));
    button_lms_add->set_tooltip_markup("Add Publications");
    button_lms_add->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
    toolbar->append(*button_lms_add);

    Gtk::Image *button_list_image = Gtk::manage(new Gtk::Image("stock_list_24.png"));
    Gtk::ToolButton *button_lms_list = Gtk::manage(new Gtk::ToolButton(*button_list_image));
    button_lms_list->set_tooltip_markup("List Publications");
    button_lms_list->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_list_click));
    toolbar->append(*button_lms_list);

    Gtk::Image *button_list_checkin = Gtk::manage(new Gtk::Image("stock_checkin_24.png"));
    Gtk::ToolButton *button_lms_checkin = Gtk::manage(new Gtk::ToolButton(*button_list_checkin));
    button_lms_checkin->set_tooltip_markup("Check In");
    button_lms_checkin->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkin_click));
    toolbar->append(*button_lms_checkin);

    Gtk::Image *button_list_checkout = Gtk::manage(new Gtk::Image("stock_checkout_24.png"));
    Gtk::ToolButton *button_lms_checkout = Gtk::manage(new Gtk::ToolButton(*button_list_checkout));
    button_lms_checkout->set_tooltip_markup("Check Out");
    button_lms_checkout->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkout_click));
    toolbar->append(*button_lms_checkout);

  	Gtk::Image *button_list_addp = Gtk::manage(new Gtk::Image("msall.png"));
    Gtk::ToolButton *button_lms_addp = Gtk::manage(new Gtk::ToolButton(*button_list_addp));
    button_lms_addp->set_tooltip_markup("Add Patron");
    button_lms_addp->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_addpatron_click));
    toolbar->append(*button_lms_addp);

  	Gtk::Image *button_list_listp = Gtk::manage(new Gtk::Image("listp.png"));
    Gtk::ToolButton *button_lms_listp = Gtk::manage(new Gtk::ToolButton(*button_list_listp));
    button_lms_listp->set_tooltip_markup("Add Patron");
    button_lms_listp->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_listpatron_click));
    toolbar->append(*button_lms_listp);

    Gtk::Image *button_list_help = Gtk::manage(new Gtk::Image("stock_help_24.png"));
    Gtk::ToolButton *button_lms_help = Gtk::manage(new Gtk::ToolButton(*button_list_help));
    button_lms_help->set_tooltip_markup("Help");
    button_lms_help->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    toolbar->append(*button_lms_help);

    Gtk::Image *button_list_stop = Gtk::manage(new Gtk::Image("stock_stop_24.png"));
    Gtk::ToolButton *button_lms_stop = Gtk::manage(new Gtk::ToolButton(*button_list_stop));
    button_lms_stop->set_tooltip_markup("Quit");
    button_lms_stop->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    toolbar->append(*button_lms_stop);

	vbox->show_all();
	
}

void Main_window::on_about_click(){
	controller.execute_cmd(9);
}
void Main_window::on_checkin_click(){
	controller.execute_cmd(4);
}

void Main_window::on_checkout_click(){
	controller.execute_cmd(3);
}
void Main_window::on_list_click(){
	controller.execute_cmd(2);
}

void Main_window::on_add_click(){
	controller.execute_cmd(1);
}

void Main_window::on_addpatron_click(){
	controller.execute_cmd(5);
}

void Main_window::on_listpatron_click(){
	controller.execute_cmd(6);
}

void Main_window::on_quit_click(){
	hide();
}
