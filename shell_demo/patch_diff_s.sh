#!/bin/sh

date_time=`date +%m%d_%H_%M`
basedir=`pwd`



commitid=${1}                # para 1 commitid
commitid_s=${commitid:0:8}   # we only use 8 bit 

releasenote_path=${basedir}/"patch_${commitid_s}"/releasenote.txt

function usage_help
{
  cat <<EOF
  +--------------------------------------------------------------+
  +-------------------command [arg1]-----------------------------+
  +-------------------arg1 == commit id--------------------------+
EOF
}

function clean_all
{
    rm -rf patch_*[^sh]
    rm -rf *.tar
    echo -e "\033[31m clean file success \033[0m"
}

function make_diff
{
if [ $# != 1 ]; then
    echo -e "\033[31m make diff function error\033[0m"
    exit 1
fi

mkdir -p  "patch_$commitid_s"/"new"
mkdir -p  "patch_$commitid_s"/"old"

if [ $? -ne 0 ];then
    echo -e "\033[31m mkdir error\033[0m"
    return 1
fi

echo "releasetime:`date +%Y/%m/%d`   " > $releasenote_path
echo "releasepath:`pwd`   " >> $releasenote_path  
echo "git project:`git rev-parse --show-toplevel`   ">> $releasenote_path  
echo "commit id $commitid   " >> $releasenote_path  
echo "author:"$USER" in "$HOSTNAME"   " >> $releasenote_path  
    
git stash 

git reset --hard "$1"

echo  -e "Reset to commit id Current"

git diff-tree -r --no-commit-id --name-only $1 | xargs tar -rf "new_$date_time.tar"
	
git reset --hard HEAD^

git diff-tree -r --no-commit-id --name-only $1 | xargs tar -rf "old_$date_time.tar"
  
echo  -e "Reset to commit id Before"

if [ $? -eq 0 ];then
    echo -e "\033[31m Get Patch tar success\033[0m"
else
    echo -e "\033[31m Get Patch tar Fail\033[0m"
fi

mv   "new_$date_time.tar"  "patch_$commitid_s"/"new"
mv   "old_$date_time.tar"  "patch_$commitid_s"/"old"


cd  $basedir/"patch_$commitid_s"/"new";tar -xvf "new_$date_time.tar"
cd  $basedir/"patch_$commitid_s"/"old";tar -xvf "old_$date_time.tar"

if [ $? -eq 0 ];then
    echo -e "\033[31m Get Compare file Success\033[0m"
else
    echo -e "\033[31m Get Compare file fail\033[0m"
fi

rm -rf $basedir/"patch_$commitid_s"/"new"/"new_$date_time.tar"
rm -rf $basedir/"patch_$commitid_s"/"old"/"old_$date_time.tar"

git reset --hard $1

if [ $? -eq 0 ];then
    echo -e "\033[31mrecovery commit Success \033[0m"
else
    echo -e "\033[31mrecovery commit Fail\033[0m"
fi

}
if [ $# != 1 ]; then
    usage_help
    exit 1
fi

if [ -d ".git" ];then
  echo -e "Find git project       \033[31m [OK]  \033[0m"
else
  echo -e "Not git project dir Ex \033[31m [NOK]  \033[0m"
  exit 1
fi


case $1 in
    "clean")
    clean_all
    exit 0
    ;;
    "help")
    usage_help
    exit 0
    ;;
    *)
    make_diff $1
    exit 0
    ;;
esac
  