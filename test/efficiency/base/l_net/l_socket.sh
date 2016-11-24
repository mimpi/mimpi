#!/bin/sh
./server.exe 1048576 &
echo "sleep 1 seg..."
sleep 1
./client.exe 1048576

