float4 VS(float4 pos : POSITION) : SV_POSITION
{
    return pos;
}

// SV : System Value
// TARGET : ±×¸± °÷
float4 PS() : SV_TARGET
{
    return float4(1.0f, 1.0f, 1.0f, 1.0f);
}