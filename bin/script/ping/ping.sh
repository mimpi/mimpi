#!/bin/sh
echo "running...".
env COMPRESSION=NO   NS_HOST=localhost NS_PORT=7500   _N_PROCS=2 _PROC_ID=0 ./ping.linux.xmp &
env COMPRESSION=NO   NS_HOST=localhost NS_PORT=7500   _N_PROCS=2 _PROC_ID=1 ./ping.linux.xmp &
env COMPRESSION=NO   NS_HOST=localhost NS_PORT=7500   _N_PROCS=2 _PROC_ID=2 /home/pabs/acaldero/w/mpi/XMP/MiMPI/bin/ns.exe
