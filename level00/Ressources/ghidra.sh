#!/bin/bash

xhost +local:root
docker run -it --rm -v /tmp/.X11-unix:/tmp/.X11-unix -v `pwd`/../..:/override -e "DISPLAY=unix${DISPLAY}" blacktop/ghidra
xhost -local:root
