#pragma once
// ���߿� ��������Ʈ �̺�Ʈ��...
class Timer
{
private:
    Timer();

public:
    static Timer& GetInstance()
    {
        static std::unique_ptr<Timer> inst;
        if (!inst)
            inst = std::unique_ptr<Timer>(new Timer());
        return *inst;
    }

private:
    chrono::steady_clock::time_point    currentTime;
    chrono::steady_clock::time_point    lastTime;
    UINT                                framePerSecond;
    UINT                                framePerSecondCount;
    float                               framePerSecondTimeElapsed;
    float                               deltaTime;
    float                               deltaScaleTime;
    float                               worldTime;
   
public:
    bool    GetTick(float& time, float interval);
    void    Chronometry(UINT lock = 60);
    float   GetDelta()          { return deltaTime; } //��ũ�� X
    float   GetDeltaTime()      { return deltaScaleTime; }
    UINT    GetFramePerSecond() { return framePerSecond; }
    float   GetWorldTime()      { return worldTime; }

    void Update();
};
