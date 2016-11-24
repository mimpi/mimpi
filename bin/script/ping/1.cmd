#!/bin/csh
# @ job_name       = ./ping.sp2.xmp
# @ output         = ./1.out
# @ error          = ./1.out
# @ initialdir     = /u/fperez/XMP/MiMPI/test/mp/mpi/performance/ping/
# @ job_type       = parallel
# @ class          = parallel
# @ min_processors = 3
# @ max_processors = 3
# @ notify_user    = fperez@besiberri.sp.cesca.es
# @ environment    = MP_EUILIB=us; MP_EUIDEVICE=css0; MP_PROCS=3; MP_PGMMODEL=mpmd; MP_NEWJOB=yes;
# notification     = complete
# @ requirements   = (Adapter == "hps_user")
# @ restart        = yes
# @ queue
poe -procs 3 < /u/fperez/XMP/MiMPI/test/mp/mpi/performance/ping/1.proc
quit
