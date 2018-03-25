#!/bin/sh
#使用了 释伴 固定的使用方法

set -e  # 作用是如果命令执行失败 则会立即报错 防止错误像滚雪球那样 越滚越大

#判断BASH 的固定使用方法
if [ -x "$$BASH" ];then
echo $$BASH;
else
 if [ -x /bin/bash ];then #FILE exists and execute (or search) permission is granted
 echo /bin/bash
 else
 echo sh;
fi
fi

# 这种echo 的写法会自动换行
echo "This is the first line"
echo "This is the second line"

# 这种echo 的写法会停止换行
echo -n "This is the third line"
echo -n "This is the third line"


# 这种echo 的写法 会自动转义特殊的字符 比如：
# \n 自动换行
# \a 发出提示音
# \b 删除前面的一个字符
#
echo -e "This is the fourth line "
echo -e "This is the fifth line\nThis is the sixth line"
echo -e "This is the seventh line\aThis is the eighth line"


if [ $? -eq 0 ];then
echo "scripts excute success"
else
echo "scripts excute fail"
fi #end of if [ $?
