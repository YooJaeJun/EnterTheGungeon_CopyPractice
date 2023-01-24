
struct VertexInput
{
	// GPU는 16바이트씩 읽는다. float 4바이트 * 4
    float4 position : POSITION0; //시멘틱 -> 용도
    float4 color : COLOR0;
};
// PI
struct PixelInput
{
    float4 position : SV_POSITION; //화면좌표계 포지션
    float4 color : COLOR0;
};

//오브젝트의 크기 회전 이동
cbuffer VS_WVP : register(b0) //register(b0)
{
    matrix WVP;
}
cbuffer VS_COLOR : register(b1)
{
    //4 개의 4바이트
    float4 color;
}

cbuffer PS_LIGHT : register(b0)
{
	float2 screenPos; //스크린좌표
	float radius; //반지름크기
	float select; //남는값
	float4 lightColor; //조명 색
	float4 outColor; //외곽 색
};

PixelInput VS(VertexInput input)
{
    //공간변환이 있을 예정인 곳
    PixelInput output;
    
    output.position = mul(input.position, WVP);
	// 그라데이션 효과를 위해 벡터에서 반 보다 작은 부분은 벡터를 더 작게, 다른 부분은 벡터를 더 크게
    output.color = input.color + (color * 2.0f - 1.0f);
	// saturate: 1보다 크면 1, 0보다 작으면 0, 사잇값은 그대로.
    saturate(output.color); 
    return output;
}

//->pixel  PS   ->color
//픽셀쉐이더 진입 함수
float4 PS(PixelInput input) : SV_TARGET //SV_TARGET 은 타겟이될 색깔 
{
	float4 outputColor;
	outputColor = saturate(input.color);
    
	float2 minus = input.position.xy - screenPos;
	float dis = minus.x * minus.x + minus.y * minus.y;
	dis = sqrt(dis);
    
	if (select == 0.0f)
	{
		if (dis > radius)
			outputColor.rgb += (outColor.rgb * 2.0f - 1.0f);
		else
			outputColor.rgb += (lightColor.rgb * 2.0f - 1.0f);
	}
	else
	{
		float temp = 1.0f - saturate(dis / radius);
		outputColor.rgb += (lightColor.rgb * 2.0f - 1.0f);
		outputColor.rgb *= temp;
	}

	outputColor = saturate(outputColor);
    
	return outputColor;
}