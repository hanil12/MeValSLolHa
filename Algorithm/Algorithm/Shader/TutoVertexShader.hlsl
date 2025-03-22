
cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
};

cbuffer Projection : register(b2)
{
    matrix projection;
};

struct VertexInput
{
    float4 pos : POSITION;
    float4 color : COLOR;
};

struct VertexOutput
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};

VertexOutput VS(VertexInput input)
{
    VertexOutput result;
    input.pos = mul(input.pos, world);
    input.pos = mul(input.pos, view);
    input.pos = mul(input.pos, projection);
    result.color = input.color;
    result.pos = input.pos;
    
    return result;
}