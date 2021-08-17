FROM gcc
USER root
WORKDIR /usr/work

RUN apt-get update -y &&\
    apt-get upgrade -y &&\
    apt-get install valgrind -y &&\
    apt-get clean &&\
    rm -rf /var/lib/apt/lists/*