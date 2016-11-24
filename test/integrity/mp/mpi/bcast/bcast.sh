#!/bin/sh


echo "running...".

#
#  2
#
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=0 ./bcast.linux.xmp &
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=1 ./bcast.linux.xmp &
#env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=2 /home/pabs/acaldero/w/mpi/XMP/MiMPI/bin/ns.exe

#
#  4
#
env COMPRESSION=BEST_SPEED NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=0 ./bcast.linux.xmp &
env COMPRESSION=BEST_SPEED NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=1 ./bcast.linux.xmp &
env COMPRESSION=BEST_SPEED NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=2 ./bcast.linux.xmp &
env COMPRESSION=BEST_SPEED NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=3 ./bcast.linux.xmp &
env COMPRESSION=BEST_SPEED NS_HOST=localhost NS_PORT=7500    _N_PROCS=4 _PROC_ID=4 ~mimpid/MiMPI/bin/ns.exe
