cbuffer ColorBuffer : register(b0)
{
    float4 color_;
}

struct PixelInput
{
    float4 pos : SV_Position; // SystemValue
    float4 color : COLOR;
};

float4 PS(PixelInput input) : SV_TARGET
{
    return color_;
}