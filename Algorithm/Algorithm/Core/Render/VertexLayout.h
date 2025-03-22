#pragma once

struct Vertex
{
    XMFLOAT3 pos;
};

struct Vertex_Texture
{
    XMFLOAT3 pos;
    XMFLOAT2 uv;

    // ºû
    // Normal ¹ý¼±
};

struct Vertex_Color
{
    Vertex_Color() : pos(XMFLOAT3()) {}
    Vertex_Color(float x, float y) : pos(x, y, 0) {}

    XMFLOAT3 pos;
    XMFLOAT4 color = XMFLOAT4(1, 1, 1, 1);
};
