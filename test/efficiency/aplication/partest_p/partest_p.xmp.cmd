#!/bin/csh
# @ job_name =  partest_parallel
# @ output   =  partest_p.xmp.stdout
# @ error    =  partest_p.xmp.stderr
# @ initialdir = /a/incw2/home2/fperez/FELIX/XMP/xmp/test/mpi/partest_p
# @ job_type = parallel
# @ class = parallel
# @ min_processors = 3
# @ max_processors = 3
# @ notify_user = fperez@besiberri.sp.cesca.es
# @ environment = MP_EUILIB=us; MP_EUIDEVICE=css0; MP_PROCS=3; MP_PGMMODEL=mpmd; MP_NEWJOB=yes;
# notification = complete
# @ requirements = (Adapter == "hps_user")
# @ restart = yes
# @ queue


setenv dir /a/incw2/home2/fperez/FELIX/XMP/xmp/test/mpi/partest_p

poe -procs 3 < $dir/partest_p.xmp.proc
quit


