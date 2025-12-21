#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

#include "sprite.h"

inline Font menu_font;
inline Sound brick_destroyed_sound;
inline Sound Victory_sound;
inline Sound Boss_hit_sound;
inline Texture2D wall_texture;
inline Texture2D void_texture;
inline Texture2D paddle_texture;
inline Texture2D block_texture;
inline Texture2D boss_texture;
inline sprite ball_sprite;
inline Sound win_sound;
inline Sound lose_sound;
inline Texture2D background_texture;
inline Music background_music;
void load_fonts();
void unload_fonts();

void load_textures();
void unload_textures();

void load_sounds();
void unload_sounds();

#endif // ASSETS_H
