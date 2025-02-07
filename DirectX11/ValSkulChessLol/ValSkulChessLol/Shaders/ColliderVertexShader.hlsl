
// 상수버퍼(constant Buffer)
cbuffer World : register(b0)
{
    matrix world;
}

cbuffer View : register(b1)
{
    matrix view;
}

cbuffer Projection : register(b2)
{
    matrix projection;
}

struct VertexInput
{
    float4 pos : POSITION;
};

struct PixelInput
{
    float4 pos : SV_POSITION;
};

// 정점마다 계산실행
PixelInput VS(VertexInput input)
{
    PixelInput result;
    result.pos = input.pos;
    result.pos = mul(result.pos, world);
    result.pos = mul(result.pos, view);
    result.pos = mul(result.pos, projection);
    
    return result;
}