#!/bin/sh

res1=$(echo "ok" | ./reader -p test)
res2=$(./pipe2)

echo "${res1}"
echo "${res2}"

if [ "$res1" != "$res2" ]; then
    echo "Test failed, mismatching output" 1>&2
    exit 1
fi
