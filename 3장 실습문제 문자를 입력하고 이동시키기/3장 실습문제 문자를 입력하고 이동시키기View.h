
// 3장 실습문제 문자를 입력하고 이동시키기View.h: CMy3장실습문제문자를입력하고이동시키기View 클래스의 인터페이스
//

#pragma once


class CMy3장실습문제문자를입력하고이동시키기View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy3장실습문제문자를입력하고이동시키기View() noexcept;
	DECLARE_DYNCREATE(CMy3장실습문제문자를입력하고이동시키기View)

// 특성입니다.
public:
	CMy3장실습문제문자를입력하고이동시키기Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy3장실습문제문자를입력하고이동시키기View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutput;
	CPoint m_ptLocation;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_ptClientSIze;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	bool m_bDrag;
	afx_msg void OnMove(int x, int y);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3장 실습문제 문자를 입력하고 이동시키기View.cpp의 디버그 버전
inline CMy3장실습문제문자를입력하고이동시키기Doc* CMy3장실습문제문자를입력하고이동시키기View::GetDocument() const
   { return reinterpret_cast<CMy3장실습문제문자를입력하고이동시키기Doc*>(m_pDocument); }
#endif

