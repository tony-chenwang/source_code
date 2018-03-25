#!/bin/sh
DEBUG=TRUE
LOCATION="HuDongroad 99 Biaoli 19F YSTEN"
readonly LOCATION

if [ "$DEBUG" = "TRUE" ];
then
echo "LOCATION is $LOCATION"
fi

# LOCATION="YouYou shiji square SH PuDong"

# if [ "$DEBUG" = "TRUE" ];
# then
# echo "LOCATION is $LOCATION"
# fi

if [ "$DEBUG" = "TRUE" ];
then
echo "get env "
echo "path = $PATH"
echo "USER = $USER"
fi

# get shell para
echo "the number of para id $#"

echo "0th para is $0"   # 第一个参数 就是执行脚本名称
echo "1th para is $1" 
echo "2th para is $2" 
echo "3th para is $3" 

#单字符显示传递给脚本参数的内容
echo "using single string to show $@ "

#多字符显示传递给脚本参数的内容
echo "using multi string to show $* "


