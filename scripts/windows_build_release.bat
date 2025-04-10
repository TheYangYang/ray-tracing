@echo off
setlocal

set "BUILD_DIR=build"

cd /d "%~dp0.."

if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)
cd "%BUILD_DIR%"

echo Configuring project with CMake (Release mode)...
cmake -DCMAKE_BUILD_TYPE=Release ..

echo Building project...
cmake --build . --config Release

echo Build completed successfully.
pause

endlocal
