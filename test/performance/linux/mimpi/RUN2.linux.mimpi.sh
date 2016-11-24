#!/bin/sh



#
#  startup
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""
# ns
NS_HOST=138.100.9.94
NS_PORT=7500
NS_PATH=/home/proyectos/mpi/src/MiMPI/bin
# test
TEST_PATH=/home/proyectos/mpi/src/MiMPI/test/mp/mpi/performance
COMPRESS=BEST_SPEED


#
#  begin testing ...
#
echo " ping"
echo "------"
echo ""
rsh hinojo   "( cd $TEST_PATH/ping/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./ping.linux.xmp )" &
rsh arlo     "( cd $TEST_PATH/ping/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./ping.linux.xmp )" &
rsh $NS_HOST  "( cd $NS_PATH/        ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

echo " ping_mt"
echo "---------"
echo ""
rsh hinojo  "( cd $TEST_PATH/ping_r/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./ping.linux.xmp )" &
rsh arlo    "( cd $TEST_PATH/ping_r/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./ping.linux.xmp )" &
rsh $NS_HOST  "( cd $NS_PATH/        ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

echo " bcast"
echo "-------"
echo ""
rsh hinojo  "( cd $TEST_PATH/bcast/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./bcast.linux.xmp )" &
rsh arlo    "( cd $TEST_PATH/bcast/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./bcast.linux.xmp )" &
rsh $NS_HOST  "( cd $NS_PATH/         ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

echo " gather"
echo "--------"
echo ""
rsh hinojo  "( cd $TEST_PATH/gather/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./gather.linux.xmp )" &
rsh arlo    "( cd $TEST_PATH/gather/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./gather.linux.xmp )" &
rsh $NS_HOST  "( cd $NS_PATH/          ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

echo " scatter"
echo "--------"
echo ""
rsh hinojo  "( cd $TEST_PATH/scatter/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=0 ./scatter.linux.xmp )" &
rsh arlo    "( cd $TEST_PATH/scatter/ ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=1 ./scatter.linux.xmp )" &
rsh $NS_HOST  "( cd $NS_PATH/           ; env COMPRESSION=$COMPRESS NS_HOST=$NS_HOST NS_PORT=$NS_PORT _N_PROCS=2 _PROC_ID=2 ./ns.exe )"

#
#  stop
#
echo ""
echo " linux.mimpi.sh"
echo "----------------"
echo ""

