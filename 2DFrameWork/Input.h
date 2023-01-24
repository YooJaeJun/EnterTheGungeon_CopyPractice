#pragma once

class Input
{
    friend class Window;

private:
    Input();

public:
    static Input& GetInstance()
    {
        static std::unique_ptr<Input> inst;
        if (!inst)
            inst = std::unique_ptr<Input>(new Input());
        return *inst;
    }

public:
    ~Input();

    bool KeyDown(int KeyCode); //�������� ����1ȸ
    bool KeyPress(int KeyCode);//������������
    bool KeyUp(int KeyCode); //�����ٰ� �������� ����1ȸ
    void Update();

    Vector2 GetScreenMousePos() { return mouseScreenPos; }
    Vector2 GetWorldMousePos() { return mouseWorldPos; }

private:
    unsigned char keyState[256];
    unsigned char keyOldState[256];
    unsigned char keyMap[256];

    Vector2       mouseScreenPos;
    Vector2       mouseWorldPos;
    Vector2       mouseWorldPosZoom;
    bool          isZoom;

    enum
    {
        KEY_INPUT_STATUS_DOWN,
        KEY_INPUT_STATUS_PRESS,
        KEY_INPUT_STATUS_NONE,
        KEY_INPUT_STATUS_UP,
    };
};

