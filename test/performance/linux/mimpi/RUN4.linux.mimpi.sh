#!/bin/sh



#
#  startup
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""
# ns
NS_HOST=138.100.9.73
NS_PORT=7500
NS_PATH=/home/proyectos/mpi/src/MiMPI/bin
NS_NAME=./ns.exe
# test
TEST_PATH=/home/proyectos/mpi/src/MiMPI/test/mp/mpi/performance
PING_NAME=./ping.linux.xmp
SCATTER_NAME=./scatter.linux.xmp
GATHER_NAME=./gather.linux.xmp
BCAST_NAME=./bcast.linux.xmp


#
#  begin testing ...
#
echo " ping"
echo "------"
echo ""
rsh hinojo   "( cd $TEST_PATH/ping/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 $PING_NAME )" &
rsh arlo     "( cd $TEST_PATH/ping/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 $PING_NAME )" &
rsh $NS_HOST "( cd $NS_PATH/        ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 $NS_NAME )"

echo " ping_mt"
echo "---------"
echo ""
rsh hinojo   "( cd $TEST_PATH/ping_r/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 $PING_NAME )" &
rsh arlo     "( cd $TEST_PATH/ping_r/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 $PING_NAME )" &
rsh $NS_HOST "( cd $NS_PATH/          ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 $NS_NAME )"

echo " bcast"
echo "-------"
echo ""
rsh hinojo   "( cd $TEST_PATH/bcast/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=0 $BCAST_NAME )" &
rsh arlo     "( cd $TEST_PATH/bcast/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=1 $BCAST_NAME )" &
rsh tamujo   "( cd $TEST_PATH/bcast/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=2 $BCAST_NAME )" &
rsh escoba   "( cd $TEST_PATH/bcast/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=3 $BCAST_NAME )" &
rsh $NS_HOST "( cd $NS_PATH/         ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=4 $NS_NAME )"

echo " gather"
echo "--------"
echo ""
rsh hinojo  "( cd $TEST_PATH/gather/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=0 $GATHER_NAME )" &
rsh arlo    "( cd $TEST_PATH/gather/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=1 $GATHER_NAME )" &
rsh tamujo  "( cd $TEST_PATH/gather/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=2 $GATHER_NAME )" &
rsh escoba  "( cd $TEST_PATH/gather/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=3 $GATHER_NAME )" &
rsh $NS_HOST  "( cd $NS_PATH/          ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=4 $NS_NAME )"

echo " scatter"
echo "--------"
echo ""
rsh hinojo  "( cd $TEST_PATH/scatter/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=0 $SCATTER_NAME )" &
rsh arlo    "( cd $TEST_PATH/scatter/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=1 $SCATTER_NAME )" &
rsh tamujo  "( cd $TEST_PATH/scatter/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=2 $SCATTER_NAME )" &
rsh escoba  "( cd $TEST_PATH/scatter/ ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=3 $SCATTER_NAME )" &
rsh $NS_HOST  "( cd $NS_PATH/           ; env NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=4 _PROC_ID=4 $NS_NAME )"

#
#  stop
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""

