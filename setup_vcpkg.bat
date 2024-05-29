@echo off

:: vcpkg 설치
if not exist "vcpkg" (
    git clone https://github.com/microsoft/vcpkg.git
    .\vcpkg\bootstrap-vcpkg.bat
)

:: live555 의존성 설치
.\vcpkg\vcpkg install live555