#!/bin/bash

for i in {0..9}; do
#    a=$RANDOM
    ./ex2_1 $i > bash$i.txt &
done
wait