#!/bin/csh
# @ job_name       = ping.socket
# @ output         = RES/socket.$(cluster).$(process).out
# @ error          = ERR/socket.$(cluster).$(process).err
# @ initialdir     = /u/fperez/XMP/MiMPI/test.new/p7m/ping_pong
# @ job_type       = parallel
# @ class          = parallel
# @ min_processors = 2
# @ max_processors = 2
# @ notify_user    = fperez@besiberri.sp.cesca.es
# @ environment    = MP_EUILIB=us; MP_EUIDEVICE=css0; MP_PROCS=2; MP_PGMMODEL=mpmd; MP_NEWJOB=yes;
# notification     = complete
# @ requirements   = (Adapter == "hps_user")
# @ restart        = yes
# @ queue

poe < /u/fperez/XMP/MiMPI/test.new/p7m/ping_pong/run.proc
