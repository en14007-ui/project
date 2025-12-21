#include "assets.h"

#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    wall_texture = LoadTexture("data/images/wall_2.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/wood.png");
    paddle_texture = LoadTexture("data/images/paddle.png");
    ball_sprite = load_sprite("data/images/fire_ball/fire_ball", ".png", 8, true, 10);
     boss_texture = LoadTexture("data/images/Boss.png");
    background_texture = LoadTexture("data/images/background01.png");

}

void unload_textures()
{
    UnloadTexture(background_texture);
    UnloadTexture(wall_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(paddle_texture);
    unload_sprite(ball_sprite);
    UnloadTexture(boss_texture);


}

void load_sounds()
{
    InitAudioDevice();
    win_sound = LoadSound("data/sounds/win.wav");
    lose_sound = LoadSound("data/sounds/lose.wav");
    brick_destroyed_sound = LoadSound("data/sounds/brick_destroyed.wav");
    Victory_sound = LoadSound("data/sounds/Victory.wav");
    Boss_hit_sound = LoadSound("data/sounds/Boss_hit.ogg");
}

void unload_sounds()
{
    UnloadSound(brick_destroyed_sound);
    UnloadSound(Victory_sound);
    UnloadSound(Boss_hit_sound);
    UnloadSound(win_sound);
    UnloadSound(lose_sound);
    CloseAudioDevice();
}
