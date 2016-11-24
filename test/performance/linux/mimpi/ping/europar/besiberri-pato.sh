ssh pato.arcos.inf.uc3m.es env NS_HOST=pato.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=2 /export/home/pato11-1/proyectos/mimpi/MiMPI/bin/ns.exe &
ssh pato.arcos.inf.uc3m.es env NS_HOST=pato.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=1 /export/home/pato11-1/proyectos/mimpi/Roberto/ping/ping.linux.xmp &
ssh besiberri.sp.cesca.es  env NS_HOST=pato.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=0 /home3/mimpi/SRC/mimpi.31/test/performance/sp2/mimpi/ping/ping.linux.xmp
