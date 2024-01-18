//������������������������������������������������������������������������������
 // �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D		g_texture : register(t0);	//�e�N�X�`���[
SamplerState	g_sampler : register(s0);	//�T���v���[

Texture2D		normalTex : register(t1);

//������������������������������������������������������������������������������
// �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer gmodel:register(b0)
{
	float4x4	matWVP;				// ���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
	float4x4	matW;				//���[���h�s��
	float4x4	matNormal;			// ���[���h�s��
	float4		diffuseColor;		//�}�e���A���̐F���g�U���ˌW��
	float4		ambientColor;		//����
	float4		specularColor;		//���ʔ��ˁ��n�C���C�g
	float		shininess;

	int			hasTexture;
	int		hasNormalMap;			//�e�N�X�`���[���\���Ă��邩�ǂ���
};

cbuffer gmodel:register(b1)
{
	float4		lightPosition;
	float4		eyePosition;
}

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
	float4 pos		: SV_POSITION;	//�ʒu
	float2 uv		: TEXCOORD;		//UV���W
	float4 color	: COLOR;		//�F�i���邳�j
	float4 eyev		: POSITION;		//���[���h���W�ɕϊ����ꂽ�����x�N�g��
	float4 Neyev	: POSITION1;	//�m�[�}���}�b�v�p�̐ڋ�Ԃɕϊ����ꂽ�����x�N�g��
	float4 normal	: POSITION2;	//
	float4 light	: POSITION3;	//
	float4 color	: POSITION4;	//
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL, float4 tangent : TANGENT)
{
	//�s�N�Z���V�F�[�_�[�֓n�����
	VS_OUT outData = (VS_OUT)0;

	//���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
	//�X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
	outData.pos = mul(pos, matWVP);	//mul()
	outData.uv = (float)uv;

	float3 binormal = cross(normal, tangent);

	normal.w = 0;
	normal = mul(normal, matNormal);
	normal = normalize(normal);
	outData.normal = normal;

	tangent.w = 0;
	tangent = mul(tangent, matNormal);
	tangent = normalize(tangent);

	binormal = mul(binormal, matNormal);
	binormal = normalize(binormal)

	float4 posw = mul(binormal, matNormal);
	outData.eyev = eyePosition - posw;

	outData.Neyev.x = dot(outData.eyev, tangent);
	outData.Neyev.y = dot(outData.eyev, tangent);
	outData.Neyev.z = dot(outData.eyev, tangent);
	outData.Neyev.z = 0;


	float4 light = normalize(lightPosition);
	light = normalize(light);

	//outData.color = saturate(dot(normal, light));
	//float4 posw = mul(pos, matW);
	//outData.eyev = eyePosition - posw;

	outData.color = mul(light, normal);

	outData.light.x = dot(light, tangent);
	outData.light.y = dot(light, tangent);
	outData.light.z = dot(light, tangent);
	outData.light.w = 0;



	//�܂Ƃ߂ďo��
	return outData;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
	float4 lightSource = float4(1.0, 1.0, 1.0, 0.0);	//���C�g�̐F�����邳 Iin
	//float4 ambentSource = float4(0.2, 0.2, 0.2, 1.0);	//�A���r�G���g�W��   Ka
	float4 diffuse;
	float4 ambient;
	float4 NL = dot(inData.normal, normalize(lightPosition));	//�@���Ɠ��ˌ��̓��p
	float4 reflect = normalize(2 * NL * inData.normal - normalize(lightPosition));	//���˃x�N�g��
	//float4 reflection = reflect(normalize(-lightPosition), inData.normal);

	float4 specular = pow(saturate(dot(reflect, normalize(inData.eyev))), shininess) * specularColor;



	/*float4 nk;
	if (inData.color.x < 1 / 3.0)
	{
		nk = float4(0.0, 0.0, 0.0, 0.0);
	}
	else if (inData.color.x < 2 / 3.0)
	{
		nk = float4(0.0, 0.0, 0.0, 0.0);
	}
	else
	{
		nk = float4(1.0, 1.0, 1.0, 1.0);
	}*/

	if (hasTexture == false)
	{
			diffuse = lightSource * diffuseColor * inData.color;
			ambient = lightSource * diffuseColor * ambientColor;
	}
	else
	{
		   diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
		   ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambientColor;
	}



	//return g_texture.Sample(g_sampler, inData.uv);// (diffuse + ambient);]
	//float4 diffuse = lightSource * inData.color;
	//float4 ambient = lightSource * ambentSource;

	return diffuse + ambient + specular;
	//return nk;

}