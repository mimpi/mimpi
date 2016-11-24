#!/bin/tcsh
echo "running...".

cd /user1/uni/uc3m/mimpi/SRC/MiMPI.31/test/performance/irix/mimpi/ping
mpirun -np 2 ping.irix.mpi
