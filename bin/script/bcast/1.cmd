#!/bin/csh
# @ job_name       = ./bcast.sp2.xmp
# @ output         = ./1.out
# @ error          = ./1.err
# @ initialdir     = /u/fperez/XMP/MiMPI/test/mp/mpi/performance/bcast/
# @ job_type       = parallel
# @ class          = parallel
# @ min_processors = 5
# @ max_processors = 5
# @ notify_user    = fperez@besiberri.sp.cesca.es
# @ environment    = MP_EUILIB=us; MP_EUIDEVICE=css0; MP_PROCS=5; MP_PGMMODEL=mpmd; MP_NEWJOB=yes;
# notification     = complete
# @ requirements   = (Adapter == "hps_user")
# @ restart        = yes
# @ queue
poe -procs 5 < /u/fperez/XMP/MiMPI/test/mp/mpi/performance/bcast/1.proc
quit
