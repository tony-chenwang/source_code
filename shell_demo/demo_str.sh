#!/bin/bash

echo "shell str demo BUILD_DATE:$(date)"

stra="This is tony demo"
strb="tony"
strc="atom"

# be care of this is must use bash as shell or it will fail
if [[ $stra == *$strb* ]]
then
  echo "stra include strb"
else
  echo "stra not include strb"
fi

# must be care of * is at out "" 
if [[ $stra == *"tony"* ]];then
 echo "stra include strb"
else
 echo "stra not include strb"
fi

if [[ $stra =~ $strb ]]
then
 echo "stra include strb"
else
 echo "stra not include strb"
fi

result=$(echo $stra | grep "${strb}")

if [[ $result != "" ]]
then
 echo "stra include strb"
else
 echo "stra not include strb"
fi











