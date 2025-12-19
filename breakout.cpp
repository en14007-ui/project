#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"

#include "raylib.h"
bool player_won = false;

void draw_pause_overlay()
{
    ClearBackground((Color) { 15, 18, 30, 255 });
    DrawRectangle(0, 0, 1280, 720, ColorAlpha(BLACK, 0.7f));
    DrawText("PAUSED", 420, 250, 100, YELLOW);
    DrawText("Press ESC to continue", 340, 380, 50, WHITE);
}
void restart();
void update()
{
    // TODO



    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        move_paddle(-paddle_speed);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        move_paddle(paddle_speed);
    }

    move_ball();
    if (!is_ball_inside_level()) {
        lives--;

        PlaySound(lose_sound);

        if (lives<=0) {
            state=gameover_state;
        }else {
            load_level(0);
        }
    }
    else if (current_level_blocks == 0) {
        if (current_level_index + 1 < level_count) {
            load_level(1);
            PlaySound(win_sound);
        }

        else {

            state=victory_state;
            init_victory_menu();

            PlaySound(win_sound);
        }

    }
}

void draw()
{
    // TODO

    draw_level();
    draw_paddle();
    draw_ball();
    draw_ui();
}

int main()
{

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1920, 1040, "Platformer");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_level();
    load_sounds();
    state = menu_state;
    while (!WindowShouldClose()) {

        if (state == menu_state && IsKeyPressed(KEY_SPACE)) {
            load_level(0);
            state = in_game_state;
        }

        if (state == in_game_state || state == paused_state) {
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = (state == in_game_state) ? paused_state : in_game_state;
            }
        }

        if (state == in_game_state) {
            update();
        }
        BeginDrawing();
        if (state == menu_state) {
            draw_menu();
        }else if (state==gameover_state) {
            draw_game_over_menu();
            if (IsKeyPressed(KEY_SPACE)||IsKeyPressed(KEY_ENTER))
            {
                lives=3;
                scores=0;
                load_level(0);
                state=in_game_state;

            }
        }
        else {
            ClearBackground(BLACK);
            if (state != paused_state) {
                draw();
            }

            if (state == paused_state) {
                draw_pause_menu();
            }
        }
        if (state == victory_state) {
            draw_victory_menu();
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {

                restart();
                state = in_game_state;
            }
        }

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}