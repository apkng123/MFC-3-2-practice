﻿
// 3장 실습문제 문자를 입력하고 이동시키기Doc.h: CMy3장실습문제문자를입력하고이동시키기Doc 클래스의 인터페이스
//


#pragma once


class CMy3장실습문제문자를입력하고이동시키기Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMy3장실습문제문자를입력하고이동시키기Doc() noexcept;
	DECLARE_DYNCREATE(CMy3장실습문제문자를입력하고이동시키기Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMy3장실습문제문자를입력하고이동시키기Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
