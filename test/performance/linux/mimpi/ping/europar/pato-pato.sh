rsh pato1 env NS_HOST=pato11.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=2 /export/home/pato11-1/proyectos/mimpi/MiMPI/bin/ns.exe &
rsh pato2 env NS_HOST=pato11.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=0 /export/home/pato11-1/proyectos/mimpi/Roberto/ping/ping.linux.xmp &
rsh pato3 env NS_HOST=pato11.arcos.inf.uc3m.es NS_PORT=7500 _N_PROCS=2 _PROC_ID=1 /export/home/pato11-1/proyectos/mimpi/Roberto/ping/ping.linux.xmp &
