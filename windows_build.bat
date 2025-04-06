@echo off
setlocal

:: Set the build directory
set "BUILD_DIR=build"

:: Navigate to the project directory
cd /d "%~dp0"

:: Create the build directory if it doesn't exist
if not exist "%BUILD_DIR%" (
    echo Creating build directory...
    mkdir "%BUILD_DIR%"
)

:: Navigate into the build directory
cd "%BUILD_DIR%"

:: Run CMake configuration
echo Configuring project with CMake...
cmake ..

:: Build the project
echo Building project...
cmake --build .

echo Build completed successfully.
pause

endlocal
