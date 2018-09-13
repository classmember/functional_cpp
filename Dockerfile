#
# Ubuntu Dockerfile
#
# https://github.com/dockerfile/ubuntu
#

# Pull base image.
FROM ubuntu:16.04

# Install.
RUN \
  sed -i 's/# \(.*multiverse$\)/\1/g' /etc/apt/sources.list && \
  apt update && \
  apt -y upgrade && \
  apt install -y build-essential && \
  apt install -y software-properties-common && \
  apt install -y byobu curl git htop man unzip vim wget && \
  apt install -y clang cmake && \
  mkdir -p /usr/local/src && \
  rm -rf /var/lib/apt/lists/*

# Add files.
ADD ./* /usr/local/src/functional_cpp/

# Set environment variables.
ENV HOME /root

# Define working directory.
WORKDIR /usr/local/src/functional_cpp

# Compile.
RUN \
  cmake -H. -Bbuild && \
  cmake --build build -- -j3

# Define default command.
CMD ["/usr/local/src/functional_cpp/bin/hello"]
