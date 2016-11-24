#!/bin/sh
echo "running...".
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=0 ./reduce.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=1 ./reduce.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=2 /home/pabs/acaldero/w/mpi/XMP/MiMPI/bin/ns.exe
