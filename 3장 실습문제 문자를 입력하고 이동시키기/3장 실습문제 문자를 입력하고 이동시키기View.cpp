
// 3장 실습문제 문자를 입력하고 이동시키기View.cpp: CMy3장실습문제문자를입력하고이동시키기View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "3장 실습문제 문자를 입력하고 이동시키기.h"
#endif

#include "3장 실습문제 문자를 입력하고 이동시키기Doc.h"
#include "3장 실습문제 문자를 입력하고 이동시키기View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3장실습문제문자를입력하고이동시키기View

IMPLEMENT_DYNCREATE(CMy3장실습문제문자를입력하고이동시키기View, CView)

BEGIN_MESSAGE_MAP(CMy3장실습문제문자를입력하고이동시키기View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy3장실습문제문자를입력하고이동시키기View 생성/소멸

CMy3장실습문제문자를입력하고이동시키기View::CMy3장실습문제문자를입력하고이동시키기View() noexcept
{
	m_strOutput.Format(_T(""));
	m_ptLocation = (0, 0);
	m_bDrag = TRUE;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy3장실습문제문자를입력하고이동시키기View::~CMy3장실습문제문자를입력하고이동시키기View()
{
}

BOOL CMy3장실습문제문자를입력하고이동시키기View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy3장실습문제문자를입력하고이동시키기View 그리기

void CMy3장실습문제문자를입력하고이동시키기View::OnDraw(CDC* pDC)
{
	CMy3장실습문제문자를입력하고이동시키기Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);



	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy3장실습문제문자를입력하고이동시키기View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy3장실습문제문자를입력하고이동시키기View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy3장실습문제문자를입력하고이동시키기View 진단

#ifdef _DEBUG
void CMy3장실습문제문자를입력하고이동시키기View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3장실습문제문자를입력하고이동시키기View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3장실습문제문자를입력하고이동시키기Doc* CMy3장실습문제문자를입력하고이동시키기View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3장실습문제문자를입력하고이동시키기Doc)));
	return (CMy3장실습문제문자를입력하고이동시키기Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3장실습문제문자를입력하고이동시키기View 메시지 처리기


void CMy3장실습문제문자를입력하고이동시키기View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK)
	{
		m_strOutput.Delete(nCharIndex - 1, 1);

	}
	else
	{
		m_strOutput += (WCHAR)nChar;
	}
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy3장실습문제문자를입력하고이동시키기View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
	
		break;

	case VK_PRIOR:
		m_ptLocation.y -= 50;
		break;

	case VK_NEXT:
		m_ptLocation.y += 50;
		break;
	case VK_HOME:
		m_ptLocation = (0,0);
		break;
	}

	if (m_ptLocation.x < 0)
	{
		m_ptLocation.x = 0;
		AfxMessageBox(_T("왼쪽으로 더 이상 이동할 수 없습니다."));
	}
	if (m_ptLocation.y < 0)
	{
		m_ptLocation.y = 0;
		AfxMessageBox(_T("위쪽으로 더 이상 이동할 수 없습니다."));
	}
	if (m_ptLocation.x > m_ptClientSIze.x)
	{
		AfxMessageBox(_T("오른쪽으로 더 이상 이동할 수 없습니다."));

	}
	if (m_ptLocation.y > m_ptClientSIze.y)
	{
		AfxMessageBox(_T("아래쪽으로 더 이상 이동할 수 없습니다."));
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy3장실습문제문자를입력하고이동시키기View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_ptClientSIze.x = cx;
	m_ptClientSIze.y = cy;

	Invalidate();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy3장실습문제문자를입력하고이동시키기View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = false;
	m_ptLocation = point;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}




void CMy3장실습문제문자를입력하고이동시키기View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = true;
	CView::OnLButtonUp(nFlags, point);
}


void CMy3장실습문제문자를입력하고이동시키기View::OnMove(int x, int y)
{



	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy3장실습문제문자를입력하고이동시키기View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == false)
	{
		m_ptLocation = point;

	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
