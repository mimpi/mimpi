#!/bin/sh



#
#  startup
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""
# ns
NS_HOST=138.100.9.62
NS_PORT=7500
NS_PATH=/home/pabs/acaldero/w/mpi/XMP/MiMPI/bin
# test
TEST_PATH=/home/pabs/acaldero/w/mpi/XMP/MiMPI/test/mp/mpi/performance


#
#  begin testing ...
#
echo " ping"
echo "------"
echo ""
rsh hinojo   "( cd $TEST_PATH/ping/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./ping.linux.xmp )" &
rsh arlo     "( cd $TEST_PATH/ping/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./ping.linux.xmp )" &
rsh $NS_HOST "( cd $NS_PATH/        ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

#
#  stop
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""

