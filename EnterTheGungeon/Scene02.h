#pragma once

namespace Gungeon
{
	const int enemyMax = 4;
	const int doorMax = 10;

	enum class GameState
	{
		// �� ���� ��ٸ��� ����
		start,
		waitingRoom,
		// ���� �ݺ��Ǵ� ����
		enteringRoom,
		waitingSpawn,
		fight
	};

	class Scene02 : public Scene
	{
	public:
		Scene02();
		~Scene02();

	protected:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void ResizeScreen() override;

	private:
		void Start();
		void WaitingRoom();
		void EnteringRoom();
		void WaitingSpawn();
		void Fight();
		void SetCamera();
		void SpawnPlayer();
		void SpawnEffect();
		void SpawnEnemy();
		void SpawnTreasureBox();
		void IntersectPlayer();
		void IntersectEnemy();
		void GateProcess();
		void ChangeUpdateScene();
		void ChangeScene1();
		void ChangeScene2();
		void ChangeScene3();
		void ColToggle();

	public:
		std::shared_ptr<ProcedureMapGeneration> mapGen = nullptr;
		std::shared_ptr<Player>					player = nullptr;

	private:
		std::shared_ptr<Room>					curRoom = nullptr;
		GameState								gameState = GameState::start;
		std::shared_ptr<Enemy>					enemy[enemyMax];
		bool									isChangingScene = false;
		float									timeFade = 0.0f;
		vector<std::shared_ptr<Effect>>			spawnEffect;
		int										afterRoomIdx = -2;
		int										curRoomIdx = 0;
		int										roomClearCount = 0;
		int										roomClearCountForBossBattle = 3;
		std::shared_ptr<Gate>					gate = nullptr;
		std::shared_ptr<Cinematic>				cinematic = nullptr;
		std::vector<std::shared_ptr<Door>>		door;
		std::shared_ptr<TreasureBox>			treasureBox = nullptr;
	};
}