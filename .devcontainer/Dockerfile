FROM mcr.microsoft.com/devcontainers/base:bookworm

ENV DEBIAN_FRONTEND=noninteractive \
    TERM=xterm

RUN echo "deb http://deb.debian.org/debian trixie main" | tee /etc/apt/sources.list.d/trixie.list > /dev/null

RUN apt-get update && \
    apt install -y \
    clangd clang-tidy clang-format lldb gcc
