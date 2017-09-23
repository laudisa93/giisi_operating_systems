#!/bin/bash
for ((i = 1 ; i <=5 ; i++))
do 
if test $i -eq 1
then
echo "Hola " $i "vez"
else
echo "Hola " $i "veces"
fi
done
