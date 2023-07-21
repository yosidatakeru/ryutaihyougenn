#include <Novice.h>
#include"ImGuiManager.h"
const char kWindowTitle[] = "LE2B_ヨシダ_タケル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	float inputFloat4[4] = { 0,0,0,0 };
	float inputFloat = 0;
    //心拍による血液の循環量 
	float blood = 60.0f;
	
	//一秒あたりの心拍数
	float HeartRate=2.0f;
	//流血量
	float flowRateBlopd = 0.0f;
	//断面積(血管の太さ)
	float bloodVessel = 3.0f;
	//出血速度
	float bloodSpeed = 0.0f;
	//重力
	float gravity = 9.8f;
	
	//落ちる高さ
	float heightFromGround = 1.6f;
	////落下時間
	//float bloodDropTime = 0.0f;

	//落下した場所
	float bloodDistance = 0.0f;
	
	
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///		
		
		blood = inputFloat4[0];
		HeartRate = inputFloat4[1];
		bloodVessel = inputFloat4[2];
		heightFromGround = inputFloat4[3];
		
             //流血量
		     flowRateBlopd = blood * HeartRate;
			 //流速１秒間に訳４０ｃｍ／ｓ
			 bloodSpeed = flowRateBlopd / bloodVessel;
			 //センチからメートル
			 bloodSpeed/=100;

			 bloodDistance = (2 * heightFromGround / gravity)* (2 * heightFromGround / gravity);
			 bloodDistance *= bloodSpeed;
		     
			 ImGui::Begin("blood");
			 ImGui::Text("blood,HeartRate,bloodVessel,heightFromGround");
			 ImGui::SliderFloat4("blood", inputFloat4, 0.0f, 200.0f);
			 ImGui::End();
			
			 Novice::ScreenPrintf(0, 10, " bloodSpeed%f", bloodSpeed);
			 Novice::ScreenPrintf(0, 25, " bloodDistance %f", bloodDistance);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		///
		/// 
		/// 
		/// 
		/// 
		/// 
		/// 
		/// 
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
