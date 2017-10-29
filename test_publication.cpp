#include<iostream>
#include<string>
#include<vector>
#include "Publication.cpp"
#include<gtkmm.h>
#include "dialogs.h"
using namespace std;

int main(int argc, char *argv[]){
Gtk::Main kit(argc, argv);
string title, author, copyright, isbn;
string name, number;
int genre, media, age;
title = "Harry Potter";
author = "JK Rowling";
copyright = "01/01/1997";
genre = 0;
media = 1;
age = 0;
isbn = "978-3-16-148410-0";
name = "Aaditya";
number = "7772226666";
Publication p(title, author, copyright, genre, media, age, isbn);
Dialogs::message(p.to_string(), "Test Output");
Dialogs::message("Test Completed Successfully");
}

