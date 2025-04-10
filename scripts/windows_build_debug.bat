@echo off
setlocal

set "BUILD_DIR=build"

cd /d "%~dp0.."

if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)

cd "%BUILD_DIR%"

echo Configuring project with CMake (Debug mode)...
cmake -DCMAKE_BUILD_TYPE=Debug ..

echo Building project...
cmake --build . --config Debug

echo Build completed successfully.
pause

endlocal
