#/bin/csh
#
#   Copyright (C) 1996, 97, 98, 1999
#
# This file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
#


test $# -le 0
if ($status == 0) then
        echo "Use: $0 <process_name>" ;
        exit ;
endif


echo "killing..."

kill -9 `ps ax|grep $1|cut -f1 -d' '` &
kill -9 `ps ax|grep $1|cut -f2 -d' '` &
kill -9 `ps ax|grep $1|cut -f3 -d' '` &
kill -9 `ps ax|grep $1|cut -f4 -d' '` &
# procesos='ps ax |grep $1| awk {{ print $0 }}'
# echo $procesos
# foreach pidk ($procesos) do 
#     kill -9 $pidk ;
# end

echo "process killed."

