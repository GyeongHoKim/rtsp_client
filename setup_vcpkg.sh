#!/bin/bash

# vcpkg 설치
if [ ! -d "vcpkg" ]; then
  git clone https://github.com/microsoft/vcpkg.git
  ./vcpkg/bootstrap-vcpkg.sh
fi

# live555 의존성 설치
./vcpkg/vcpkg install live555