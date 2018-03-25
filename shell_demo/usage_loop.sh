#!/bin/sh

i=0
sum=0

while [[ $i -le 100 ]];do
sum=$(expr $sum + $i)
i=$(expr $i + 1)
done

echo "the sum value 1~100 is $sum"


