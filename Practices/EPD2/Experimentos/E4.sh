#!/bin/bash
echo ¿Que te gusta mas EPD o EB o nada?
read clase

if test $clase = 'EPD'
then
echo Te gusta la $clase
elif test $clase = 'EB'
then
echo Te gusta la $clase
else
echo No te gusta nada
fi
