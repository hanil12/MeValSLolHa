

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
    result.pos = input.pos;
    result.color = input.color;
    
    return result;
}