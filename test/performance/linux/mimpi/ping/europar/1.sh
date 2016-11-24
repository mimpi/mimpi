#!/bin/sh
echo "running...".
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=0 ./ping.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=1 ./ping.linux.xmp &
env NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=2 /user1/uni/uc3m/mimpi/MiMPI/bin/ns.exe
