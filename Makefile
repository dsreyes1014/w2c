SHELL = /bin/bash

# This is the compiler.
CC = gcc

# This is the directory in which the program will be installed
PROG_DIR = /opt/Write2chordpro
INSTALL_DIR = $(PROG_DIR)/bin

# Include and Lib directory is in source directory here.
INCLUDE = $(PROG_DIR)/include
LIBDIR = $(PROG_DIR)/lib

# Flags for the gcc compiler.
CFLAGS = -Wall -c -std=c99

# Dependecies to build the program. 
CPPFLAGS = -I/usr/include/atk-1.0 -I/usr/include/cairo -I$(INCLUDE)/gtk-3.0 \
           -I/usr/include/pango-1.0 -I/usr/include/gdk-pixbuf-2.0 \
           -I/usr/lib/glib-2.0/include -I/usr/include/glib-2.0 -I/usr/include/pixman-1 \
           -I/usr/include/freetype2 -I/usr/include/libpng16 

# Library directory to link to
LDFLAGS = -L$(LIBDIR) -L/usr/lib

# Libraries to link
LIBS = -Wl,-rpath=$(PROG_DIR)/lib -lgtk-3 -lgdk-3 -lgobject-2.0 -latk-1.0 -lgio-2.0 -lglib-2.0 -lpangoft2-1.0 \
       -lgdk_pixbuf-2.0 -lpangocairo-1.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig \
       -lgmodule-2.0 -lgthread-2.0 
       
PROGRAM = w2c-gui
OBJECTS = src/main.o src/menu.o src/chords.o src/songs.o src/editor.o src/display.o src/transpose.o
HEADERS = src/menu.h src/chords.h src/songs.h src/editor.h src/display.h src/transpose.h
#GTK+3 = `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
DESKTOP_FILE = w2c.desktop
# Uninstall script will be located in /opt when installed.
UNINSTALL = src/uninstall-w2c.sh

all: checkdir $(PROGRAM)
checkdir:
	if [ -e $(PROG_DIR) ]; \
	then \
		echo "Checking for directory..."; \
		echo "Directory exists. Continuing build."; \
	else \
		echo "Building dependencies..."; \
		cd deps; \
		./deps-download; \
		./install-deps; \
	fi
$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(PROGRAM) 
main.o: src/main.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) src/main.c 
display.o: src/display.c src/editor.h 
	$(CC) $(CFLAGS) $(CPPFLAGS) src/display.c 
menu.o: src/menu.c
	$(CC) $(CFLAGS) $(CPPFLAGS) src/menu.c 
chords.o: src/chords.c src/editor.h
	$(CC) $(CFLAGS) $(CPPFLAGS) src/chords.c 
songs.o: src/songs.c src/editor.h src/display.h
	$(CC) $(CFLAGS) $(CPPFLAGS) src/songs.c 
editor.o: src/editor.c src/chords.h src/transpose.h src/songs.h src/display.h
	$(CC) $(CFLAGS) $(CPPFLAGS) src/editor.c 
transpose.o: src/transpose.c src/editor.h
	$(CC) $(CFLAGS) $(CPPFLAGS) src/transpose.c 

clean: 
	rm -rfv $(OBJECTS) $(PROGRAM) src/*~ *~

install: $(PROG_DIR)
	cp -v $(PROGRAM) $(INSTALL_DIR)/
	cp -v $(UNINSTALL) /opt/
	cp -v $(DESKTOP_FILE) /usr/share/applications/
	cp -Rv themes/Zukitwo $(PROG_DIR)/share/themes/
	mkdir -v /usr/share/w2c
	cp -Rv icons /usr/share/w2c/icons
	echo "export PATH=/opt/Write2chordpro/bin:${PATH}" > w2c.sh
	mv -v w2c.sh /etc/profile.d/

$(PROG_DIR): 
	src/prog-dir.sh # program directory script to make sure directory exists before install.
	
uninstall: check
	/opt/$(UNINSTALL)
	rm -v /opt/$(UNINSTALL) 

check:
	ls /opt/$(UNINSTALL)
