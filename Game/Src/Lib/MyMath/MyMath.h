#include <DxLib.h>

class MyMath
{
public:
	//ベクトルや行列の計算処理をまとめたクラス
	static VECTOR VecCreate(VECTOR PosA, VECTOR PosB);//ベクトル作成
	static float VecLong(VECTOR PosA, VECTOR PosB);//ベクトルの長さ
	static VECTOR VecAdd(VECTOR vecA, VECTOR vecB);//ベクトルの足し算
	static VECTOR VecSubtract(VECTOR vecA, VECTOR vecB);//ベクトルの引き算
	static VECTOR VecScale(VECTOR vec, float scale);//ベクトルのスカラー倍
	static float VecDot(VECTOR vecA, VECTOR vecB);//ベクトルの内積
	static VECTOR VecCross(VECTOR vecA, VECTOR vecB);//ベクトルの外積
	static VECTOR VecNormalize(VECTOR vec);//ベクトルの正規化
	static void Matldentity(MATRIX* mp);//単位行列の取得
	static VECTOR Transform(MATRIX mat, VECTOR vec);//ベクトル×行列
	static float GetAngleY(VECTOR vec1, VECTOR vec2);//角度を取得(Y軸)
	static float GetAngleX(VECTOR vec1, VECTOR vec2);//角度を取得(X軸)
	static float GetAngleZ(VECTOR vec1, VECTOR vec2);//角度を取得(Z軸)
	static float MyAbsf(float i_fNum);//絶対値の取得

	static MATRIX GetIdentityMatrix();
	static MATRIX GetTranslateMatrix(float x, float y, float z);
	static MATRIX GetScaleMtrix(VECTOR SCALE);
	static MATRIX GetPitchMatrix(float Rad);
	static MATRIX GetYawMatrix(float Rad);
	static MATRIX GetRollMatrix(float Rad);
	static MATRIX MatAdd(MATRIX matA, MATRIX matB);
	static MATRIX MatScale(MATRIX matA, float scale);
	static MATRIX MatMult(MATRIX matA, MATRIX matB);
	static VECTOR MatTransform(MATRIX matA, VECTOR vec1);
	static MATRIX MatTranspose(MATRIX mat);
};