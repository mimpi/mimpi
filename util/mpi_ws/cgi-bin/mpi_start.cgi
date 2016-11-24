#!/bin/sh

#
# disable filename globbing
#
set -f

#
# file type
#
echo Content-type: text/plain
echo

#
# get request
#
read LINE
echo $LINE > /tmp/mpi_run.$$.request.txt

#
# sed
#
sed "s/\&/ /g"    /tmp/mpi_run.$$.request.txt > /tmp/mpi_run.$$.sed.txt
mv                /tmp/mpi_run.$$.sed.txt       /tmp/mpi_run.$$.request.txt
sed "s/%2F/\//g"  /tmp/mpi_run.$$.request.txt > /tmp/mpi_run.$$.sed.txt
mv                /tmp/mpi_run.$$.sed.txt       /tmp/mpi_run.$$.request.txt

#
# echo
#
echo env `cat /tmp/mpi_run.$$.request.txt` ./mpi_exec.exe > /tmp/mpi_run.$$.sh.txt
mv            /tmp/mpi_run.$$.sh.txt   /tmp/mpi_run.$$.request.txt
echo "requesting to run a mpi program ..."
chmod 755 /tmp/mpi_run.$$.request.txt 
/tmp/mpi_run.$$.request.txt >& /tmp/mpi_run.$$.response.txt
cat /tmp/mpi_run.$$.response.txt | while read LINE; do
	echo $LINE
done
echo "request end."

#
# free resources
#
rm -fr            /tmp/mpi_run.$$.request.txt
rm -fr            /tmp/mpi_run.$$.response.txt

