# This the compiler.
CC = gcc

# This is the directory in which the program will be installed
PROG_DIR = /opt/Write2chordpro
INSTALL_DIR = $(PROG_DIR)/bin

# Include and Lib directory is in source directory here.
INCLUDE = $(PWD)/src/include
LIBDIR = $(PWD)/src/lib

# Flags for the gcc compiler.
CFLAGS = -Wall -c -std=c99

# Dependecies to build the program. 
CPPFLAGS = -I$(INCLUDE)/atk-1.0 -I$(INCLUDE)/cairo -I$(INCLUDE)/gtk-3.0 \
           -I$(INCLUDE)/pango-1.0 -I$(INCLUDE)/gdk-pixbuf-2.0 \
           -I$(LIBDIR)/glib-2.0/include -I$(INCLUDE)/glib-2.0 -I$(INCLUDE)/pixman-1 \
           -I$(INCLUDE)/freetype2 -I$(INCLUDE)/libpng16 

# Library directory to link to
LDFLAGS = -L$(LIBDIR)

# Libraries to link
LIBS = $(LIBDIR)/libgtk-3.so -lgdk-3 -lgobject-2.0 -latk-1.0 -lgio-2.0 -lglib-2.0 -lpangoft2-1.0 \
       -lgdk_pixbuf-2.0 -lpangocairo-1.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig \
       -lgmodule-2.0 -lgthread-2.0 
       
PROGRAM = w2c-gui
OBJECTS = src/main.o src/menu.o src/chords.o src/songs.o src/editor.o src/display.o src/transpose.o
HEADERS = src/menu.h src/chords.h src/songs.h src/editor.h src/display.h src/transpose.h
GTK+3 = `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`
DESKTOP_FILE = w2c.desktop
# Uninstall script will be located in /opt when installed.
UNINSTALL = src/uninstallW2C


all: $(PROGRAM)
$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)
main.o: src/main.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/main.c 
display.o: src/display.c src/editor.h 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/display.c 
menu.o: src/menu.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/menu.c 
chords.o: src/chords.c src/editor.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/chords.c 
songs.o: src/songs.c src/editor.h src/display.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/songs.c 
editor.o: src/editor.c src/chords.h src/transpose.h src/songs.h src/display.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/editor.c 
transpose.o: src/transpose.c src/editor.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBS) src/transpose.c 

clean: 
	rm -rfv $(OBJECTS) $(PROGRAM) src/*~

install: $(PROG_DIR)
	cp -Rv src/bin $(PROG_DIR)/
	cp -Rv src/lib $(PROG_DIR)/
	cp -Rv src/etc $(PROG_DIR)/
	cp -v $(PROGRAM) $(INSTALL_DIR)/
	cp -v $(UNINSTALL) /opt/
	cp -v $(INSTALL_DIR)/w2c-gui /usr/local/bin/
	cp -v $(DESKTOP_FILE) /usr/share/applications/
	cp -Rv icons /usr/share/w2c/icons

$(PROG_DIR): 
	src/progDir # program directory script to make sure directory exists before install.
	
uninstall: check
	/opt/$(UNINSTALL)
	rm -v /opt/$(UNINSTALL) 

check:
	ls /opt/$(UNINSTALL)
