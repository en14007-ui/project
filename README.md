# Simple Breakout (Arkanoid Clone) 🧱🎮

A **classic brick-breaker** with modern features — boss fights, power-ups, coins, smooth physics, and catchy audio — built from scratch in **C++** using **Raylib**.

![Gameplay](https://github.com/user-attachments/assets/33f008dd-f7c7-42d8-be92-f63f18835331)

[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://cplusplus.com/) [![Raylib](https://img.shields.io/badge/Raylib-v5.0-green.svg)](https://www.raylib.com/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Features

- Realistic paddle + ball physics with angle-based bounces
- 7 hand-crafted levels with increasing difficulty
- Final boss fight (moving boss with health bar)
- Power-ups dropping from bricks (big paddle mode implemented)
- Coin system — special blocks drop coins when destroyed
- Lives, score, and coin counters in HUD
- Pause menu (ESC key)
- Victory & Game Over screens with animated effects
- Background music + full sound design

## Screenshots

| Main Menu                  | Gameplay (Power-Up Drop)   | Boss Fight                 | Victory Screen             |
|----------------------------|----------------------------|----------------------------|----------------------------|
| ![Menu](https://github.com/user-attachments/assets/ef0cf924-d037-4771-98a0-322162dda7cb) | ![Gameplay](https://github.com/user-attachments/assets/33f008dd-f7c7-42d8-be92-f63f18835331) | ![Boss](https://github.com/user-attachments/assets/a7d517cb-d284-41b2-8fca-2e70a264c5b0) | ![Victory](https://github.com/user-attachments/assets/301f86a4-ab72-4d49-9d45-d97615182b7a) |

| Game Over (Lose Screen)    | Pause Menu (not uploaded yet) |

|----------------------------|-------------------------------|
| ![Lose](https://github.com/user-attachments/assets/ee46a0ee-59ec-4aa7-aa53-4d8408b92ac2) | ![Pause](<img width="1919" height="1010" alt="Снимок экрана 2026-02-07 162210" src="https://github.com/user-attachments/assets/ab706ec2-dc73-463f-a213-d1c6e88348d7" />) |

## Game Assets Showcase

### Textures (all pixel art, 64×64 or scaled)

| Normal Brick (wood)       | Coin Block                | Boss                      | Fireball Power-Up         | Background                |
|---------------------------|---------------------------|---------------------------|---------------------------|---------------------------|
| ![Wood](https://github.com/user-attachments/assets/43836744-1113-4ce9-82dc-93dc9031d695) | ![Coin](https://github.com/user-attachments/assets/2e542882-1bf5-4827-845c-32e05f07ffbd) | ![Boss](https://github.com/user-attachments/assets/0b53bfc8-46b2-45f4-9101-3695add4ed86) | ![Fireball](https://github.com/user-attachments/assets/7fad20ae-3f2a-441d-b5b0-f59ebae25f0c) | ![Background](https://github.com/user-attachments/assets/ba0db777-a012-4edd-88f3-309a08eb52b9) |

### Walls

![Wall](https://github.com/user-attachments/assets/6df31037-1871-4143-9675-f7cb83d35e68)

### Sounds (OGG/WAV, royalty-free)

- **Victory** — [Victory.wav](https://github.com/user-attachments/files/25151415/Victory.wav)  
- **Lose** — [lose.wav](https://github.com/user-attachments/files/25151419/lose.wav)  
- **Brick Destroyed / Coin** — [brick_destroyed.wav](https://github.com/user-attachments/files/25151425/brick_destroyed.wav)  
- **Background music** — [Background.mp3](https://github.com/user-attachments/files/25151618/Background.mp3)


### Controls

- **A / ←** — Move paddle left  
- **D / →** — Move paddle right  
- **SPACE** — Start game / restart after win or lose  
- **ESC** — Pause / resume

## Technologies

- **C++17** — modern syntax, RAII, smart resource handling
- **Raylib v5.0** — lightweight, cross-platform graphics/input/audio
- **CMake + vcpkg** — easy build & dependency management
- Custom collision system (grid + circle-rectangle)
- State machine (menu → playing → paused → victory → gameover)

## How to Build & Run

### Prerequisites
- CMake 3.20+
- C++17 compiler (MSVC, MinGW, Clang)
- vcpkg (for Raylib)

### Windows (CLion / CMake)
```bash
git clone https://github.com/yourusername/simple-breakout.git
cd simple-breakout
vcpkg install raylib
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=[vcpkg-root]/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
cd build
./breakout.exe


