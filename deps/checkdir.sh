#!/bin/bash

set -e

DIR=/opt/Write2chordpro

if [ -e $DIR ]
then
	echo "directory exists"
else
	./deps-download
	./install-deps
fi
