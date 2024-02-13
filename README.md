# Basic circle which is effected by gravity in SDL 

This program demonstrates a simple SDL-based application with a moving circle affected by gravity. The circle can be moved left and right, and it can jump when the space key is pressed.

## Dependencies

- SDL2
- SDL2_gfx

## Building and Running

### Prerequisites

Make sure you have SDL2 and SDL2_gfx installed on your system.

#### Ubuntu

```bash
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-gfx-dev
```

#### Build
```bash
 g++ main.cpp physics.cpp enemy/Enemy.cpp -o main -lSDL2 -lSDL2_gfx
 ```
