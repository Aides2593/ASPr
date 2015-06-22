
// ASProjDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ASProj.h"
#include "ASProjDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//define const
#define TOPX 20
#define TOPY 20
#define BOTTOMX 1000
#define BOTTOMY 500
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CASProjDlg dialog



CASProjDlg::CASProjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CASProjDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CASProjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CASProjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CASProjDlg message handlers

BOOL CASProjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CASProjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CASProjDlg::OnPaint()
{
	CPaintDC dc(this);

	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(20, 20, 1000, 500);
	for (int i = 40; i < 1000; i += 20)
	{
		dc.MoveTo(i, 20);
		dc.LineTo(i, 500);
	}
	for (int i = 40; i < 500; i += 20)
	{
		dc.MoveTo(20, i);
		dc.LineTo(1000, i);
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CASProjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CASProjDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	this->SetWindowPos(NULL, 0, 0, 1200, 560, SWP_NOMOVE | SWP_NOZORDER);
	return 0;
}


void CASProjDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
// 	CRect crActiveRegion(20, 20, 1000, 500);
// 	InvalidateRect(&crActiveRegion, 1);
	POINT	ptCursor, ptFillRect;
	RECT	rcTest;
	CClientDC cpD(this);
	CDialogEx::OnLButtonDown(nFlags, point);
	GetCursorPos(&ptCursor);
	GetWindowRect(&rcTest);
	if (ptCursor.x > rcTest.left + 20 && ptCursor.x < rcTest.left + 1000 && ptCursor.y > rcTest.top + 40 && ptCursor.y < rcTest.top + 520)
	{
		ptFillRect.x = ((ptCursor.x - rcTest.left) / 20) * 20;
		ptFillRect.y = ((ptCursor.y - rcTest.top) / 20 - 1) * 20;
		cpD.SelectStockObject(BLACK_BRUSH);
		cpD.Rectangle(ptFillRect.x, ptFillRect.y, ptFillRect.x + 20, ptFillRect.y + 20);
		//UpdateWindow();
	}
}


void CASProjDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	POINT	ptCursor, ptFillRect;
	RECT	rcTest;
	CClientDC cpD(this);

	if (nFlags & MK_LBUTTON == MK_LBUTTON)
	{
		GetCursorPos(&ptCursor);
		GetWindowRect(&rcTest);
		if (ptCursor.x > rcTest.left + 20 && ptCursor.x < rcTest.left + 1000 && ptCursor.y > rcTest.top + 40 && ptCursor.y < rcTest.top + 520)
		{
			ptFillRect.x = ((ptCursor.x - rcTest.left) / 20) * 20;
			ptFillRect.y = ((ptCursor.y - rcTest.top) / 20 - 1) * 20;
			cpD.SelectStockObject(BLACK_BRUSH);
			cpD.Rectangle(ptFillRect.x, ptFillRect.y, ptFillRect.x + 20, ptFillRect.y + 20);
			//UpdateWindow();
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
