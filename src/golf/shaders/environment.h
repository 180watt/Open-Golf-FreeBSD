#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Overview:

        Shader program 'environment':
            Get shader desc: environment_shader_desc()
            Vertex shader: environment_vs
                Attribute slots:
                    ATTR_environment_vs_position = 0
                    ATTR_environment_vs_texture_coord = 1
                    ATTR_environment_vs_lightmap_uv = 2
                Uniform block 'environment_vs_params':
                    C struct: environment_vs_params_t
                    Bind slot: SLOT_environment_vs_params = 0
            Fragment shader: environment_fs
                Uniform block 'environment_fs_params':
                    C struct: environment_fs_params_t
                    Bind slot: SLOT_environment_fs_params = 0
                Image 'environment_lightmap_tex':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_environment_lightmap_tex = 0
                Image 'environment_material_tex':
                    Type: SG_IMAGETYPE_2D
                    Component Type: SG_SAMPLERTYPE_FLOAT
                    Bind slot: SLOT_environment_material_tex = 1


    Shader descriptor structs:

        sg_shader environment = sg_make_shader(environment_shader_desc());

    Vertex attribute locations for vertex shader 'environment_vs':

        sg_pipeline pip = sg_make_pipeline(&(sg_pipeline_desc){
            .layout = {
                .attrs = {
                    [ATTR_environment_vs_position] = { ... },
                    [ATTR_environment_vs_texture_coord] = { ... },
                    [ATTR_environment_vs_lightmap_uv] = { ... },
                },
            },
            ...});

    Image bind slots, use as index in sg_bindings.vs_images[] or .fs_images[]

        SLOT_environment_lightmap_tex = 0;
        SLOT_environment_material_tex = 1;

    Bind slot and C-struct for uniform block 'environment_vs_params':

        environment_vs_params_t environment_vs_params = {
            .model_mat = ...;
            .proj_view_mat = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_environment_vs_params, &environment_vs_params, sizeof(environment_vs_params));

    Bind slot and C-struct for uniform block 'environment_fs_params':

        environment_fs_params_t environment_fs_params = {
            .ball_position = ...;
        };
        sg_apply_uniforms(SG_SHADERSTAGE_[VS|FS], SLOT_environment_fs_params, &environment_fs_params, sizeof(environment_fs_params));

*/
#include <stdint.h>
#include <stdbool.h>
#if !defined(SOKOL_SHDC_ALIGN)
  #if defined(_MSC_VER)
    #define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
  #else
    #define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
  #endif
#endif
#define ATTR_environment_vs_position (0)
#define ATTR_environment_vs_texture_coord (1)
#define ATTR_environment_vs_lightmap_uv (2)
#define SLOT_environment_lightmap_tex (0)
#define SLOT_environment_material_tex (1)
#define SLOT_environment_vs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct environment_vs_params_t {
    mat4 model_mat;
    mat4 proj_view_mat;
} environment_vs_params_t;
#pragma pack(pop)
#define SLOT_environment_fs_params (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct environment_fs_params_t {
    vec4 ball_position;
} environment_fs_params_t;
#pragma pack(pop)
#if defined(SOKOL_GLCORE33)
/*
    #version 330
    
    uniform vec4 environment_vs_params[8];
    out vec3 frag_position;
    layout(location = 0) in vec3 position;
    out vec2 frag_texture_coord;
    layout(location = 1) in vec2 texture_coord;
    out vec2 frag_lightmap_uv;
    layout(location = 2) in vec2 lightmap_uv;
    
    void main()
    {
        mat4 _20 = mat4(environment_vs_params[0], environment_vs_params[1], environment_vs_params[2], environment_vs_params[3]);
        vec4 _28 = vec4(position, 1.0);
        frag_position = (_20 * _28).xyz;
        frag_texture_coord = texture_coord;
        frag_lightmap_uv = lightmap_uv;
        gl_Position = (mat4(environment_vs_params[4], environment_vs_params[5], environment_vs_params[6], environment_vs_params[7]) * _20) * _28;
    }
    
*/
static const char environment_vs_source_glsl330[693] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x65,0x6e,0x76,0x69,0x72,
    0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x38,0x5d,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,0x20,0x66,0x72,
    0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x6c,0x61,0x79,
    0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,
    0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,
    0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,
    0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,
    0x20,0x3d,0x20,0x31,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x74,0x65,
    0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x6f,0x75,0x74,
    0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,0x74,
    0x6d,0x61,0x70,0x5f,0x75,0x76,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,
    0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x32,0x29,0x20,0x69,0x6e,0x20,
    0x76,0x65,0x63,0x32,0x20,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x75,0x76,
    0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x32,0x30,0x20,0x3d,0x20,
    0x6d,0x61,0x74,0x34,0x28,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,
    0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x65,
    0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,
    0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,
    0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x76,0x65,0x63,0x34,0x20,0x5f,0x32,0x38,0x20,0x3d,0x20,0x76,0x65,0x63,
    0x34,0x28,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x31,0x2e,0x30,0x29,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,
    0x69,0x6f,0x6e,0x20,0x3d,0x20,0x28,0x5f,0x32,0x30,0x20,0x2a,0x20,0x5f,0x32,0x38,
    0x29,0x2e,0x78,0x79,0x7a,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,
    0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x20,0x3d,0x20,
    0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,
    0x5f,0x75,0x76,0x20,0x3d,0x20,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x75,
    0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x20,0x3d,0x20,0x28,0x6d,0x61,0x74,0x34,0x28,0x65,0x6e,0x76,0x69,0x72,
    0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x34,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,
    0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x35,0x5d,0x2c,0x20,0x65,
    0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x73,0x5b,0x36,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,
    0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x37,
    0x5d,0x29,0x20,0x2a,0x20,0x5f,0x32,0x30,0x29,0x20,0x2a,0x20,0x5f,0x32,0x38,0x3b,
    0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 330
    
    uniform vec4 environment_fs_params[1];
    uniform sampler2D environment_lightmap_tex;
    uniform sampler2D environment_material_tex;
    
    in vec2 frag_lightmap_uv;
    in vec3 frag_position;
    in vec2 frag_texture_coord;
    layout(location = 0) out vec4 g_frag_color;
    
    void main()
    {
        float ao = texture(environment_lightmap_tex, frag_lightmap_uv).x;
        float _39 = distance(frag_position.xz, environment_fs_params[0].xz);
        bool _43 = _39 < 0.14000000059604644775390625;
        bool _54;
        if (_43)
        {
            _54 = frag_position.y < environment_fs_params[0].y;
        }
        else
        {
            _54 = _43;
        }
        if (_54)
        {
            float _60 = (0.14000000059604644775390625 - _39) * 7.142857074737548828125;
            ao -= ((_60 * _60) * 0.800000011920928955078125);
        }
        g_frag_color = vec4(texture(environment_material_tex, frag_texture_coord).xyz * ao, 1.0);
    }
    
*/
static const char environment_fs_source_glsl330[876] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x33,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x65,0x6e,0x76,0x69,0x72,
    0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,
    0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x73,0x61,0x6d,
    0x70,0x6c,0x65,0x72,0x32,0x44,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,
    0x6e,0x74,0x5f,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x74,0x65,0x78,0x3b,
    0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,
    0x32,0x44,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x6d,
    0x61,0x74,0x65,0x72,0x69,0x61,0x6c,0x5f,0x74,0x65,0x78,0x3b,0x0a,0x0a,0x69,0x6e,
    0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,0x74,
    0x6d,0x61,0x70,0x5f,0x75,0x76,0x3b,0x0a,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,
    0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x69,
    0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,
    0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,
    0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x67,0x5f,0x66,0x72,0x61,0x67,0x5f,
    0x63,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,
    0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,
    0x61,0x6f,0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x65,0x6e,0x76,
    0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,
    0x70,0x5f,0x74,0x65,0x78,0x2c,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,
    0x74,0x6d,0x61,0x70,0x5f,0x75,0x76,0x29,0x2e,0x78,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x33,0x39,0x20,0x3d,0x20,0x64,0x69,0x73,0x74,
    0x61,0x6e,0x63,0x65,0x28,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x2e,0x78,0x7a,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,
    0x6e,0x74,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2e,
    0x78,0x7a,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x34,
    0x33,0x20,0x3d,0x20,0x5f,0x33,0x39,0x20,0x3c,0x20,0x30,0x2e,0x31,0x34,0x30,0x30,
    0x30,0x30,0x30,0x30,0x30,0x35,0x39,0x36,0x30,0x34,0x36,0x34,0x34,0x37,0x37,0x35,
    0x33,0x39,0x30,0x36,0x32,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,
    0x20,0x5f,0x35,0x34,0x3b,0x0a,0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x34,
    0x33,0x29,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
    0x20,0x5f,0x35,0x34,0x20,0x3d,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,
    0x74,0x69,0x6f,0x6e,0x2e,0x79,0x20,0x3c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,
    0x6d,0x65,0x6e,0x74,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,
    0x5d,0x2e,0x79,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x65,
    0x6c,0x73,0x65,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,
    0x20,0x20,0x5f,0x35,0x34,0x20,0x3d,0x20,0x5f,0x34,0x33,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x69,0x66,0x20,0x28,0x5f,0x35,0x34,0x29,0x0a,
    0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x66,0x6c,
    0x6f,0x61,0x74,0x20,0x5f,0x36,0x30,0x20,0x3d,0x20,0x28,0x30,0x2e,0x31,0x34,0x30,
    0x30,0x30,0x30,0x30,0x30,0x30,0x35,0x39,0x36,0x30,0x34,0x36,0x34,0x34,0x37,0x37,
    0x35,0x33,0x39,0x30,0x36,0x32,0x35,0x20,0x2d,0x20,0x5f,0x33,0x39,0x29,0x20,0x2a,
    0x20,0x37,0x2e,0x31,0x34,0x32,0x38,0x35,0x37,0x30,0x37,0x34,0x37,0x33,0x37,0x35,
    0x34,0x38,0x38,0x32,0x38,0x31,0x32,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,
    0x20,0x20,0x61,0x6f,0x20,0x2d,0x3d,0x20,0x28,0x28,0x5f,0x36,0x30,0x20,0x2a,0x20,
    0x5f,0x36,0x30,0x29,0x20,0x2a,0x20,0x30,0x2e,0x38,0x30,0x30,0x30,0x30,0x30,0x30,
    0x31,0x31,0x39,0x32,0x30,0x39,0x32,0x38,0x39,0x35,0x35,0x30,0x37,0x38,0x31,0x32,
    0x35,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x67,0x5f,
    0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x76,0x65,0x63,
    0x34,0x28,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x65,0x6e,0x76,0x69,0x72,0x6f,
    0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x6d,0x61,0x74,0x65,0x72,0x69,0x61,0x6c,0x5f,0x74,
    0x65,0x78,0x2c,0x20,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,
    0x5f,0x63,0x6f,0x6f,0x72,0x64,0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x61,0x6f,
    0x2c,0x20,0x31,0x2e,0x30,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_GLCORE33 */
#if defined(SOKOL_GLES3)
/*
    #version 300 es
    
    uniform vec4 environment_vs_params[8];
    out vec3 frag_position;
    layout(location = 0) in vec3 position;
    out vec2 frag_texture_coord;
    layout(location = 1) in vec2 texture_coord;
    out vec2 frag_lightmap_uv;
    layout(location = 2) in vec2 lightmap_uv;
    
    void main()
    {
        mat4 _20 = mat4(environment_vs_params[0], environment_vs_params[1], environment_vs_params[2], environment_vs_params[3]);
        vec4 _28 = vec4(position, 1.0);
        frag_position = (_20 * _28).xyz;
        frag_texture_coord = texture_coord;
        frag_lightmap_uv = lightmap_uv;
        gl_Position = (mat4(environment_vs_params[4], environment_vs_params[5], environment_vs_params[6], environment_vs_params[7]) * _20) * _28;
    }
    
*/
static const char environment_vs_source_glsl300es[696] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x0a,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x65,0x6e,
    0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x38,0x5d,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x33,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,
    0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
    0x3d,0x20,0x30,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x33,0x20,0x70,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,0x20,
    0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,
    0x72,0x64,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,
    0x69,0x6f,0x6e,0x20,0x3d,0x20,0x31,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,
    0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,
    0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,
    0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x75,0x76,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x32,0x29,0x20,
    0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,
    0x5f,0x75,0x76,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,
    0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x74,0x34,0x20,0x5f,0x32,0x30,
    0x20,0x3d,0x20,0x6d,0x61,0x74,0x34,0x28,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,
    0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,
    0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,
    0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,
    0x73,0x5b,0x32,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,
    0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x3b,
    0x0a,0x20,0x20,0x20,0x20,0x76,0x65,0x63,0x34,0x20,0x5f,0x32,0x38,0x20,0x3d,0x20,
    0x76,0x65,0x63,0x34,0x28,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x31,
    0x2e,0x30,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x70,0x6f,
    0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x28,0x5f,0x32,0x30,0x20,0x2a,0x20,
    0x5f,0x32,0x38,0x29,0x2e,0x78,0x79,0x7a,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,
    0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,
    0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,0x74,
    0x6d,0x61,0x70,0x5f,0x75,0x76,0x20,0x3d,0x20,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,
    0x70,0x5f,0x75,0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x28,0x6d,0x61,0x74,0x34,0x28,0x65,0x6e,
    0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x34,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,
    0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x35,0x5d,
    0x2c,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x36,0x5d,0x2c,0x20,0x65,0x6e,0x76,0x69,
    0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,
    0x73,0x5b,0x37,0x5d,0x29,0x20,0x2a,0x20,0x5f,0x32,0x30,0x29,0x20,0x2a,0x20,0x5f,
    0x32,0x38,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #version 300 es
    precision mediump float;
    precision highp int;
    
    uniform highp vec4 environment_fs_params[1];
    uniform highp sampler2D environment_lightmap_tex;
    uniform highp sampler2D environment_material_tex;
    
    in highp vec2 frag_lightmap_uv;
    in highp vec3 frag_position;
    in highp vec2 frag_texture_coord;
    layout(location = 0) out highp vec4 g_frag_color;
    
    void main()
    {
        highp float ao = texture(environment_lightmap_tex, frag_lightmap_uv).x;
        highp float _39 = distance(frag_position.xz, environment_fs_params[0].xz);
        bool _43 = _39 < 0.14000000059604644775390625;
        bool _54;
        if (_43)
        {
            _54 = frag_position.y < environment_fs_params[0].y;
        }
        else
        {
            _54 = _43;
        }
        if (_54)
        {
            highp float _60 = (0.14000000059604644775390625 - _39) * 7.142857074737548828125;
            ao -= ((_60 * _60) * 0.800000011920928955078125);
        }
        g_frag_color = vec4(texture(environment_material_tex, frag_texture_coord).xyz * ao, 1.0);
    }
    
*/
static const char environment_fs_source_glsl300es[985] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x33,0x30,0x30,0x20,0x65,0x73,0x0a,
    0x70,0x72,0x65,0x63,0x69,0x73,0x69,0x6f,0x6e,0x20,0x6d,0x65,0x64,0x69,0x75,0x6d,
    0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x3b,0x0a,0x70,0x72,0x65,0x63,0x69,0x73,0x69,
    0x6f,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x69,0x6e,0x74,0x3b,0x0a,0x0a,0x75,
    0x6e,0x69,0x66,0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,
    0x34,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x66,0x73,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,0x69,0x66,
    0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,
    0x72,0x32,0x44,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,
    0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x74,0x65,0x78,0x3b,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x73,0x61,0x6d,0x70,
    0x6c,0x65,0x72,0x32,0x44,0x20,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,
    0x74,0x5f,0x6d,0x61,0x74,0x65,0x72,0x69,0x61,0x6c,0x5f,0x74,0x65,0x78,0x3b,0x0a,
    0x0a,0x69,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x32,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,0x68,0x74,0x6d,0x61,0x70,0x5f,0x75,0x76,0x3b,
    0x0a,0x69,0x6e,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x33,0x20,0x66,
    0x72,0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x69,0x6e,
    0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,0x61,0x67,
    0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,0x6f,0x72,0x64,0x3b,0x0a,
    0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,
    0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x76,
    0x65,0x63,0x34,0x20,0x67,0x5f,0x66,0x72,0x61,0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,
    0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x20,0x61,0x6f,0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x65,0x6e,
    0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x6c,0x69,0x67,0x68,0x74,0x6d,
    0x61,0x70,0x5f,0x74,0x65,0x78,0x2c,0x20,0x66,0x72,0x61,0x67,0x5f,0x6c,0x69,0x67,
    0x68,0x74,0x6d,0x61,0x70,0x5f,0x75,0x76,0x29,0x2e,0x78,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x5f,0x33,0x39,
    0x20,0x3d,0x20,0x64,0x69,0x73,0x74,0x61,0x6e,0x63,0x65,0x28,0x66,0x72,0x61,0x67,
    0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2e,0x78,0x7a,0x2c,0x20,0x65,0x6e,
    0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x66,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2e,0x78,0x7a,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x34,0x33,0x20,0x3d,0x20,0x5f,0x33,0x39,0x20,0x3c,
    0x20,0x30,0x2e,0x31,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x35,0x39,0x36,0x30,
    0x34,0x36,0x34,0x34,0x37,0x37,0x35,0x33,0x39,0x30,0x36,0x32,0x35,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x62,0x6f,0x6f,0x6c,0x20,0x5f,0x35,0x34,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x69,0x66,0x20,0x28,0x5f,0x34,0x33,0x29,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x35,0x34,0x20,0x3d,0x20,0x66,0x72,
    0x61,0x67,0x5f,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2e,0x79,0x20,0x3c,0x20,
    0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,0x6e,0x74,0x5f,0x66,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2e,0x79,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x7d,0x0a,0x20,0x20,0x20,0x20,0x65,0x6c,0x73,0x65,0x0a,0x20,0x20,0x20,0x20,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x35,0x34,0x20,0x3d,0x20,0x5f,
    0x34,0x33,0x3b,0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x69,0x66,
    0x20,0x28,0x5f,0x35,0x34,0x29,0x0a,0x20,0x20,0x20,0x20,0x7b,0x0a,0x20,0x20,0x20,
    0x20,0x20,0x20,0x20,0x20,0x68,0x69,0x67,0x68,0x70,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x20,0x5f,0x36,0x30,0x20,0x3d,0x20,0x28,0x30,0x2e,0x31,0x34,0x30,0x30,0x30,0x30,
    0x30,0x30,0x30,0x35,0x39,0x36,0x30,0x34,0x36,0x34,0x34,0x37,0x37,0x35,0x33,0x39,
    0x30,0x36,0x32,0x35,0x20,0x2d,0x20,0x5f,0x33,0x39,0x29,0x20,0x2a,0x20,0x37,0x2e,
    0x31,0x34,0x32,0x38,0x35,0x37,0x30,0x37,0x34,0x37,0x33,0x37,0x35,0x34,0x38,0x38,
    0x32,0x38,0x31,0x32,0x35,0x3b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x61,
    0x6f,0x20,0x2d,0x3d,0x20,0x28,0x28,0x5f,0x36,0x30,0x20,0x2a,0x20,0x5f,0x36,0x30,
    0x29,0x20,0x2a,0x20,0x30,0x2e,0x38,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x31,0x39,
    0x32,0x30,0x39,0x32,0x38,0x39,0x35,0x35,0x30,0x37,0x38,0x31,0x32,0x35,0x29,0x3b,
    0x0a,0x20,0x20,0x20,0x20,0x7d,0x0a,0x20,0x20,0x20,0x20,0x67,0x5f,0x66,0x72,0x61,
    0x67,0x5f,0x63,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x76,0x65,0x63,0x34,0x28,0x74,
    0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x65,0x6e,0x76,0x69,0x72,0x6f,0x6e,0x6d,0x65,
    0x6e,0x74,0x5f,0x6d,0x61,0x74,0x65,0x72,0x69,0x61,0x6c,0x5f,0x74,0x65,0x78,0x2c,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,0x63,0x6f,
    0x6f,0x72,0x64,0x29,0x2e,0x78,0x79,0x7a,0x20,0x2a,0x20,0x61,0x6f,0x2c,0x20,0x31,
    0x2e,0x30,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
#endif /* SOKOL_GLES3 */
#if !defined(SOKOL_GFX_INCLUDED)
  #error "Please include sokol_gfx.h before environment.h"
#endif
static inline const sg_shader_desc* environment_shader_desc(void) {
  #if defined(SOKOL_GLCORE33)
  if (sg_query_backend() == SG_BACKEND_GLCORE33) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "position";
      desc.attrs[1].name = "texture_coord";
      desc.attrs[2].name = "lightmap_uv";
      desc.vs.source = environment_vs_source_glsl330;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 128;
      desc.vs.uniform_blocks[0].uniforms[0].name = "environment_vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 8;
      desc.fs.source = environment_fs_source_glsl330;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "environment_fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.fs.images[0].name = "environment_lightmap_tex";
      desc.fs.images[0].type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.fs.images[1].name = "environment_material_tex";
      desc.fs.images[1].type = SG_IMAGETYPE_2D;
      desc.fs.images[1].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "environment_shader";
    };
    return &desc;
  }
  #endif /* SOKOL_GLCORE33 */
  #if defined(SOKOL_GLES3)
  if (sg_query_backend() == SG_BACKEND_GLES3) {
    static sg_shader_desc desc;
    static bool valid;
    if (!valid) {
      valid = true;
      desc.attrs[0].name = "position";
      desc.attrs[1].name = "texture_coord";
      desc.attrs[2].name = "lightmap_uv";
      desc.vs.source = environment_vs_source_glsl300es;
      desc.vs.entry = "main";
      desc.vs.uniform_blocks[0].size = 128;
      desc.vs.uniform_blocks[0].uniforms[0].name = "environment_vs_params";
      desc.vs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.vs.uniform_blocks[0].uniforms[0].array_count = 8;
      desc.fs.source = environment_fs_source_glsl300es;
      desc.fs.entry = "main";
      desc.fs.uniform_blocks[0].size = 16;
      desc.fs.uniform_blocks[0].uniforms[0].name = "environment_fs_params";
      desc.fs.uniform_blocks[0].uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
      desc.fs.uniform_blocks[0].uniforms[0].array_count = 1;
      desc.fs.images[0].name = "environment_lightmap_tex";
      desc.fs.images[0].type = SG_IMAGETYPE_2D;
      desc.fs.images[0].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.fs.images[1].name = "environment_material_tex";
      desc.fs.images[1].type = SG_IMAGETYPE_2D;
      desc.fs.images[1].sampler_type = SG_SAMPLERTYPE_FLOAT;
      desc.label = "environment_shader";
    };
    return &desc;
  }
  #endif /* SOKOL_GLES3 */
  return 0; /* can't happen */
}