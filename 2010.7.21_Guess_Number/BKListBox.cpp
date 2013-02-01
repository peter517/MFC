// BKListBox.cpp : implementation file
//

#include "stdafx.h"
#include "Guess_Number.h"
#include "BKListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBKListBox
/*���ñ���ʧ����*/

CBKListBox::CBKListBox()
{
m_brHollow.CreateStockObject(HOLLOW_BRUSH);  // �������Ļ�ˢ
}

CBKListBox::~CBKListBox()
{
}

HBRUSH CBKListBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkMode(TRANSPARENT); // ���ñ���͸��ģʽ
	return m_brHollow;	  // ���ؿ��Ļ�ˢ
}

BOOL CBKListBox::OnEraseBkgnd(CDC* pDC) 
{
	RECT rc;
	GetClientRect(&rc);  // ��ȡ�б��ͻ�����
	int rcWidth = rc.right-rc.left;  // �б��ͻ�������
	int rcHeight = rc.bottom-rc.top;  // �б��ͻ�����߶�
	BITMAP bitmap;  // λͼ���
	m_Bitmap.GetBitmap(&bitmap);  // ����λͼ
	CDC dcMem;  // �ڴ��ͼ�豸
	dcMem.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dcMem.SelectObject(&m_Bitmap);
	// ���Ʊ���λͼ
	pDC->StretchBlt(0,0,rcWidth,rcHeight,&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	dcMem.SelectObject(pOldBitmap);	
	return CListBox::OnEraseBkgnd(pDC);
}

void CBKListBox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	Invalidate();
	CListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CBKListBox::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	Invalidate();	
	CListBox::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBKListBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Invalidate();	
	CListBox::OnLButtonDown(nFlags, point);
}

void CBKListBox::OnSelchange() 
{
	Invalidate();	
}

BEGIN_MESSAGE_MAP(CBKListBox, CListBox)
	//{{AFX_MSG_MAP(CBKListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBKListBox message handlers
