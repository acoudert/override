FROM	ubuntu:18.04
RUN	dpkg --add-architecture i386
RUN	apt -y update
RUN	apt install -y vim python3 python3-dev python3-pip libssl-dev libffi-dev gdb wget curl gcc make git libc6:i386 libncurses5:i386 libstdc++6:i386 ca-certificates patch pkg-config strace ltrace file upx-ucl netcat ruby-full --no-install-recommends python
RUN	git clone https://github.com/Mipu94/peda-heap.git ~/peda-heap
RUN	echo "source ~/peda-heap/peda.py" >> ~/.gdbinit
RUN echo 0 > /proc/sys/kernel/randomize_va_space
ENTRYPOINT bash
