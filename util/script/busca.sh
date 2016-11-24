#!/bin/sh
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


# ... Welcome
echo ""
echo "	 SearchSrc"
echo "	-----------"
echo ""
echo "	$0  TO_SEARCH  GREP_OPTIONS"
echo ""
if [ 1 -gt $# ] ; then
   echo "	--- STOP (no params) ---"
   exit 1
fi

# ... Accept Params
echo "	Press ANY key show params..."
read PAUSE
echo "	TO_SEARCH=$1"
echo "	GREP_OPTIONS=$2"
echo ""

# ... Accept Target
echo "	Press ANY key to search TARGETS..."
read PAUSE
TO_SEARCH=$1
GREP_OPTIONS=$2
LIST_SRC=`find . -name "*.[chm]" -print`
LIST_TARGET=`grep $GREP_OPTIONS $TO_SEARCH $LIST_SRC`
echo "	LIST_TARGET..."
echo "$LIST_TARGET"
echo ""
echo ""

echo "	--- STOP (done) ---"
