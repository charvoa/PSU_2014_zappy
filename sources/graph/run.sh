#!/bin/bash

export LD_LIBRARY_PATH=`pwd`/libGDL/libs/:`pwd`/Sound/lib/
file=$(pwd)"/zappy_graph"

if [ -f "$file" ]
then
    echo "Running Graph Zappy";
    ./zappy_graph 127.0.0.1 4242;
else
    make re; ./zappy_graph 127.0.0.1 4242;
fi
