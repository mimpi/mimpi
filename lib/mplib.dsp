# Microsoft Developer Studio Project File - Name="mplib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mplib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mplib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mplib.mak" CFG="mplib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mplib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mplib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mplib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir ".\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I ".\include" /I ".\src" /I "..\include" /I "..\src" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /D "HAVE_WINDOWS_H" /D "HAVE_LZO_H" /FR /YX /FD /c
# ADD BASE RSC /l 0xc0a /d "NDEBUG"
# ADD RSC /l 0xc0a /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir ".\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\include" /I "..\src" /D "_DEBUG" /D "__DEBUG__" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /D "HAVE_WINDOWS_H" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc0a /d "_DEBUG"
# ADD RSC /l 0xc0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "mplib - Win32 Release"
# Name "mplib - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\base\l_alloc\l_alloc.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_authors.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_barrier.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_barrier\l_barrier_48h.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_bcast.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_chain.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_list.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_tree.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_adt\l_buffa.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_comm.c
# End Source File
# Begin Source File

SOURCE=..\src\console\l_condition_msg.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_adt\l_darray.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_byte.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_char.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_double.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_float.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_int.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_long.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_short.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_debug\l_debug.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_debug\l_debug_dfa.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_debug\l_debug_msg.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_adt\l_dhash.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_creat.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_default.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_disc.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_match.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_open.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_unlink.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_adt\l_dstack.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_dump_all.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_finalize.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_gather.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_gather\l_gather_list.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_go_debug.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_group.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_init.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_initialized.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_misc.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_async.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_sync.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_thread.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman\l_netid.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman\l_netlnk.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodecmd.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei\l_nodedata.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodegrp.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei\l_nodeheader.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodeinfo.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_nodeli.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodereq.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_ns_params.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_ns_params\l_ns_params_sb.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_nsi.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_params_mpi.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_params_xmp.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_recv.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_reduce.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_list.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_one.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_op.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_reqman\l_reqli.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_reqman.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_root.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\base\l_sb.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\base\l_sb_sock.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_scatter.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_scatter\l_scatter_list.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_send.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_sendrecv.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\l_single_request.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_accept.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns\l_snoopy_ns_dump.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns\l_snoopy_ns_trace.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_recv.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_send.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\l_society.c
# End Source File
# Begin Source File

SOURCE=..\src\console\l_stack_msg.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_string\l_string.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_time\l_time.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_trace_all.c
# End Source File
# Begin Source File

SOURCE=..\src\console\l_trace_msg.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_unknow.c
# End Source File
# Begin Source File

SOURCE=..\src\console\l_verbose_msg.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\base\node.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\mpi_xmp\map\params_mpi.c
# End Source File
# Begin Source File

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\params_xmp.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_alloc\v_alloc.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_string\v_dtd.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_file\v_file.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_process\v_process.c
# End Source File
# Begin Source File

SOURCE=..\src\base\L_socket\v_socket.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_thread\v_thread.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_zlib\v_zl.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_alloc\x_alloc.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_string\x_dtd.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_file\x_file.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_process\x_process.c
# End Source File
# Begin Source File

SOURCE=..\src\base\L_socket\x_socket.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_string\x_string.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_thread\x_thread.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_time\x_time.c
# End Source File
# Begin Source File

SOURCE=..\src\base\l_zlib\x_zl.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
