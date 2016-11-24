SHELL = /bin/sh

include sys.def

dum: 
	@echo "Please use one of the following targets:"
	@echo
	@echo "For all three : compile, run, graph, clean, clobber, reconfig"
	@echo "For BlasBench : blas-bench, blas-run, blas-graph"
	@echo "For CacheBench: cache-bench, cache-run, cache-graph"
	@echo "For MPBench   : mp-bench, mp-run, mp-graph"

compile bench: blas-bench mp-bench cache-bench

run: blas-run cache-run mp-run

graphs graph: blas-graph cache-graph mp-graph

blas-bench:
	cd blasbench; make  
blas-run: 
	cd blasbench; make run
blas-graph:
	cd blasbench; make graph
cache-bench:
	cd cachebench; make 
cache-run:
	cd cachebench; make run
cache-graph:
	cd cachebench; make graph
mp-bench:
	cd mpbench; make 
mp-run:
	cd mpbench; make run
mp-graph:
	cd mpbench; make graph

sys.def reconfig:
	-rm -f sys.def
	ln -s conf/sys.default sys.def

clean:
	cd mpbench; make clean
	cd blasbench; make clean
	cd cachebench; make clean
	rm -f *~ */*~

clobber: reconfig
	cd mpbench; make clobber
	cd blasbench; make clobber
	cd cachebench; make clobber
	rm -f *~ */*~ results/*

dist: reconfig clobber
	cd ..; umask 2; chgrp -R utbench llcbench; chmod -R g+w llcbench;
	cd ..; tar cf llcbench.tar llcbench; gzip llcbench.tar
	rm -f llcbench.tar.gz; mv ../llcbench.tar.gz .

install: dist
	cp -p llcbench.tar.gz /silk/homes/icl/www-home/projects/llcbench
	cp -p www/*.html /silk/homes/icl/www-home/projects/llcbench
