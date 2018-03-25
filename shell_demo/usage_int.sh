#!/bin/sh

val1=700 
val2=500

#get the val of val1 + val2
#val3=`expr $val1 + $val2`

val3=$(expr $val1 + $val2)  #$() 与 `` 的作用是一致的 但是更容易被接受
echo "the sum is val3 = $val3"

val3=$(expr $val1 - $val2) #
echo "the sum is val3 = $val3"

val3=$(expr $val1 \* $val2)  # 注意乘号的使用需要转义
echo "the sum is val3 = $val3"

val3=$(expr $val1 % $val2)  # 取余运算符
echo "the sum is val3 = $val3"

val4=$(expr $val1 + 111)  # 取余运算符
echo "the sum is val3 = $val4"



if [ $val1 = $val2 ];then
echo "val1 & val2 is equal"
elif [ $val1 -gt $val2 ];then
echo "val1 > val2"
elif [ $val1 -lt $val2 ];then
echo "val1 < val2"
else
echo "would not run at this "
fi

if [ $val1 -eq $val2 ];then
echo "val1 & val2 is equal"
elif [ $val1 -gt $val2 ];then
echo "val1 > val2"
elif [ $val1 -lt $val2 ];then
echo "val1 < val2"
else
echo "would not run at this "
fi




