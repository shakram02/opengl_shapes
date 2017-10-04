 
# OpenGL Shapes

Basic skeleton for OpenGL on Manjaro(Arch), with CMake

To install dependencies

```
sudo pacman -S sdl2
sudo pacman -S glew
sudo pacman -S glm
```

Sources were created by following [this](https://www.youtube.com/playlist?list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh)
tutorial. 

To build the project after installing the dependencies

```
./compile_and_run.sh
```

or alternatively

```
mkdir build
cd build
cmake ..
make
./open_gl_display
```

