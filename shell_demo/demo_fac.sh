#!/bin/sh

fac=1

for a in `seq 1 10`
do
  fac=`expr $a \* $fac`
done

echo "10!=$fac"
