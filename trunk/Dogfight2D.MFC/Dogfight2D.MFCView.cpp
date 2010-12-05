
// Dogfight2D.MFCView.cpp : implementation of the CDogfight2DMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Dogfight2D.MFC.h"
#endif

#include "Dogfight2D.MFCDoc.h"
#include "Dogfight2D.MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDogfight2DMFCView

IMPLEMENT_DYNCREATE(CDogfight2DMFCView, CView)

BEGIN_MESSAGE_MAP(CDogfight2DMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDogfight2DMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDogfight2DMFCView construction/destruction

CDogfight2DMFCView::CDogfight2DMFCView()
{
	// TODO: add construction code here

}

CDogfight2DMFCView::~CDogfight2DMFCView()
{
}

BOOL CDogfight2DMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDogfight2DMFCView drawing

void CDogfight2DMFCView::OnDraw(CDC* /*pDC*/)
{
	CDogfight2DMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDogfight2DMFCView printing


void CDogfight2DMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDogfight2DMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDogfight2DMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDogfight2DMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDogfight2DMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDogfight2DMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDogfight2DMFCView diagnostics

#ifdef _DEBUG
void CDogfight2DMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CDogfight2DMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDogfight2DMFCDoc* CDogfight2DMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDogfight2DMFCDoc)));
	return (CDogfight2DMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDogfight2DMFCView message handlers
