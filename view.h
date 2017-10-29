#ifndef __VIEW_H
#define __VIEW_H 201609
 
#include "library.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include<string.h>

class View {
  public:
    View(Library& lib) : library(lib) { }
    std::string show_menu();
    std::string list_publications();
    std::string list_patron();
    std::string help();
	  std::string list_genre();
	  std::string list_media();
	  std::string list_age();
  private:
    Library& library; 
};
#endif
