#include "view.h"
#include <iostream>
#include <string>


using namespace std;

string View::show_menu() {
  string menu = R"(
=================================
CSE1325 Library Management System
=================================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Patrons
=======
(5) Add patron
(6) List all patrons

Utility
-------
(9) Help
(0) Exit

)";

  return menu;
}

string View::list_publications() {
string pub_list = R"(
----------------------------
Library Publications List
----------------------------
)";
for (int i=0; i<library.number_of_publications(); ++i)
  {
    pub_list += std::to_string(i) + ") " + library.publication_to_string(i) + '\n';
  }
  return pub_list;
}

string View::list_age(){
string age_list = R"(
-------------------------
Age Category
-------------------------
)";
for (int i = 0; i < Age::num_ages; ++i)
 {
    age_list += "  " + std::to_string(i) + ") " + Age(i).to_string() + '\n';
 }
 return age_list;

}

string View::list_genre(){
string gen_list = R"(
--------------------------
Genre Category
--------------------------
)";
for (int i = 0; i < Genre::num_genres; ++i)
 {
    gen_list += "  " + std::to_string(i) + ") " + Genre(i).to_string() + '\n';
 }
 return gen_list;
}

string View::list_media(){
string media_list = R"(
--------------------------
Media Category
--------------------------
)";
for (int i = 0; i < Media::num_media; ++i)
 {
    media_list += "  " + std::to_string(i) + ") " + Media(i).to_string() + '\n';
 }
 return media_list;
}


string View::list_patron() {
  string patron_list = R"(
-----------------------
List of Beloved Patrons
-----------------------
)";
  for (int i=0; i<library.number_of_patrons(); ++i) {
    patron_list += std::to_string(i) + ") " + library.patron_to_string(i) + '\n';
  }
  return patron_list;
}

string View::help() {
  string helptext = R"(
                 Welcome to Simple Library Management system
                 Here, You can Add Publications
                 Check In
                 Check Out
                 Add and List Patrons
                 This all at the access of your fingertips. Just Select the Option
                 Press 99 to Pre-fill Publications
                 Images are under GNU LPGL License
  )";
  return helptext;
}


