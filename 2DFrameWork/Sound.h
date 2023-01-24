#pragma once
// ���߿� ��������Ʈ �̺�Ʈ��...
class Sound
{
    struct SoundNode
    {
        FMOD::Sound* sound;        //����� ���� ������
        FMOD::Channel* channel;    //������� ä��
    };
    map<string, SoundNode*> SoundList;
    FMOD::System* system;

private:
    Sound();

public:
    static Sound& GetInstance()
    {
        static std::unique_ptr<Sound> inst;
        if (!inst)
            inst = std::unique_ptr<Sound>(new Sound());
        return *inst;
    }

public:
    ~Sound();
    //�������� ���� �߰� 
    bool AddSound(string File, string Key, bool loop = false);
    //�������� ���� ����
    bool DeleteSound(string Key);

    //�׸��� key�� �Ű������� �ΰ� ��� ����
    void Play(string Key);
    void Stop(string Key);
    //�Ͻ�����
    void Pause(string Key);
    //�Ͻ����� ����
    void Resume(string Key);

    void SetVolume(string Key, float scale);
    void SetMasterVolume();
    void Update();
};

