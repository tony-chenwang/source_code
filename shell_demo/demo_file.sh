#check file exsit
echo -n "enter a file name:"
dir=`pwd`
read file
if [ -e $dir/$file ];then
echo "the file is exist"
else
echo "the file is no exist"
fi
