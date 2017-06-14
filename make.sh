#! /bin/bash

if [ ! -d "./build" ]
then
	mkdir build
	cd build
	cmake ..
	make
else
	cd build
fi

if [ ! -f "./app/robot.lg" ]
then
	cp ../app/robot.lg ./app
fi

cd ./app

./robot