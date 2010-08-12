//
//  MiniBrowserController.h
//  TexLege
//

#import <UIKit/UIKit.h>


@interface MiniBrowserController : UIViewController <UIWebViewDelegate>
{
	IBOutlet UIToolbar *m_toolBar;
	IBOutlet UIWebView *m_webView;
	IBOutlet UIBarButtonItem *m_backButton;
	IBOutlet UIBarButtonItem *m_reloadButton;
	IBOutlet UIBarButtonItem *m_fwdButton;
	IBOutlet UIBarButtonItem *m_doneButton;
	
	BOOL m_shouldStopLoadingOnHide;
	BOOL m_shouldUseParentsView;
@private
	BOOL m_loadingInterrupted;
	NSURLRequest *m_urlRequestToLoad;
	
	IBOutlet UIActivityIndicatorView *m_activity;
	IBOutlet UILabel                 *m_loadingLabel;
	
	NSURL *m_currentURL;
	
	NSArray *m_normalItemList;
	NSArray *m_loadingItemList;
	
	BOOL m_shouldDisplayOnViewLoad;
	id m_parentCtrl;
	SEL m_authCallback;
	IBOutlet UIColor *sealColor;
}

@property (nonatomic,retain) IBOutlet UIToolbar *m_toolBar;
@property (nonatomic,retain) IBOutlet UIWebView *m_webView;
@property (nonatomic) BOOL m_shouldUseParentsView;
@property (nonatomic) BOOL m_shouldStopLoadingOnHide;
@property (nonatomic,retain) IBOutlet UIBarButtonItem *m_backButton;
@property (nonatomic,retain) IBOutlet UIBarButtonItem *m_reloadButton;
@property (nonatomic,retain) IBOutlet UIBarButtonItem *m_fwdButton;
@property (nonatomic,retain) IBOutlet UIBarButtonItem *m_doneButton;
@property (nonatomic,retain) NSURL *m_currentURL;
@property (nonatomic,retain) IBOutlet UIColor *sealColor;

+ (MiniBrowserController *)sharedBrowser;
+ (MiniBrowserController *)sharedBrowserWithURL:(NSURL *)urlOrNil;

- (void)display:(id)parentController;
- (NSString *)popoverButtonTitle;

- (IBAction)closeButtonPressed:(id)button;
- (IBAction)backButtonPressed:(id)button;
- (IBAction)fwdButtonPressed:(id)button;
- (IBAction)refreshButtonPressed:(id)button;
- (IBAction)openInSafari:(id)button;

- (void)loadURL:(NSURL *)url;
- (void)LoadRequest:(NSURLRequest *)urlRequest;
- (void)stopLoading;

- (void)setAuthCallback:(SEL)callback;
- (void)authCompleteCallback;

@property BOOL m_loadingInterrupted;
@property (retain) NSURLRequest *m_urlRequestToLoad;
@property (retain) IBOutlet UIActivityIndicatorView *m_activity;
@property (retain) IBOutlet UILabel					*m_loadingLabel;
@property (retain) NSArray *m_normalItemList;
@property (retain) NSArray *m_loadingItemList;
@property BOOL m_shouldDisplayOnViewLoad;
@property (assign,setter=display:) id m_parentCtrl;
@property (setter=setAuthCallback:) SEL m_authCallback;
@end
