#!/bin/sh

echo "the para is $1"

case $1 in
A)
 echo "we are in A select";;
B)
 echo "we are in B select";;
C)
 echo "we are in C select";;
D|E)
 echo "we are in D&E select";;
*)
 echo "we are in * select";;
esac

