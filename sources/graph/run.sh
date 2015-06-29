#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/libGDL/libs/:`pwd`/Sound/lib/
file=$(pwd)"/zappy_graph"

if [ -f "$file" ]
then
    echo "Running Graph Zappy";
    gdb ./zappy_graph;
else
    make re; ./zappy_graph;
fi
