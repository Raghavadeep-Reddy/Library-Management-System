#include "controller.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include "dialogs.h"
#include<gtkmm.h>
#include <iostream>
#include <string>

using namespace std;

void Controller::cli() {
  string title = "Main Menu";
  int choice = -1;
  string text;
  while (choice != 0) {
        text = Dialogs::input(view.show_menu(), title);
        choice = atoi(text.c_str());
        execute_cmd(choice);
  }
}

int Controller::get_int(string prompt, int max_int) {
  int result;
  string result1;
  while(true) {
    result1 = Dialogs::input(prompt, "Lists");
    result = atoi(result1.c_str());
    if (0 <= result && result <= max_int) break;
    cout << "Please enter an integer between 0 and " << max_int << endl;
  }
  return result;
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;

	title = Dialogs::input("Title ?", "Input");

    author = Dialogs::input("Author ?", "Input");

    copyright = Dialogs::input("Copyright Date ?", "Input");

	genre = get_int(view.list_genre(), Genre::num_genres - 1);

    media = get_int(view.list_media(), Media::num_media - 1);

    age = get_int(view.list_age(), Age::num_ages - 1);

    isbn = Dialogs::input("ISBN ?", "Input");

    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    Dialogs::message(view.list_publications(), "Publications");

 } else if (cmd == 3) { // Check out publication
    int pub, pat;
	string pub_sh, pat_sh;

	//pub = get_int(view.list_publications(), library.number_of_publications() - 1);
	
	//pat = get_int(view.list_patrons(), library.number_of_publications() - 1);
	Dialogs::message(view.list_publications(), "Publications");
	pub_sh = Dialogs::input("Publication Number ?", "Input");
	pat_sh = Dialogs::input("Patron Number ?", "Input");
	pub = atoi(pub_sh.c_str());
	pat = atoi(pat_sh.c_str());
    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked out!" << endl;
    }
    
 } else if (cmd == 4) { // Check in publication
    int pub;
	string pub_sh;
    Dialogs::message(view.list_publications(), "Publications");
    pub_sh = Dialogs::input("Publication Number ?", "Input");
	pub = atoi(pub_sh.c_str());

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
      cerr << "ERROR: That publication is already checked in!" << endl;
    }

 } else if (cmd == 5) { // Add patron
    string name, number;


    name = Dialogs::input("Name of Patron ?", "Patron");

    number = Dialogs::input("Number of Patron ?", "Patron");
    library.add_patron(Patron(name, number));
    
 } else if (cmd == 6) { // List all patrons
    Dialogs::message(view.list_patron(), "Patrons");

 } else if (cmd == 9) { // Help
   Dialogs::message(view.help(), "Help");
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}

