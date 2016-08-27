#ifndef MDB_STRUCTS_H
#define MDB_STRUCTS_H

#include "../../include/SDL2/SDL.h"

#include "MDB_File.hpp"

struct MDB_Room
{
    uint32_t width;
    uint32_t height;

//Flags include such things as scroll direction and the speed of scroll
    uint32_t flags;
};

struct MDB_Image
{
    uint32_t img_size;
    uint32_t width;
    uint32_t height;
    char* img_slug;
    MDB_File* img_file;
    SDL_Texture* texture;
};

struct MDB_AnimationFile
{
    uint32_t frames;
//See enums in the 0x73XX range
    uint32_t animation_type;
    char* img_slug;
    uint32_t* frame_list;
    MDB_Image* connected_image;
};

struct MDB_TextureAnimationFile
{
    char* animation_slug;
    uint32_t no_textures;
    MDB_AnimationFile* animations;
};

struct MDB_Attack
{
    uint32_t damage;
    uint32_t speed;
    char* animation_slug;

    MDB_TextureAnimationFile* animations;
};

struct MDB_AttackChance
{
    MDB_Attack attack;
    float chance;
};

struct MDB_Actor
{
    uint32_t health;
//See MDB_E_ 0x72XX spaces
    uint32_t type;

    MDB_AttackChance* attacks;
};

struct MDB_DropChance
{
    float drop_chance;
    char* drop;
};

#endif