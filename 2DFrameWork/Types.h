#pragma once

struct Int2
{
	int x;
	int y;
	Int2() : x(0), y(0) {}
	Int2(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	const Int2 operator+(const Int2& dest) const
	{
		return Int2(x + dest.x, y + dest.y);
	}
	const Int2 operator-(const Int2& dest) const
	{
		return Int2(x - dest.x, y - dest.y);
	}
	const Int2 operator*(const Int2& dest) const
	{
		return Int2(x * dest.x, y * dest.y);
	}
	const Int2 operator/(const Int2& dest) const
	{
		return Int2(x / dest.x, y / dest.y);
	}

	const Int2 operator+(const int value) const
	{
		return Int2(x + value, y + value);
	}
	const Int2 operator-(const int value) const
	{
		return Int2(x - value, y - value);
	}
	const Int2 operator*(const int value) const
	{
		return Int2(x * value, y * value);
	}
	const Int2 operator/(const int value) const
	{
		return Int2(x / value, y / value);
	}

	bool operator==(const Int2 dest) const
	{
		return (x == dest.x && y == dest.y);
	}

	bool operator!=(const Int2 dest) const
	{
		return (x != dest.x || y != dest.y);
	}

	bool operator<(const Int2& other) const
	{
		return x < other.x || (!(other.x < x) && y < other.y);
	}
};

class Scene
{
public:
	virtual ~Scene() {};
	//초기화
	virtual void Init() = 0;
	//Loop
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;
	//Window Resize
	virtual void ResizeScreen() = 0;
};

class Application
{
	friend class Direct3D11;
	friend class Window;
	friend class Gui;

	//getter만 두고 접근가능
private:

	float		x, y;
	float		width;
	float		height;
	HINSTANCE	instance;
	HWND		handle;
	wstring		appName;
	bool		fullScreen;

public:
	bool		vSync;
	Color		background;
	int			fixFrame;
	float		deltaScale;
	float		soundScale;

public:
	Application() :instance(nullptr), handle(nullptr), vSync(false), fullScreen(false)
		, appName(L" "), width(1280.0f), height(720.0f), background(Color(0.7f, 0.7f, 0.7f, 1.0f))
		, fixFrame(200), deltaScale(1.0f), soundScale(1.0f), x(0.0f), y(0.0f) {}
	float	GetWidth() { return width; }
	float	GetHeight() { return height; }
	float	GetHalfWidth() { return width / 2.0f; }
	float	GetHalfHeight() { return height / 2.0f; }
	void	InitWidthHeight(float width, float height) { this->width = width; this->height = height; }

	void	SetInstance(HINSTANCE instance)
	{
		if (!this->instance)
			this->instance = instance;
	}
	void	SetAppName(wstring appName)
	{
		if (this->appName == L" ")
			this->appName = appName;
	}
	//해상도변경은 D3D의 리사이즈 함수 이용!
};