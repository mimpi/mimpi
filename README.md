# MiMPI: Multithred-Safe (partial) Implementation of MPI
Quick Start

How to get binaries from source:
-------------------------------
  
   # cd <MiMPI directory>
  
        To go to the MiMPI base directory.
  
   # vi configure.in

        [ OPTIONAL ] To add or change any option you wish.
  
   # autoconf

        Command to use in order to generate the "configure" script.
  
   # ./configure
  
        Use ./configure in order to check your system and to generate the associated Makefiles.
  
   # make
  
        Compile MiMPI as a library ( lib/libmpi.a ),
        a daemon needed to run ( bin/ns.exe ) and some
        examples ( example/* )
  

How to install binaries into system:
-----------------------------------
  
   # cp lib/libmpi.a     &lt;system library path&gt;<br>
   # cp include/mpi.h    &lt;system includes path&gt;<br>
   # cp bin/ns.exe       &lt;system binary path&gt;
  
      System library path are usally /lib or /usr/lib.
      System includes path is /usr/include and
      System binary path can be /bin or /usr/bin.
  
  
Some test for MiMPI:
--------------------
  
   # cd test
        
        Go to test directory.
        
   # make
        
        Compile many test. Some options are plataform-bounded.



