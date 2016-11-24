#!/bin/sh
if [ $# != 0 ]; then
	echo ""
	echo "Usage: hello_world".
	echo ""
else
	echo "running...".
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=0 ./hello_world.exe $1 &
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=1 ./hello_world.exe $1 &
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=2 ../../bin/ns.exe
fi
