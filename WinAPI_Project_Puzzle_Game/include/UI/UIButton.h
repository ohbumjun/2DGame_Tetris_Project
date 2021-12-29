#pragma once

#include "UIWidget.h"

class CUIButton : public CUIWidget {
public :
	CUIButton();
	CUIButton(const CUIButton& Button);
	~CUIButton();
private :
	EButton_State m_ButtonState;
	CSharedPtr<class CTexture> m_Texture;
	AnimationFrameData m_FrameData[(int)EButton_State::End];
	std::function<void()> m_ButtonClickCallback;
	std::function<void()> m_ButtonHoverCallback;
public :
	void SetTexture(class CTexture* const Texture);
	void SetTexture(const std::string& Name);
	void SetTexure(const std::string& Name, const std::vector<std::wstring> vecFileName, const std::string& PathName = TEXTURE_PATH);
	void SetTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
	void SetTextureFullPath(const std::string& Name, const TCHAR* FullPath);
	void SetTextureColorKey(unsigned char r, unsigned char g, unsigned char b, int Index = 0);
public :
	void Enable(bool Enable);
public :
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC, const Vector2& Pos);
	virtual void Render(HDC hDC);
	virtual CUIButton* Clone();
public:
	void CallMouseHoveredCallback(float DeltaTime);
	void CallMouseReleaseCallback(float DeltaTime);
public :
	template<typename T>
	void SetButtonClickCallback(T* Obj, void(T::*Func)())
{
		m_ButtonClickCallback = std::bind(Func, Obj);
}
	template<typename T>
	void SetButtonHoverCallback(T* Obj, void(T::* Func)())
	{
		m_ButtonHoverCallback = std::bind(Func, Obj);
	}
};