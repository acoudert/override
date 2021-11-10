#!/bin/bash

docker run --privileged -it --rm -v `pwd`/../../:/override gdb-peda
