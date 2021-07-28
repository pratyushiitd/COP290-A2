# COP290-A2

2 Player maze game with SDL in C++ and sockets


## Installation

1. To install clone the repo and run `make all`
2. Debugging:
    1. To generate random maze `make maze`
    2. To eject the repo `make clean`
    3. To test build `make build`
    1. To run `make run`

Libraries:
* sdl2 `brew install sdl2`
* sdl2_image `brew install sdl2_image`
* sdl2_net `brew install sdl2_net`
* sdl2_ttf `brew install sdl2_ttf`


## Directory Structure
``` 
├── build                       # Compiled output
│   ├── main
│   ├── MAZE_152x122_n18000.bmp
│   ├── maze-generator
│   ├── maze-v
│   ├── maz-generator
│   └── win
├── makefile                    # Makefile for compilation
├── outputs                     # Intermediate outputs - maze
│   ├── matrix2.out
│   ├── matrix.out
│   ├── MAZE_20x20_n324.bmp
│   ├── MAZE_25x25_n529.bmp
│   └── MAZE_40x40_n1444.bmp
├── README.md
├── Resources                   # Resources - images, audio
│   ├── ButtonDark
│   │   ├── AngryBirds.bmp
│   │   ├── Avengers.bmp
│   │   ├── CS.bmp
│   │   └── HarryPotter.bmp
│   ├── ButtonLight
│   │   ├── AngryBirds.bmp
│   │   ├── Avengers.bmp
│   │   ├── CS.bmp
│   │   └── HarryPotter.bmp
│   ├── cherry.bmp
│   ├── Game
│   │   ├── Constants.hpp
│   │   ├── Game.hpp
│   │   ├── GameObject.hpp
│   │   ├── Map.hpp
│   │   ├── Movedirection.hpp
│   │   ├── TextureManager.hpp
│   │   ├── TileGraph.hpp
│   │   └── Tile.hpp
│   ├── LOR.bmp
│   ├── LOR.jpg
│   ├── PacMan.bmp
│   ├── player.bmp
│   ├── player.jpg
│   ├── Themes
│   │   ├── angrybird.bmp
│   │   ├── avengers.bmp
│   │   ├── csgo.bmp
│   │   ├── HarryPotter.bmp
│   │   └── LOR.bmp
│   └── tile.bmp
└── src                     # Code Logic
    ├── a.out
    ├── client.hpp
    ├── Game.cpp
    ├── GameObject.cpp
    ├── main.cpp
    ├── Map.cpp
    ├── maze-generator.cpp
    ├── server.hpp
    ├── TextureManager.cpp
    ├── Tile.cpp
    ├── TileGraph.cpp
    └── weapon.cpp
```

## TODO:

* [X] remove dependencies on outputs folder as there is no output and shift it to build
* [X] maze generation
* [X] maze movement and player logic - indexing issue
* [X] seperate "Resources" into "include" and "assets" and update code
* [ ] weapons
* [X] network transfer
* [ ] songs themes/decoration
* [X] different scenes for settings/menue - 1 player/ 2 player
* [X] create install script
* [X] update makefile
* [X] documentation for code
* [ ] ppt for presentation
