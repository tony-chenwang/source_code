#using for passwd
echo -n "login name:"    
read name
echo -n "passwd:"
read  passwd 

if [ $name = "tony.chen" -a $passwd = "tony.chen" ];then
echo "login success"
else
echo "login failed"
fi
