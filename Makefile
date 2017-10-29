# Makefile for Library Management System
CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o controller.o view.o library.o publication.o patron.o dialogs.o main_window.o dialogs.o
	$(CXX) $(CXXFLAGS) -fPIC -o lms main.o controller.o dialogs.o view.o library.o publication.o patron.o main_window.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp controller.h library.h dialogs.h main_window.h
	$(CXX) $(CXXFLAGS) -fPIC -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	
main_window.o: main_window.cpp main_window.h
	$(CXX) $(CXXFLAGS) -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

controller.o: controller.cpp controller.h library.h view.h publication.h patron.h genre.h media.h age.h dialogs.h
	$(CXX) $(CXXFLAGS) -fPIC -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

library.o: library.cpp library.h patron.h publication.h
	$(CXX) $(CXXFLAGS) -fPIC -c library.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

test_publication.o: test_publication.cpp
	g++ --std=c++11 -fPIC -c test_publication.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

test_pub: test_publication.o dialogs.o
	g++ --std=c++11 test_publication.o dialogs.o -o test_pub `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./test_pub

test_library.o: test_library.cpp
	g++ --std=c++11 -fPIC -c test_library.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

test_lib: test_library.o dialogs.o
	g++ --std=c++11 test_library.o dialogs.o -o test_lib `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./test_pub

publication.o: publication.cpp publication.h patron.h media.h age.h genre.h 
	$(CXX) $(CXXFLAGS) -fPIC -c publication.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

test_patron: test_patron.o patron.o patron.h
	$(CXX) $(CXXFLAGS) -o test_patron test_patron.o patron.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

patron.o: patron.cpp patron.h 
	$(CXX) $(CXXFLAGS) -fPIC -c -w patron.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

view_gui.o: view_gui.cpp view_gui.h dialogs.h 
	$(CXX) $(CXXFLAGS) -c -w view_gui.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

view.o: view.cpp view.h dialogs.h 
	$(CXX) $(CXXFLAGS) -fPIC -c -w view.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`	
	
dialogs.o: dialogs.cpp *.h
	g++ --std=c++11 -fPIC -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean:
	-rm -f *.o test_age test_genre test_media test_publication test_patron test_library test_view test_view_actual.txt
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo
