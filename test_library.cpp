#include<iostream>
#include<string>
#include<vector>
#include "library.cpp"
#include<gtkmm.h>
#include "dialogs.h"
using namespace std;

int main(int argc, char *argv[]){
    Gtk::Main kit(argc, argv);
string title, author, copyright, isbn;
string name, number;
int genre, media, age;
Library lib;
cout << "Test Code to check Library " << endl;

/* Few Hard-coded Tests to check Use case #1 */
title = "Harry Potter";
author = "JK Rowling";
copyright = "01/01/1997";
genre = 0;
media = 1;
age = 0;
isbn = "978-3-16-148410-0";
name = "Aaditya";
number = "7772226666";

lib.add_publication(Publication(title, author, copyright, genre, media, age, isbn)); // Adding Values
Dialogs::message(lib.publication_to_string(0), "Test Output");
}

