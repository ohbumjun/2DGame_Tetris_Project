#include "UIWidget.h"
#include "UIWindow.h"

CUIWidget::CUIWidget() :
m_Stage(nullptr),
m_Owner(nullptr),
m_Visibility(true),
m_ZOrder(0),
m_MouseHovered(false)
{}

CUIWidget::CUIWidget(const CUIWidget& Widget)
{
	*this = Widget;
	m_MouseHovered = false;
}

CUIWidget::~CUIWidget()
{}

bool CUIWidget::Init()
{
	return true;
}

void CUIWidget::Update(float DeltaTime)
{

}

void CUIWidget::PostUpdate(float DeltaTime)
{}

void CUIWidget::Render(HDC hDC)
{}

void CUIWidget::Render(HDC hDC, const Vector2& Pos)
{}

void CUIWidget::Collision(float DeltaTime, const Vector2& MousePos)
{
	if (m_Pos.x <= MousePos.x && MousePos.x < m_Pos.x + m_Size.x &&
		m_Pos.y <= MousePos.y && MousePos.y < m_Pos.y + m_Size.y)
	{
		if (!m_MouseHovered)
		{
			CallMouseHoveredCallback(DeltaTime);
		}
		m_MouseHovered = true;
	}
	else
	{
		if (m_MouseHovered)
			CallMouseReleaseCallback(DeltaTime);
		m_MouseHovered = false;
	}
}

void CUIWidget::CallMouseHoveredCallback(float DeltaTime)
{
	m_MouseHovered = true;
}

void CUIWidget::CallMouseReleaseCallback(float DeltaTime)
{
	m_MouseHovered = false;
}
