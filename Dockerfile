# syntax=docker/dockerfile:1

# Use Ubuntu LTS (Long Term Support) release for a stable development environment
FROM ubuntu:24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        ninja-build \
        git \
    && rm -rf /var/lib/apt/lists/*

ARG USERNAME=dev

RUN useradd \
    --create-home \
    --shell /bin/bash \
    "${USERNAME}"

RUN mkdir -p /workspace/build-docker \
    && chown -R "${USERNAME}:${USERNAME}" /workspace

WORKDIR /workspace

USER ${USERNAME}