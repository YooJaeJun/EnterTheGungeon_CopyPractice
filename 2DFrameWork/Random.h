#pragma once
class Random
{
private:
    Random();

public:
    static Random& GetInstance()
    {
        static std::unique_ptr<Random> inst;
        if (!inst)
            inst = std::unique_ptr<Random>(new Random());
        return *inst;
    }

private:
    std::shared_ptr<default_random_engine> randomEngine;

public:
	~Random();
	// �޸� �ּ� �ּ� ���� 4����Ʈ. CPU�� 4����Ʈ�� �д´�.
	int Int(int min = 0, int max = 1);
	float Float(float min = 0.0f, float max = 1.0f);
};

