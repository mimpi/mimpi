#!/bin/sh
if [ $# != 1 ]; then
	echo ""
	echo "Usage: ping <max_pingpong>".
	echo ""
else
	echo "running...".
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=0 ./ping.exe $1 &
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=1 ./ping.exe $1 &
	env NS_HOST=localhost NS_PORT=7500 _N_PROCS=2 _PROC_ID=2 ../../bin/ns.exe
fi
