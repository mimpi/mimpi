#!/bin/sh
echo "running...".


cd /user1/uni/uc3m/mimpi/SRC/MiMPI.31/test/performance/irix/mimpi/ping
env COMPRESSION=NONE NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=0 ./ping.irix.xmp &
env COMPRESSION=NONE NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=1 ./ping.irix.xmp &
env COMPRESSION=NONE NS_HOST=localhost NS_PORT=7500    _N_PROCS=2 _PROC_ID=2 /user1/uni/uc3m/mimpi/MiMPI/bin/ns.exe
