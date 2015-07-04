#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/libGDL/libs/:`pwd`/Sound/lib/
file=$(pwd)"/zappy_graph"

if [ -f "$file" ]
then
    echo "Running Graph Zappy";
    if  [ $# -eq 2 ]
    then
	echo $1;
	echo $2;
	./zappy_graph $1 $2;
    else
	echo "No Arguments passing 127.0.0.1 & port 4242 as default";
	./zappy_graph 127.0.0.1 4242;
    fi
else
    make re; ./zappy_graph;
fi
