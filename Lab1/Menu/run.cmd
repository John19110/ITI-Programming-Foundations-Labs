@echo off
cd /d "%~dp0"
g++ -std=c++17 -I include src/Main.cpp src/Menu.cpp src/Employee.cpp src/Color.cpp -o Menu.exe
if errorlevel 1 exit /b 1
start "Menu" cmd /k Menu.exe
