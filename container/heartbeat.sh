#!/bin/sh

interval=2
message="heartbeat"

while sleep ${interval}; do
    echo "${message}"
done
