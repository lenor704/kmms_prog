@echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

set GAME_TYPE=Qt


set BUILD_FOLDER=build_%BUILD_SUFFIX%

set SOURCE_FOLDER=.

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% -DGAME_TYPE=%GAME_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

cd ..
