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
echo "	 Change c/Word"
echo "	---------------"
echo ""
echo "	$0 CHANGE_FROM CHANGE_TO"
echo ""
if [ 1 -gt $# ] ; then
   echo "	--- STOP (no params) ---"
   exit 1
fi

# ... Accept Params
echo "	Press ANY key show params..."
read PAUSE
echo "	RABBIT_TO_USE=$1"
echo "	CHANGE_TO_DO=s/$1/$2/g"
echo ""

# ... Accept Target
echo "	Press ANY key to search TARGETS..."
read PAUSE
RABBIT_TO_USE=$1
CHANGE_TO_DO="s/$1/$2/g"
LIST_SRC=`find . -name "*.[chm]" -print`
LIST_TARGET=`grep -l $RABBIT_TO_USE $LIST_SRC`
echo "	LIST_TARGET=$LIST_TARGET"
echo ""

# ... Accept Update
echo "	Press ANY key to update files..."
read PAUSE
for CURRET_FILE in $LIST_TARGET ; do
  sed $CHANGE_TO_DO $CURRET_FILE > chg.$$
  if [ $? -eq 0 ]; then
     mv chg.$$ $CURRET_FILE
  fi
  echo -n "."
done
echo ""
echo ""

echo "	--- STOP (done) ---"
