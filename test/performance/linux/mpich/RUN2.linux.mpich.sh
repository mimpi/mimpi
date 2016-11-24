#!/bin/sh



#
#  startup
#
echo ""
echo " linux.mpich.sh"
echo "----------------"
echo ""
TEST_PATH=/home/proyectos/mpi/src/MiMPI/test/performance/linux/mpich

#
#  begin testing ...
#
echo " ping"
echo "------"
echo ""
mpirun -nonlocal -np 2 $TEST_PATH/ping/ping.linux.mpich

echo " bcast"
echo "-------"
echo ""
mpirun -nonlocal -np 2 $TEST_PATH/bcast/bcast.linux.mpich

echo " gather"
echo "--------"
echo ""
mpirun -nonlocal -np 2 $TEST_PATH/gather/gather.linux.mpich

echo " scatter"
echo "--------"
echo ""
mpirun -nonlocal -np 2 $TEST_PATH/scatter/scatter.linux.mpich

#
#  stop
#
echo ""
echo " linux.mpich.sh"
echo "----------------"
echo ""




