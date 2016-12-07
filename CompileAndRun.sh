#!/bin/bash
clear
gcc -O3 ./Kos.c  view/* model/* controller/* tests/* -O3 -o Kos
if [ $? -ne 0 ]; then
    echo "Fordítás sikertelen!";
else
    echo "Fordítás sikeres!";
    read -n1 -r -p "Üss szóközt a futtatáshoz vagy t -t a tesztek futtatásért:" key;
    echo $key + ";";
    if [ "$key" != "t" ]; then
        ./Kos
    else
        ./Kos -t
    fi
fi