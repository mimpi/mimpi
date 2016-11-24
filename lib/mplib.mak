# Microsoft Developer Studio Generated NMAKE File, Based on mplib.dsp
!IF "$(CFG)" == ""
CFG=mplib - Win32 Debug
!MESSAGE No configuration specified. Defaulting to mplib - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "mplib - Win32 Release" && "$(CFG)" != "mplib - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mplib - Win32 Release"

OUTDIR=.\.
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.
# End Custom Macros

ALL : "$(OUTDIR)\mplib.lib" "$(OUTDIR)\mplib.bsc"


CLEAN :
	-@erase "$(INTDIR)\l_alloc.obj"
	-@erase "$(INTDIR)\l_alloc.sbr"
	-@erase "$(INTDIR)\l_authors.obj"
	-@erase "$(INTDIR)\l_authors.sbr"
	-@erase "$(INTDIR)\l_barrier.obj"
	-@erase "$(INTDIR)\l_barrier.sbr"
	-@erase "$(INTDIR)\l_barrier_48h.obj"
	-@erase "$(INTDIR)\l_barrier_48h.sbr"
	-@erase "$(INTDIR)\l_bcast.obj"
	-@erase "$(INTDIR)\l_bcast.sbr"
	-@erase "$(INTDIR)\l_bcast_chain.obj"
	-@erase "$(INTDIR)\l_bcast_chain.sbr"
	-@erase "$(INTDIR)\l_bcast_list.obj"
	-@erase "$(INTDIR)\l_bcast_list.sbr"
	-@erase "$(INTDIR)\l_bcast_tree.obj"
	-@erase "$(INTDIR)\l_bcast_tree.sbr"
	-@erase "$(INTDIR)\l_brow.obj"
	-@erase "$(INTDIR)\l_brow.sbr"
	-@erase "$(INTDIR)\l_buffa.obj"
	-@erase "$(INTDIR)\l_buffa.sbr"
	-@erase "$(INTDIR)\l_comm.obj"
	-@erase "$(INTDIR)\l_comm.sbr"
	-@erase "$(INTDIR)\l_condition_msg.obj"
	-@erase "$(INTDIR)\l_condition_msg.sbr"
	-@erase "$(INTDIR)\l_darray.obj"
	-@erase "$(INTDIR)\l_darray.sbr"
	-@erase "$(INTDIR)\l_datatype.obj"
	-@erase "$(INTDIR)\l_datatype.sbr"
	-@erase "$(INTDIR)\l_datatype_byte.obj"
	-@erase "$(INTDIR)\l_datatype_byte.sbr"
	-@erase "$(INTDIR)\l_datatype_char.obj"
	-@erase "$(INTDIR)\l_datatype_char.sbr"
	-@erase "$(INTDIR)\l_datatype_double.obj"
	-@erase "$(INTDIR)\l_datatype_double.sbr"
	-@erase "$(INTDIR)\l_datatype_float.obj"
	-@erase "$(INTDIR)\l_datatype_float.sbr"
	-@erase "$(INTDIR)\l_datatype_int.obj"
	-@erase "$(INTDIR)\l_datatype_int.sbr"
	-@erase "$(INTDIR)\l_datatype_long.obj"
	-@erase "$(INTDIR)\l_datatype_long.sbr"
	-@erase "$(INTDIR)\l_datatype_short.obj"
	-@erase "$(INTDIR)\l_datatype_short.sbr"
	-@erase "$(INTDIR)\l_debug.obj"
	-@erase "$(INTDIR)\l_debug.sbr"
	-@erase "$(INTDIR)\l_debug_dfa.obj"
	-@erase "$(INTDIR)\l_debug_dfa.sbr"
	-@erase "$(INTDIR)\l_debug_msg.obj"
	-@erase "$(INTDIR)\l_debug_msg.sbr"
	-@erase "$(INTDIR)\l_dhash.obj"
	-@erase "$(INTDIR)\l_dhash.sbr"
	-@erase "$(INTDIR)\l_do_creat.obj"
	-@erase "$(INTDIR)\l_do_creat.sbr"
	-@erase "$(INTDIR)\l_do_default.obj"
	-@erase "$(INTDIR)\l_do_default.sbr"
	-@erase "$(INTDIR)\l_do_disc.obj"
	-@erase "$(INTDIR)\l_do_disc.sbr"
	-@erase "$(INTDIR)\l_do_match.obj"
	-@erase "$(INTDIR)\l_do_match.sbr"
	-@erase "$(INTDIR)\l_do_open.obj"
	-@erase "$(INTDIR)\l_do_open.sbr"
	-@erase "$(INTDIR)\l_do_unlink.obj"
	-@erase "$(INTDIR)\l_do_unlink.sbr"
	-@erase "$(INTDIR)\l_dstack.obj"
	-@erase "$(INTDIR)\l_dstack.sbr"
	-@erase "$(INTDIR)\l_dump_all.obj"
	-@erase "$(INTDIR)\l_dump_all.sbr"
	-@erase "$(INTDIR)\l_finalize.obj"
	-@erase "$(INTDIR)\l_finalize.sbr"
	-@erase "$(INTDIR)\l_gather.obj"
	-@erase "$(INTDIR)\l_gather.sbr"
	-@erase "$(INTDIR)\l_gather_list.obj"
	-@erase "$(INTDIR)\l_gather_list.sbr"
	-@erase "$(INTDIR)\l_go_debug.obj"
	-@erase "$(INTDIR)\l_go_debug.sbr"
	-@erase "$(INTDIR)\l_group.obj"
	-@erase "$(INTDIR)\l_group.sbr"
	-@erase "$(INTDIR)\l_init.obj"
	-@erase "$(INTDIR)\l_init.sbr"
	-@erase "$(INTDIR)\l_initialized.obj"
	-@erase "$(INTDIR)\l_initialized.sbr"
	-@erase "$(INTDIR)\l_misc.obj"
	-@erase "$(INTDIR)\l_misc.sbr"
	-@erase "$(INTDIR)\l_mr_async.obj"
	-@erase "$(INTDIR)\l_mr_async.sbr"
	-@erase "$(INTDIR)\l_mr_sync.obj"
	-@erase "$(INTDIR)\l_mr_sync.sbr"
	-@erase "$(INTDIR)\l_mr_thread.obj"
	-@erase "$(INTDIR)\l_mr_thread.sbr"
	-@erase "$(INTDIR)\l_multi_request.obj"
	-@erase "$(INTDIR)\l_multi_request.sbr"
	-@erase "$(INTDIR)\l_netid.obj"
	-@erase "$(INTDIR)\l_netid.sbr"
	-@erase "$(INTDIR)\l_netlnk.obj"
	-@erase "$(INTDIR)\l_netlnk.sbr"
	-@erase "$(INTDIR)\l_netman.obj"
	-@erase "$(INTDIR)\l_netman.sbr"
	-@erase "$(INTDIR)\l_node.obj"
	-@erase "$(INTDIR)\l_node.sbr"
	-@erase "$(INTDIR)\l_nodecmd.obj"
	-@erase "$(INTDIR)\l_nodecmd.sbr"
	-@erase "$(INTDIR)\l_nodedata.obj"
	-@erase "$(INTDIR)\l_nodedata.sbr"
	-@erase "$(INTDIR)\l_nodegrp.obj"
	-@erase "$(INTDIR)\l_nodegrp.sbr"
	-@erase "$(INTDIR)\l_nodeheader.obj"
	-@erase "$(INTDIR)\l_nodeheader.sbr"
	-@erase "$(INTDIR)\l_nodei.obj"
	-@erase "$(INTDIR)\l_nodei.sbr"
	-@erase "$(INTDIR)\l_nodeinfo.obj"
	-@erase "$(INTDIR)\l_nodeinfo.sbr"
	-@erase "$(INTDIR)\l_nodeli.obj"
	-@erase "$(INTDIR)\l_nodeli.sbr"
	-@erase "$(INTDIR)\l_nodereq.obj"
	-@erase "$(INTDIR)\l_nodereq.sbr"
	-@erase "$(INTDIR)\l_nodes.obj"
	-@erase "$(INTDIR)\l_nodes.sbr"
	-@erase "$(INTDIR)\l_ns.obj"
	-@erase "$(INTDIR)\l_ns.sbr"
	-@erase "$(INTDIR)\l_ns_params.obj"
	-@erase "$(INTDIR)\l_ns_params.sbr"
	-@erase "$(INTDIR)\l_ns_params_sb.obj"
	-@erase "$(INTDIR)\l_ns_params_sb.sbr"
	-@erase "$(INTDIR)\l_nsi.obj"
	-@erase "$(INTDIR)\l_nsi.sbr"
	-@erase "$(INTDIR)\l_params_mpi.obj"
	-@erase "$(INTDIR)\l_params_mpi.sbr"
	-@erase "$(INTDIR)\l_params_xmp.obj"
	-@erase "$(INTDIR)\l_params_xmp.sbr"
	-@erase "$(INTDIR)\l_recv.obj"
	-@erase "$(INTDIR)\l_recv.sbr"
	-@erase "$(INTDIR)\l_reduce.obj"
	-@erase "$(INTDIR)\l_reduce.sbr"
	-@erase "$(INTDIR)\l_reduce_list.obj"
	-@erase "$(INTDIR)\l_reduce_list.sbr"
	-@erase "$(INTDIR)\l_reduce_one.obj"
	-@erase "$(INTDIR)\l_reduce_one.sbr"
	-@erase "$(INTDIR)\l_reduce_op.obj"
	-@erase "$(INTDIR)\l_reduce_op.sbr"
	-@erase "$(INTDIR)\l_reqli.obj"
	-@erase "$(INTDIR)\l_reqli.sbr"
	-@erase "$(INTDIR)\l_reqman.obj"
	-@erase "$(INTDIR)\l_reqman.sbr"
	-@erase "$(INTDIR)\l_root.obj"
	-@erase "$(INTDIR)\l_root.sbr"
	-@erase "$(INTDIR)\l_sb.obj"
	-@erase "$(INTDIR)\l_sb.sbr"
	-@erase "$(INTDIR)\l_sb_sock.obj"
	-@erase "$(INTDIR)\l_sb_sock.sbr"
	-@erase "$(INTDIR)\l_scatter.obj"
	-@erase "$(INTDIR)\l_scatter.sbr"
	-@erase "$(INTDIR)\l_scatter_list.obj"
	-@erase "$(INTDIR)\l_scatter_list.sbr"
	-@erase "$(INTDIR)\l_send.obj"
	-@erase "$(INTDIR)\l_send.sbr"
	-@erase "$(INTDIR)\l_sendrecv.obj"
	-@erase "$(INTDIR)\l_sendrecv.sbr"
	-@erase "$(INTDIR)\l_single_request.obj"
	-@erase "$(INTDIR)\l_single_request.sbr"
	-@erase "$(INTDIR)\l_snoopy.obj"
	-@erase "$(INTDIR)\l_snoopy.sbr"
	-@erase "$(INTDIR)\l_snoopy_accept.obj"
	-@erase "$(INTDIR)\l_snoopy_accept.sbr"
	-@erase "$(INTDIR)\l_snoopy_ns.obj"
	-@erase "$(INTDIR)\l_snoopy_ns.sbr"
	-@erase "$(INTDIR)\l_snoopy_ns_dump.obj"
	-@erase "$(INTDIR)\l_snoopy_ns_dump.sbr"
	-@erase "$(INTDIR)\l_snoopy_ns_trace.obj"
	-@erase "$(INTDIR)\l_snoopy_ns_trace.sbr"
	-@erase "$(INTDIR)\l_snoopy_recv.obj"
	-@erase "$(INTDIR)\l_snoopy_recv.sbr"
	-@erase "$(INTDIR)\l_snoopy_send.obj"
	-@erase "$(INTDIR)\l_snoopy_send.sbr"
	-@erase "$(INTDIR)\l_society.obj"
	-@erase "$(INTDIR)\l_society.sbr"
	-@erase "$(INTDIR)\l_stack_msg.obj"
	-@erase "$(INTDIR)\l_stack_msg.sbr"
	-@erase "$(INTDIR)\l_string.obj"
	-@erase "$(INTDIR)\l_string.sbr"
	-@erase "$(INTDIR)\l_time.obj"
	-@erase "$(INTDIR)\l_time.sbr"
	-@erase "$(INTDIR)\l_trace_all.obj"
	-@erase "$(INTDIR)\l_trace_all.sbr"
	-@erase "$(INTDIR)\l_trace_msg.obj"
	-@erase "$(INTDIR)\l_trace_msg.sbr"
	-@erase "$(INTDIR)\l_unknow.obj"
	-@erase "$(INTDIR)\l_unknow.sbr"
	-@erase "$(INTDIR)\l_verbose_msg.obj"
	-@erase "$(INTDIR)\l_verbose_msg.sbr"
	-@erase "$(INTDIR)\node.obj"
	-@erase "$(INTDIR)\node.sbr"
	-@erase "$(INTDIR)\params_mpi.obj"
	-@erase "$(INTDIR)\params_mpi.sbr"
	-@erase "$(INTDIR)\params_xmp.obj"
	-@erase "$(INTDIR)\params_xmp.sbr"
	-@erase "$(INTDIR)\v_alloc.obj"
	-@erase "$(INTDIR)\v_alloc.sbr"
	-@erase "$(INTDIR)\v_dtd.obj"
	-@erase "$(INTDIR)\v_dtd.sbr"
	-@erase "$(INTDIR)\v_file.obj"
	-@erase "$(INTDIR)\v_file.sbr"
	-@erase "$(INTDIR)\v_process.obj"
	-@erase "$(INTDIR)\v_process.sbr"
	-@erase "$(INTDIR)\v_socket.obj"
	-@erase "$(INTDIR)\v_socket.sbr"
	-@erase "$(INTDIR)\v_thread.obj"
	-@erase "$(INTDIR)\v_thread.sbr"
	-@erase "$(INTDIR)\v_zl.obj"
	-@erase "$(INTDIR)\v_zl.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\x_alloc.obj"
	-@erase "$(INTDIR)\x_alloc.sbr"
	-@erase "$(INTDIR)\x_dtd.obj"
	-@erase "$(INTDIR)\x_dtd.sbr"
	-@erase "$(INTDIR)\x_file.obj"
	-@erase "$(INTDIR)\x_file.sbr"
	-@erase "$(INTDIR)\x_process.obj"
	-@erase "$(INTDIR)\x_process.sbr"
	-@erase "$(INTDIR)\x_socket.obj"
	-@erase "$(INTDIR)\x_socket.sbr"
	-@erase "$(INTDIR)\x_string.obj"
	-@erase "$(INTDIR)\x_string.sbr"
	-@erase "$(INTDIR)\x_thread.obj"
	-@erase "$(INTDIR)\x_thread.sbr"
	-@erase "$(INTDIR)\x_time.obj"
	-@erase "$(INTDIR)\x_time.sbr"
	-@erase "$(INTDIR)\x_zl.obj"
	-@erase "$(INTDIR)\x_zl.sbr"
	-@erase "$(OUTDIR)\mplib.bsc"
	-@erase "$(OUTDIR)\mplib.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /I ".\include" /I ".\src" /I "..\include" /I "..\src" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /D "HAVE_WINDOWS_H" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\mplib.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mplib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\l_alloc.sbr" \
	"$(INTDIR)\l_authors.sbr" \
	"$(INTDIR)\l_barrier.sbr" \
	"$(INTDIR)\l_barrier_48h.sbr" \
	"$(INTDIR)\l_bcast.sbr" \
	"$(INTDIR)\l_bcast_chain.sbr" \
	"$(INTDIR)\l_bcast_list.sbr" \
	"$(INTDIR)\l_bcast_tree.sbr" \
	"$(INTDIR)\l_brow.sbr" \
	"$(INTDIR)\l_buffa.sbr" \
	"$(INTDIR)\l_comm.sbr" \
	"$(INTDIR)\l_condition_msg.sbr" \
	"$(INTDIR)\l_darray.sbr" \
	"$(INTDIR)\l_datatype.sbr" \
	"$(INTDIR)\l_datatype_byte.sbr" \
	"$(INTDIR)\l_datatype_char.sbr" \
	"$(INTDIR)\l_datatype_double.sbr" \
	"$(INTDIR)\l_datatype_float.sbr" \
	"$(INTDIR)\l_datatype_int.sbr" \
	"$(INTDIR)\l_datatype_long.sbr" \
	"$(INTDIR)\l_datatype_short.sbr" \
	"$(INTDIR)\l_debug.sbr" \
	"$(INTDIR)\l_debug_dfa.sbr" \
	"$(INTDIR)\l_debug_msg.sbr" \
	"$(INTDIR)\l_dhash.sbr" \
	"$(INTDIR)\l_do_creat.sbr" \
	"$(INTDIR)\l_do_default.sbr" \
	"$(INTDIR)\l_do_disc.sbr" \
	"$(INTDIR)\l_do_match.sbr" \
	"$(INTDIR)\l_do_open.sbr" \
	"$(INTDIR)\l_do_unlink.sbr" \
	"$(INTDIR)\l_dstack.sbr" \
	"$(INTDIR)\l_dump_all.sbr" \
	"$(INTDIR)\l_finalize.sbr" \
	"$(INTDIR)\l_gather.sbr" \
	"$(INTDIR)\l_gather_list.sbr" \
	"$(INTDIR)\l_go_debug.sbr" \
	"$(INTDIR)\l_group.sbr" \
	"$(INTDIR)\l_init.sbr" \
	"$(INTDIR)\l_initialized.sbr" \
	"$(INTDIR)\l_misc.sbr" \
	"$(INTDIR)\l_mr_async.sbr" \
	"$(INTDIR)\l_mr_sync.sbr" \
	"$(INTDIR)\l_mr_thread.sbr" \
	"$(INTDIR)\l_multi_request.sbr" \
	"$(INTDIR)\l_netid.sbr" \
	"$(INTDIR)\l_netlnk.sbr" \
	"$(INTDIR)\l_netman.sbr" \
	"$(INTDIR)\l_node.sbr" \
	"$(INTDIR)\l_nodecmd.sbr" \
	"$(INTDIR)\l_nodedata.sbr" \
	"$(INTDIR)\l_nodegrp.sbr" \
	"$(INTDIR)\l_nodeheader.sbr" \
	"$(INTDIR)\l_nodei.sbr" \
	"$(INTDIR)\l_nodeinfo.sbr" \
	"$(INTDIR)\l_nodeli.sbr" \
	"$(INTDIR)\l_nodereq.sbr" \
	"$(INTDIR)\l_nodes.sbr" \
	"$(INTDIR)\l_ns.sbr" \
	"$(INTDIR)\l_ns_params.sbr" \
	"$(INTDIR)\l_ns_params_sb.sbr" \
	"$(INTDIR)\l_nsi.sbr" \
	"$(INTDIR)\l_params_mpi.sbr" \
	"$(INTDIR)\l_params_xmp.sbr" \
	"$(INTDIR)\l_recv.sbr" \
	"$(INTDIR)\l_reduce.sbr" \
	"$(INTDIR)\l_reduce_list.sbr" \
	"$(INTDIR)\l_reduce_one.sbr" \
	"$(INTDIR)\l_reduce_op.sbr" \
	"$(INTDIR)\l_reqli.sbr" \
	"$(INTDIR)\l_reqman.sbr" \
	"$(INTDIR)\l_root.sbr" \
	"$(INTDIR)\l_sb.sbr" \
	"$(INTDIR)\l_sb_sock.sbr" \
	"$(INTDIR)\l_scatter.sbr" \
	"$(INTDIR)\l_scatter_list.sbr" \
	"$(INTDIR)\l_send.sbr" \
	"$(INTDIR)\l_sendrecv.sbr" \
	"$(INTDIR)\l_single_request.sbr" \
	"$(INTDIR)\l_snoopy.sbr" \
	"$(INTDIR)\l_snoopy_accept.sbr" \
	"$(INTDIR)\l_snoopy_ns.sbr" \
	"$(INTDIR)\l_snoopy_ns_dump.sbr" \
	"$(INTDIR)\l_snoopy_ns_trace.sbr" \
	"$(INTDIR)\l_snoopy_recv.sbr" \
	"$(INTDIR)\l_snoopy_send.sbr" \
	"$(INTDIR)\l_society.sbr" \
	"$(INTDIR)\l_stack_msg.sbr" \
	"$(INTDIR)\l_string.sbr" \
	"$(INTDIR)\l_time.sbr" \
	"$(INTDIR)\l_trace_all.sbr" \
	"$(INTDIR)\l_trace_msg.sbr" \
	"$(INTDIR)\l_unknow.sbr" \
	"$(INTDIR)\l_verbose_msg.sbr" \
	"$(INTDIR)\node.sbr" \
	"$(INTDIR)\params_mpi.sbr" \
	"$(INTDIR)\params_xmp.sbr" \
	"$(INTDIR)\v_alloc.sbr" \
	"$(INTDIR)\v_dtd.sbr" \
	"$(INTDIR)\v_file.sbr" \
	"$(INTDIR)\v_process.sbr" \
	"$(INTDIR)\v_socket.sbr" \
	"$(INTDIR)\v_thread.sbr" \
	"$(INTDIR)\v_zl.sbr" \
	"$(INTDIR)\x_alloc.sbr" \
	"$(INTDIR)\x_dtd.sbr" \
	"$(INTDIR)\x_file.sbr" \
	"$(INTDIR)\x_process.sbr" \
	"$(INTDIR)\x_socket.sbr" \
	"$(INTDIR)\x_string.sbr" \
	"$(INTDIR)\x_thread.sbr" \
	"$(INTDIR)\x_time.sbr" \
	"$(INTDIR)\x_zl.sbr"

"$(OUTDIR)\mplib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\mplib.lib" 
LIB32_OBJS= \
	"$(INTDIR)\l_alloc.obj" \
	"$(INTDIR)\l_authors.obj" \
	"$(INTDIR)\l_barrier.obj" \
	"$(INTDIR)\l_barrier_48h.obj" \
	"$(INTDIR)\l_bcast.obj" \
	"$(INTDIR)\l_bcast_chain.obj" \
	"$(INTDIR)\l_bcast_list.obj" \
	"$(INTDIR)\l_bcast_tree.obj" \
	"$(INTDIR)\l_brow.obj" \
	"$(INTDIR)\l_buffa.obj" \
	"$(INTDIR)\l_comm.obj" \
	"$(INTDIR)\l_condition_msg.obj" \
	"$(INTDIR)\l_darray.obj" \
	"$(INTDIR)\l_datatype.obj" \
	"$(INTDIR)\l_datatype_byte.obj" \
	"$(INTDIR)\l_datatype_char.obj" \
	"$(INTDIR)\l_datatype_double.obj" \
	"$(INTDIR)\l_datatype_float.obj" \
	"$(INTDIR)\l_datatype_int.obj" \
	"$(INTDIR)\l_datatype_long.obj" \
	"$(INTDIR)\l_datatype_short.obj" \
	"$(INTDIR)\l_debug.obj" \
	"$(INTDIR)\l_debug_dfa.obj" \
	"$(INTDIR)\l_debug_msg.obj" \
	"$(INTDIR)\l_dhash.obj" \
	"$(INTDIR)\l_do_creat.obj" \
	"$(INTDIR)\l_do_default.obj" \
	"$(INTDIR)\l_do_disc.obj" \
	"$(INTDIR)\l_do_match.obj" \
	"$(INTDIR)\l_do_open.obj" \
	"$(INTDIR)\l_do_unlink.obj" \
	"$(INTDIR)\l_dstack.obj" \
	"$(INTDIR)\l_dump_all.obj" \
	"$(INTDIR)\l_finalize.obj" \
	"$(INTDIR)\l_gather.obj" \
	"$(INTDIR)\l_gather_list.obj" \
	"$(INTDIR)\l_go_debug.obj" \
	"$(INTDIR)\l_group.obj" \
	"$(INTDIR)\l_init.obj" \
	"$(INTDIR)\l_initialized.obj" \
	"$(INTDIR)\l_misc.obj" \
	"$(INTDIR)\l_mr_async.obj" \
	"$(INTDIR)\l_mr_sync.obj" \
	"$(INTDIR)\l_mr_thread.obj" \
	"$(INTDIR)\l_multi_request.obj" \
	"$(INTDIR)\l_netid.obj" \
	"$(INTDIR)\l_netlnk.obj" \
	"$(INTDIR)\l_netman.obj" \
	"$(INTDIR)\l_node.obj" \
	"$(INTDIR)\l_nodecmd.obj" \
	"$(INTDIR)\l_nodedata.obj" \
	"$(INTDIR)\l_nodegrp.obj" \
	"$(INTDIR)\l_nodeheader.obj" \
	"$(INTDIR)\l_nodei.obj" \
	"$(INTDIR)\l_nodeinfo.obj" \
	"$(INTDIR)\l_nodeli.obj" \
	"$(INTDIR)\l_nodereq.obj" \
	"$(INTDIR)\l_nodes.obj" \
	"$(INTDIR)\l_ns.obj" \
	"$(INTDIR)\l_ns_params.obj" \
	"$(INTDIR)\l_ns_params_sb.obj" \
	"$(INTDIR)\l_nsi.obj" \
	"$(INTDIR)\l_params_mpi.obj" \
	"$(INTDIR)\l_params_xmp.obj" \
	"$(INTDIR)\l_recv.obj" \
	"$(INTDIR)\l_reduce.obj" \
	"$(INTDIR)\l_reduce_list.obj" \
	"$(INTDIR)\l_reduce_one.obj" \
	"$(INTDIR)\l_reduce_op.obj" \
	"$(INTDIR)\l_reqli.obj" \
	"$(INTDIR)\l_reqman.obj" \
	"$(INTDIR)\l_root.obj" \
	"$(INTDIR)\l_sb.obj" \
	"$(INTDIR)\l_sb_sock.obj" \
	"$(INTDIR)\l_scatter.obj" \
	"$(INTDIR)\l_scatter_list.obj" \
	"$(INTDIR)\l_send.obj" \
	"$(INTDIR)\l_sendrecv.obj" \
	"$(INTDIR)\l_single_request.obj" \
	"$(INTDIR)\l_snoopy.obj" \
	"$(INTDIR)\l_snoopy_accept.obj" \
	"$(INTDIR)\l_snoopy_ns.obj" \
	"$(INTDIR)\l_snoopy_ns_dump.obj" \
	"$(INTDIR)\l_snoopy_ns_trace.obj" \
	"$(INTDIR)\l_snoopy_recv.obj" \
	"$(INTDIR)\l_snoopy_send.obj" \
	"$(INTDIR)\l_society.obj" \
	"$(INTDIR)\l_stack_msg.obj" \
	"$(INTDIR)\l_string.obj" \
	"$(INTDIR)\l_time.obj" \
	"$(INTDIR)\l_trace_all.obj" \
	"$(INTDIR)\l_trace_msg.obj" \
	"$(INTDIR)\l_unknow.obj" \
	"$(INTDIR)\l_verbose_msg.obj" \
	"$(INTDIR)\node.obj" \
	"$(INTDIR)\params_mpi.obj" \
	"$(INTDIR)\params_xmp.obj" \
	"$(INTDIR)\v_alloc.obj" \
	"$(INTDIR)\v_dtd.obj" \
	"$(INTDIR)\v_file.obj" \
	"$(INTDIR)\v_process.obj" \
	"$(INTDIR)\v_socket.obj" \
	"$(INTDIR)\v_thread.obj" \
	"$(INTDIR)\v_zl.obj" \
	"$(INTDIR)\x_alloc.obj" \
	"$(INTDIR)\x_dtd.obj" \
	"$(INTDIR)\x_file.obj" \
	"$(INTDIR)\x_process.obj" \
	"$(INTDIR)\x_socket.obj" \
	"$(INTDIR)\x_string.obj" \
	"$(INTDIR)\x_thread.obj" \
	"$(INTDIR)\x_time.obj" \
	"$(INTDIR)\x_zl.obj"

"$(OUTDIR)\mplib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"

OUTDIR=.\.
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.
# End Custom Macros

ALL : "$(OUTDIR)\mplib.lib"


CLEAN :
	-@erase "$(INTDIR)\l_alloc.obj"
	-@erase "$(INTDIR)\l_authors.obj"
	-@erase "$(INTDIR)\l_barrier.obj"
	-@erase "$(INTDIR)\l_barrier_48h.obj"
	-@erase "$(INTDIR)\l_bcast.obj"
	-@erase "$(INTDIR)\l_bcast_chain.obj"
	-@erase "$(INTDIR)\l_bcast_list.obj"
	-@erase "$(INTDIR)\l_bcast_tree.obj"
	-@erase "$(INTDIR)\l_brow.obj"
	-@erase "$(INTDIR)\l_buffa.obj"
	-@erase "$(INTDIR)\l_comm.obj"
	-@erase "$(INTDIR)\l_condition_msg.obj"
	-@erase "$(INTDIR)\l_darray.obj"
	-@erase "$(INTDIR)\l_datatype.obj"
	-@erase "$(INTDIR)\l_datatype_byte.obj"
	-@erase "$(INTDIR)\l_datatype_char.obj"
	-@erase "$(INTDIR)\l_datatype_double.obj"
	-@erase "$(INTDIR)\l_datatype_float.obj"
	-@erase "$(INTDIR)\l_datatype_int.obj"
	-@erase "$(INTDIR)\l_datatype_long.obj"
	-@erase "$(INTDIR)\l_datatype_short.obj"
	-@erase "$(INTDIR)\l_debug.obj"
	-@erase "$(INTDIR)\l_debug_dfa.obj"
	-@erase "$(INTDIR)\l_debug_msg.obj"
	-@erase "$(INTDIR)\l_dhash.obj"
	-@erase "$(INTDIR)\l_do_creat.obj"
	-@erase "$(INTDIR)\l_do_default.obj"
	-@erase "$(INTDIR)\l_do_disc.obj"
	-@erase "$(INTDIR)\l_do_match.obj"
	-@erase "$(INTDIR)\l_do_open.obj"
	-@erase "$(INTDIR)\l_do_unlink.obj"
	-@erase "$(INTDIR)\l_dstack.obj"
	-@erase "$(INTDIR)\l_dump_all.obj"
	-@erase "$(INTDIR)\l_finalize.obj"
	-@erase "$(INTDIR)\l_gather.obj"
	-@erase "$(INTDIR)\l_gather_list.obj"
	-@erase "$(INTDIR)\l_go_debug.obj"
	-@erase "$(INTDIR)\l_group.obj"
	-@erase "$(INTDIR)\l_init.obj"
	-@erase "$(INTDIR)\l_initialized.obj"
	-@erase "$(INTDIR)\l_misc.obj"
	-@erase "$(INTDIR)\l_mr_async.obj"
	-@erase "$(INTDIR)\l_mr_sync.obj"
	-@erase "$(INTDIR)\l_mr_thread.obj"
	-@erase "$(INTDIR)\l_multi_request.obj"
	-@erase "$(INTDIR)\l_netid.obj"
	-@erase "$(INTDIR)\l_netlnk.obj"
	-@erase "$(INTDIR)\l_netman.obj"
	-@erase "$(INTDIR)\l_node.obj"
	-@erase "$(INTDIR)\l_nodecmd.obj"
	-@erase "$(INTDIR)\l_nodedata.obj"
	-@erase "$(INTDIR)\l_nodegrp.obj"
	-@erase "$(INTDIR)\l_nodeheader.obj"
	-@erase "$(INTDIR)\l_nodei.obj"
	-@erase "$(INTDIR)\l_nodeinfo.obj"
	-@erase "$(INTDIR)\l_nodeli.obj"
	-@erase "$(INTDIR)\l_nodereq.obj"
	-@erase "$(INTDIR)\l_nodes.obj"
	-@erase "$(INTDIR)\l_ns.obj"
	-@erase "$(INTDIR)\l_ns_params.obj"
	-@erase "$(INTDIR)\l_ns_params_sb.obj"
	-@erase "$(INTDIR)\l_nsi.obj"
	-@erase "$(INTDIR)\l_params_mpi.obj"
	-@erase "$(INTDIR)\l_params_xmp.obj"
	-@erase "$(INTDIR)\l_recv.obj"
	-@erase "$(INTDIR)\l_reduce.obj"
	-@erase "$(INTDIR)\l_reduce_list.obj"
	-@erase "$(INTDIR)\l_reduce_one.obj"
	-@erase "$(INTDIR)\l_reduce_op.obj"
	-@erase "$(INTDIR)\l_reqli.obj"
	-@erase "$(INTDIR)\l_reqman.obj"
	-@erase "$(INTDIR)\l_root.obj"
	-@erase "$(INTDIR)\l_sb.obj"
	-@erase "$(INTDIR)\l_sb_sock.obj"
	-@erase "$(INTDIR)\l_scatter.obj"
	-@erase "$(INTDIR)\l_scatter_list.obj"
	-@erase "$(INTDIR)\l_send.obj"
	-@erase "$(INTDIR)\l_sendrecv.obj"
	-@erase "$(INTDIR)\l_single_request.obj"
	-@erase "$(INTDIR)\l_snoopy.obj"
	-@erase "$(INTDIR)\l_snoopy_accept.obj"
	-@erase "$(INTDIR)\l_snoopy_ns.obj"
	-@erase "$(INTDIR)\l_snoopy_ns_dump.obj"
	-@erase "$(INTDIR)\l_snoopy_ns_trace.obj"
	-@erase "$(INTDIR)\l_snoopy_recv.obj"
	-@erase "$(INTDIR)\l_snoopy_send.obj"
	-@erase "$(INTDIR)\l_society.obj"
	-@erase "$(INTDIR)\l_stack_msg.obj"
	-@erase "$(INTDIR)\l_string.obj"
	-@erase "$(INTDIR)\l_time.obj"
	-@erase "$(INTDIR)\l_trace_all.obj"
	-@erase "$(INTDIR)\l_trace_msg.obj"
	-@erase "$(INTDIR)\l_unknow.obj"
	-@erase "$(INTDIR)\l_verbose_msg.obj"
	-@erase "$(INTDIR)\node.obj"
	-@erase "$(INTDIR)\params_mpi.obj"
	-@erase "$(INTDIR)\params_xmp.obj"
	-@erase "$(INTDIR)\v_alloc.obj"
	-@erase "$(INTDIR)\v_dtd.obj"
	-@erase "$(INTDIR)\v_file.obj"
	-@erase "$(INTDIR)\v_process.obj"
	-@erase "$(INTDIR)\v_socket.obj"
	-@erase "$(INTDIR)\v_thread.obj"
	-@erase "$(INTDIR)\v_zl.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\x_alloc.obj"
	-@erase "$(INTDIR)\x_dtd.obj"
	-@erase "$(INTDIR)\x_file.obj"
	-@erase "$(INTDIR)\x_process.obj"
	-@erase "$(INTDIR)\x_socket.obj"
	-@erase "$(INTDIR)\x_string.obj"
	-@erase "$(INTDIR)\x_thread.obj"
	-@erase "$(INTDIR)\x_time.obj"
	-@erase "$(INTDIR)\x_zl.obj"
	-@erase "$(OUTDIR)\mplib.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /I "..\include" /I "..\src" /D "_DEBUG" /D "__DEBUG__" /D "WIN32" /D "_MBCS" /D "_LIB" /D "HAVE_CONFIG_H" /D "HAVE_WINDOWS_H" /Fp"$(INTDIR)\mplib.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\mplib.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\mplib.lib" 
LIB32_OBJS= \
	"$(INTDIR)\l_alloc.obj" \
	"$(INTDIR)\l_authors.obj" \
	"$(INTDIR)\l_barrier.obj" \
	"$(INTDIR)\l_barrier_48h.obj" \
	"$(INTDIR)\l_bcast.obj" \
	"$(INTDIR)\l_bcast_chain.obj" \
	"$(INTDIR)\l_bcast_list.obj" \
	"$(INTDIR)\l_bcast_tree.obj" \
	"$(INTDIR)\l_brow.obj" \
	"$(INTDIR)\l_buffa.obj" \
	"$(INTDIR)\l_comm.obj" \
	"$(INTDIR)\l_condition_msg.obj" \
	"$(INTDIR)\l_darray.obj" \
	"$(INTDIR)\l_datatype.obj" \
	"$(INTDIR)\l_datatype_byte.obj" \
	"$(INTDIR)\l_datatype_char.obj" \
	"$(INTDIR)\l_datatype_double.obj" \
	"$(INTDIR)\l_datatype_float.obj" \
	"$(INTDIR)\l_datatype_int.obj" \
	"$(INTDIR)\l_datatype_long.obj" \
	"$(INTDIR)\l_datatype_short.obj" \
	"$(INTDIR)\l_debug.obj" \
	"$(INTDIR)\l_debug_dfa.obj" \
	"$(INTDIR)\l_debug_msg.obj" \
	"$(INTDIR)\l_dhash.obj" \
	"$(INTDIR)\l_do_creat.obj" \
	"$(INTDIR)\l_do_default.obj" \
	"$(INTDIR)\l_do_disc.obj" \
	"$(INTDIR)\l_do_match.obj" \
	"$(INTDIR)\l_do_open.obj" \
	"$(INTDIR)\l_do_unlink.obj" \
	"$(INTDIR)\l_dstack.obj" \
	"$(INTDIR)\l_dump_all.obj" \
	"$(INTDIR)\l_finalize.obj" \
	"$(INTDIR)\l_gather.obj" \
	"$(INTDIR)\l_gather_list.obj" \
	"$(INTDIR)\l_go_debug.obj" \
	"$(INTDIR)\l_group.obj" \
	"$(INTDIR)\l_init.obj" \
	"$(INTDIR)\l_initialized.obj" \
	"$(INTDIR)\l_misc.obj" \
	"$(INTDIR)\l_mr_async.obj" \
	"$(INTDIR)\l_mr_sync.obj" \
	"$(INTDIR)\l_mr_thread.obj" \
	"$(INTDIR)\l_multi_request.obj" \
	"$(INTDIR)\l_netid.obj" \
	"$(INTDIR)\l_netlnk.obj" \
	"$(INTDIR)\l_netman.obj" \
	"$(INTDIR)\l_node.obj" \
	"$(INTDIR)\l_nodecmd.obj" \
	"$(INTDIR)\l_nodedata.obj" \
	"$(INTDIR)\l_nodegrp.obj" \
	"$(INTDIR)\l_nodeheader.obj" \
	"$(INTDIR)\l_nodei.obj" \
	"$(INTDIR)\l_nodeinfo.obj" \
	"$(INTDIR)\l_nodeli.obj" \
	"$(INTDIR)\l_nodereq.obj" \
	"$(INTDIR)\l_nodes.obj" \
	"$(INTDIR)\l_ns.obj" \
	"$(INTDIR)\l_ns_params.obj" \
	"$(INTDIR)\l_ns_params_sb.obj" \
	"$(INTDIR)\l_nsi.obj" \
	"$(INTDIR)\l_params_mpi.obj" \
	"$(INTDIR)\l_params_xmp.obj" \
	"$(INTDIR)\l_recv.obj" \
	"$(INTDIR)\l_reduce.obj" \
	"$(INTDIR)\l_reduce_list.obj" \
	"$(INTDIR)\l_reduce_one.obj" \
	"$(INTDIR)\l_reduce_op.obj" \
	"$(INTDIR)\l_reqli.obj" \
	"$(INTDIR)\l_reqman.obj" \
	"$(INTDIR)\l_root.obj" \
	"$(INTDIR)\l_sb.obj" \
	"$(INTDIR)\l_sb_sock.obj" \
	"$(INTDIR)\l_scatter.obj" \
	"$(INTDIR)\l_scatter_list.obj" \
	"$(INTDIR)\l_send.obj" \
	"$(INTDIR)\l_sendrecv.obj" \
	"$(INTDIR)\l_single_request.obj" \
	"$(INTDIR)\l_snoopy.obj" \
	"$(INTDIR)\l_snoopy_accept.obj" \
	"$(INTDIR)\l_snoopy_ns.obj" \
	"$(INTDIR)\l_snoopy_ns_dump.obj" \
	"$(INTDIR)\l_snoopy_ns_trace.obj" \
	"$(INTDIR)\l_snoopy_recv.obj" \
	"$(INTDIR)\l_snoopy_send.obj" \
	"$(INTDIR)\l_society.obj" \
	"$(INTDIR)\l_stack_msg.obj" \
	"$(INTDIR)\l_string.obj" \
	"$(INTDIR)\l_time.obj" \
	"$(INTDIR)\l_trace_all.obj" \
	"$(INTDIR)\l_trace_msg.obj" \
	"$(INTDIR)\l_unknow.obj" \
	"$(INTDIR)\l_verbose_msg.obj" \
	"$(INTDIR)\node.obj" \
	"$(INTDIR)\params_mpi.obj" \
	"$(INTDIR)\params_xmp.obj" \
	"$(INTDIR)\v_alloc.obj" \
	"$(INTDIR)\v_dtd.obj" \
	"$(INTDIR)\v_file.obj" \
	"$(INTDIR)\v_process.obj" \
	"$(INTDIR)\v_socket.obj" \
	"$(INTDIR)\v_thread.obj" \
	"$(INTDIR)\v_zl.obj" \
	"$(INTDIR)\x_alloc.obj" \
	"$(INTDIR)\x_dtd.obj" \
	"$(INTDIR)\x_file.obj" \
	"$(INTDIR)\x_process.obj" \
	"$(INTDIR)\x_socket.obj" \
	"$(INTDIR)\x_string.obj" \
	"$(INTDIR)\x_thread.obj" \
	"$(INTDIR)\x_time.obj" \
	"$(INTDIR)\x_zl.obj"

"$(OUTDIR)\mplib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mplib.dep")
!INCLUDE "mplib.dep"
!ELSE 
!MESSAGE Warning: cannot find "mplib.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "mplib - Win32 Release" || "$(CFG)" == "mplib - Win32 Debug"
SOURCE=..\src\base\l_alloc\l_alloc.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_alloc.obj"	"$(INTDIR)\l_alloc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_alloc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_authors.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_authors.obj"	"$(INTDIR)\l_authors.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_authors.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_barrier.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_barrier.obj"	"$(INTDIR)\l_barrier.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_barrier.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_barrier\l_barrier_48h.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_barrier_48h.obj"	"$(INTDIR)\l_barrier_48h.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_barrier_48h.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_bcast.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_bcast.obj"	"$(INTDIR)\l_bcast.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_bcast.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_chain.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_bcast_chain.obj"	"$(INTDIR)\l_bcast_chain.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_bcast_chain.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_list.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_bcast_list.obj"	"$(INTDIR)\l_bcast_list.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_bcast_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_bcast\l_bcast_tree.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_bcast_tree.obj"	"$(INTDIR)\l_bcast_tree.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_bcast_tree.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_brow.obj"	"$(INTDIR)\l_brow.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_brow.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_adt\l_buffa.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_buffa.obj"	"$(INTDIR)\l_buffa.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_buffa.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_comm.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_comm.obj"	"$(INTDIR)\l_comm.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_comm.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\console\l_condition_msg.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_condition_msg.obj"	"$(INTDIR)\l_condition_msg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_condition_msg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_adt\l_darray.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_darray.obj"	"$(INTDIR)\l_darray.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_darray.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype.obj"	"$(INTDIR)\l_datatype.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_byte.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_byte.obj"	"$(INTDIR)\l_datatype_byte.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_byte.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_char.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_char.obj"	"$(INTDIR)\l_datatype_char.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_char.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_double.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_double.obj"	"$(INTDIR)\l_datatype_double.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_double.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_float.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_float.obj"	"$(INTDIR)\l_datatype_float.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_float.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_int.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_int.obj"	"$(INTDIR)\l_datatype_int.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_int.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_long.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_long.obj"	"$(INTDIR)\l_datatype_long.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_long.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_datatype\l_datatype_short.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_datatype_short.obj"	"$(INTDIR)\l_datatype_short.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_datatype_short.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_debug\l_debug.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_debug.obj"	"$(INTDIR)\l_debug.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_debug.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_debug\l_debug_dfa.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_debug_dfa.obj"	"$(INTDIR)\l_debug_dfa.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_debug_dfa.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_debug\l_debug_msg.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_debug_msg.obj"	"$(INTDIR)\l_debug_msg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_debug_msg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_adt\l_dhash.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_dhash.obj"	"$(INTDIR)\l_dhash.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_dhash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_creat.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_creat.obj"	"$(INTDIR)\l_do_creat.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_creat.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_default.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_default.obj"	"$(INTDIR)\l_do_default.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_default.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_disc.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_disc.obj"	"$(INTDIR)\l_do_disc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_disc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_match.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_match.obj"	"$(INTDIR)\l_do_match.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_match.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_open.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_open.obj"	"$(INTDIR)\l_do_open.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_open.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_do_unlink.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_do_unlink.obj"	"$(INTDIR)\l_do_unlink.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_do_unlink.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_adt\l_dstack.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_dstack.obj"	"$(INTDIR)\l_dstack.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_dstack.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_dump_all.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_dump_all.obj"	"$(INTDIR)\l_dump_all.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_dump_all.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_finalize.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_finalize.obj"	"$(INTDIR)\l_finalize.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_finalize.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_gather.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_gather.obj"	"$(INTDIR)\l_gather.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_gather.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_gather\l_gather_list.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_gather_list.obj"	"$(INTDIR)\l_gather_list.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_gather_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node\l_go_debug.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_go_debug.obj"	"$(INTDIR)\l_go_debug.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_go_debug.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_group.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_group.obj"	"$(INTDIR)\l_group.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_group.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_init.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_init.obj"	"$(INTDIR)\l_init.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_init.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_initialized.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_initialized.obj"	"$(INTDIR)\l_initialized.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_initialized.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_misc.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_misc.obj"	"$(INTDIR)\l_misc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_misc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_async.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_mr_async.obj"	"$(INTDIR)\l_mr_async.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_mr_async.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_sync.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_mr_sync.obj"	"$(INTDIR)\l_mr_sync.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_mr_sync.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request\l_mr_thread.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_mr_thread.obj"	"$(INTDIR)\l_mr_thread.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_mr_thread.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\l_multi_request.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_multi_request.obj"	"$(INTDIR)\l_multi_request.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_multi_request.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman\l_netid.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_netid.obj"	"$(INTDIR)\l_netid.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_netid.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman\l_netlnk.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_netlnk.obj"	"$(INTDIR)\l_netlnk.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_netlnk.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_netman.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_netman.obj"	"$(INTDIR)\l_netman.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_netman.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_node.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_node.obj"	"$(INTDIR)\l_node.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_node.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodecmd.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodecmd.obj"	"$(INTDIR)\l_nodecmd.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodecmd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei\l_nodedata.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodedata.obj"	"$(INTDIR)\l_nodedata.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodedata.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodegrp.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodegrp.obj"	"$(INTDIR)\l_nodegrp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodegrp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei\l_nodeheader.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodeheader.obj"	"$(INTDIR)\l_nodeheader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodeheader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_nodei.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodei.obj"	"$(INTDIR)\l_nodei.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodei.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodeinfo.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodeinfo.obj"	"$(INTDIR)\l_nodeinfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodeinfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_nodeli.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodeli.obj"	"$(INTDIR)\l_nodeli.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodeli.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodereq.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodereq.obj"	"$(INTDIR)\l_nodereq.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodereq.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nodes.obj"	"$(INTDIR)\l_nodes.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nodes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_ns.obj"	"$(INTDIR)\l_ns.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_ns.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_ns_params.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_ns_params.obj"	"$(INTDIR)\l_ns_params.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_ns_params.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_ns_params\l_ns_params_sb.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_ns_params_sb.obj"	"$(INTDIR)\l_ns_params_sb.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_ns_params_sb.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_nsi.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_nsi.obj"	"$(INTDIR)\l_nsi.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_nsi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_params_mpi.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_params_mpi.obj"	"$(INTDIR)\l_params_mpi.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_params_mpi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_params_xmp.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_params_xmp.obj"	"$(INTDIR)\l_params_xmp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_params_xmp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_recv.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_recv.obj"	"$(INTDIR)\l_recv.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_recv.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_reduce.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reduce.obj"	"$(INTDIR)\l_reduce.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reduce.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_list.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reduce_list.obj"	"$(INTDIR)\l_reduce_list.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reduce_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_one.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reduce_one.obj"	"$(INTDIR)\l_reduce_one.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reduce_one.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_reduce\l_reduce_op.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reduce_op.obj"	"$(INTDIR)\l_reduce_op.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reduce_op.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_reqman\l_reqli.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reqli.obj"	"$(INTDIR)\l_reqli.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reqli.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_reqman.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_reqman.obj"	"$(INTDIR)\l_reqman.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_reqman.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_root.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_root.obj"	"$(INTDIR)\l_root.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_root.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\base\l_sb.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_sb.obj"	"$(INTDIR)\l_sb.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_sb.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\base\l_sb_sock.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_sb_sock.obj"	"$(INTDIR)\l_sb_sock.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_sb_sock.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_scatter.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_scatter.obj"	"$(INTDIR)\l_scatter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_scatter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_scatter\l_scatter_list.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_scatter_list.obj"	"$(INTDIR)\l_scatter_list.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_scatter_list.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_send.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_send.obj"	"$(INTDIR)\l_send.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_send.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_sendrecv.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_sendrecv.obj"	"$(INTDIR)\l_sendrecv.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_sendrecv.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\l_single_request.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_single_request.obj"	"$(INTDIR)\l_single_request.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_single_request.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy.obj"	"$(INTDIR)\l_snoopy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_accept.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_accept.obj"	"$(INTDIR)\l_snoopy_accept.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_accept.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_ns.obj"	"$(INTDIR)\l_snoopy_ns.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_ns.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns\l_snoopy_ns_dump.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_ns_dump.obj"	"$(INTDIR)\l_snoopy_ns_dump.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_ns_dump.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_ns\l_snoopy_ns_trace.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_ns_trace.obj"	"$(INTDIR)\l_snoopy_ns_trace.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_ns_trace.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_recv.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_recv.obj"	"$(INTDIR)\l_snoopy_recv.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_recv.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\l_snoopy\l_snoopy_send.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_snoopy_send.obj"	"$(INTDIR)\l_snoopy_send.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_snoopy_send.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\l_society.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_society.obj"	"$(INTDIR)\l_society.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_society.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\console\l_stack_msg.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_stack_msg.obj"	"$(INTDIR)\l_stack_msg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_stack_msg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_string\l_string.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_string.obj"	"$(INTDIR)\l_string.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_string.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_time\l_time.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_time.obj"	"$(INTDIR)\l_time.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_trace_all.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_trace_all.obj"	"$(INTDIR)\l_trace_all.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_trace_all.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\console\l_trace_msg.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_trace_msg.obj"	"$(INTDIR)\l_trace_msg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_trace_msg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node_server\l_ns\l_brow\l_unknow.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_unknow.obj"	"$(INTDIR)\l_unknow.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_unknow.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\console\l_verbose_msg.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\l_verbose_msg.obj"	"$(INTDIR)\l_verbose_msg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\l_verbose_msg.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\base\node.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\node.obj"	"$(INTDIR)\node.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\node.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\mpi_xmp\map\params_mpi.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\params_mpi.obj"	"$(INTDIR)\params_mpi.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\params_mpi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\mp\xmp_tcp\map\node\l_nodes\params_xmp.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\params_xmp.obj"	"$(INTDIR)\params_xmp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\params_xmp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_alloc\v_alloc.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_alloc.obj"	"$(INTDIR)\v_alloc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_alloc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_string\v_dtd.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_dtd.obj"	"$(INTDIR)\v_dtd.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_dtd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_file\v_file.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_file.obj"	"$(INTDIR)\v_file.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_file.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_process\v_process.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_process.obj"	"$(INTDIR)\v_process.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_process.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\L_socket\v_socket.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_socket.obj"	"$(INTDIR)\v_socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_socket.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_thread\v_thread.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_thread.obj"	"$(INTDIR)\v_thread.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_thread.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_zlib\v_zl.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\v_zl.obj"	"$(INTDIR)\v_zl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\v_zl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_alloc\x_alloc.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_alloc.obj"	"$(INTDIR)\x_alloc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_alloc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_string\x_dtd.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_dtd.obj"	"$(INTDIR)\x_dtd.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_dtd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_file\x_file.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_file.obj"	"$(INTDIR)\x_file.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_file.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_process\x_process.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_process.obj"	"$(INTDIR)\x_process.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_process.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\L_socket\x_socket.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_socket.obj"	"$(INTDIR)\x_socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_socket.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_string\x_string.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_string.obj"	"$(INTDIR)\x_string.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_string.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_thread\x_thread.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_thread.obj"	"$(INTDIR)\x_thread.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_thread.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_time\x_time.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_time.obj"	"$(INTDIR)\x_time.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\src\base\l_zlib\x_zl.c

!IF  "$(CFG)" == "mplib - Win32 Release"


"$(INTDIR)\x_zl.obj"	"$(INTDIR)\x_zl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "mplib - Win32 Debug"


"$(INTDIR)\x_zl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

