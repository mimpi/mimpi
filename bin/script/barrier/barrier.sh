#!/bin/sh


echo "running...".

#
#  2
#
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=0 ./barrier.linux.xmp &
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=1 ./barrier.linux.xmp &
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=2 ../../../../../bin/ns.exe

#
#  4
#
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=0 ./barrier.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=1 ./barrier.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=2 ./barrier.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=3 ./barrier.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=4 ~mimpi/MiMPI/bin/ns.exe
