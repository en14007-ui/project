#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"
#include "raylib.h"
#include <cmath>
bool player_won = false;
bool ball_lost = false;



void restart();

static inline Rectangle px_rect_to_grid(const Vector2 px_pos, const Vector2 px_size)
{
    return Rectangle {
        (px_pos.x - shift_to_center.x) / cell_size,
        (px_pos.y - shift_to_center.y) / cell_size,
        px_size.x / cell_size,
        px_size.y / cell_size
    };
}

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

        if (lives <= 0) {
            state = gameover_state;
        } else {
            load_level(0);
        }
    } if (blocks_left == 0 && coins_left == 0) {


        if (current_level_index == level_count - 1 && boss.active) {
            return;
        }


        if (current_level_index + 1 < level_count) {
            load_level(1);
            PlaySound(win_sound);
            return;
        }
    }



    if (boss.active) {

        const float dt = GetFrameTime();
        float dx_total = boss.speed * (float)boss.direction * dt;

        const float max_step_px = cell_size * 0.25f;
        int steps = (int)std::ceil(std::fabs(dx_total) / (max_step_px > 1.0f ? max_step_px : 1.0f));
        if (steps < 1)
            steps = 1;
        float dx_step = dx_total / (float)steps;

        for (int i = 0; i < steps; ++i) {
            const Vector2 old_pos = boss.pos;
            Vector2 next_pos = boss.pos;
            next_pos.x += dx_step;

            if (next_pos.x <= 0.0f || next_pos.x + boss.width >= (float)GetScreenWidth()) {
                boss.direction *= -1;
                boss.speed += 20.0f;
                boss.pos = old_pos;
                break;
            }

            const Rectangle boss_grid_next = px_rect_to_grid(next_pos, { boss.width, boss.height });
            if (is_colliding_with_level_cell({ boss_grid_next.x, boss_grid_next.y }, { boss_grid_next.width, boss_grid_next.height }, WALL)) {
                boss.direction *= -1;
                boss.speed += 20.0f;
                boss.pos = old_pos;
                break;
            }

            boss.pos = next_pos;
        }

        const Rectangle boss_grid = px_rect_to_grid(boss.pos, { boss.width, boss.height });
        const Rectangle ball_grid = { ball_pos.x, ball_pos.y, ball_size.x, ball_size.y };

        if (boss.hit_cooldown > 0.0f)
            boss.hit_cooldown -= dt;

        if (boss.hit_cooldown <= 0.0f && CheckCollisionRecs(ball_grid, boss_grid)) {
            boss.health--;
            PlaySound(Boss_hit_sound);
            boss.hit_cooldown = 2.20f;

            ball_vel.y *= -1.1f;
            ball_vel.x += (ball_pos.x + ball_size.x * 0.5f - (boss_grid.x + boss_grid.width * 0.5f)) * 0.02f;

            ball_pos.y = boss_grid.y - ball_size.y - 0.01f;

            PlaySound(lose_sound);

            if (boss.health <= 0) {
                boss.active = false;
                state = victory_state;
                init_victory_menu();
                PlaySound(Victory_sound);
            }
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
        UpdateMusicStream(background_music);
        if (state == menu_state && IsKeyPressed(KEY_SPACE)) {
            load_level(0);
            state = in_game_state;
            PlayMusicStream(background_music);
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
        } else if (state == gameover_state) {
            draw_game_over_menu();

            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
                lives = 5;
                score = 0;
                load_level(0);
                state = in_game_state;
            }
        } else {
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
                lives = 5;
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
