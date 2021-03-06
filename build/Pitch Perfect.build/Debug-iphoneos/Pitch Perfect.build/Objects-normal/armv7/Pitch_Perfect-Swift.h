// Generated by Apple Swift version 1.2 (swiftlang-602.0.49.6 clang-602.0.49)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import AVFoundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UIWindow;
@class UIApplication;
@class NSObject;

SWIFT_CLASS("_TtC13Pitch_Perfect11AppDelegate")
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic) UIWindow * __nullable window;
- (BOOL)application:(UIApplication * __nonnull)application didFinishLaunchingWithOptions:(NSDictionary * __nullable)launchOptions;
- (void)applicationWillResignActive:(UIApplication * __nonnull)application;
- (void)applicationDidEnterBackground:(UIApplication * __nonnull)application;
- (void)applicationWillEnterForeground:(UIApplication * __nonnull)application;
- (void)applicationDidBecomeActive:(UIApplication * __nonnull)application;
- (void)applicationWillTerminate:(UIApplication * __nonnull)application;
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class AVAudioPlayer;
@class RecordedAudio;
@class AVAudioEngine;
@class AVAudioFile;
@class UIButton;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC13Pitch_Perfect24PlaySoundsViewController")
@interface PlaySoundsViewController : UIViewController
@property (nonatomic) AVAudioPlayer * __null_unspecified audioPlayer;
@property (nonatomic) RecordedAudio * __null_unspecified receivedAudio;
@property (nonatomic) AVAudioEngine * __null_unspecified audioEngine;
@property (nonatomic) AVAudioFile * __null_unspecified audioFile;
- (void)viewDidLoad;
- (void)didReceiveMemoryWarning;
- (IBAction)stopAudio:(UIButton * __nonnull)sender;
- (IBAction)playSlowAudio:(UIButton * __nonnull)sender;
- (IBAction)playFastAudio:(UIButton * __nonnull)sender;
- (void)playAudioWithVariablePitch:(float)pitch;
- (IBAction)playDarthVaderAudio:(UIButton * __nonnull)sender;
- (IBAction)playChipmunkAudio:(UIButton * __nonnull)sender;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class AVAudioRecorder;
@class UIStoryboardSegue;
@class UILabel;

SWIFT_CLASS("_TtC13Pitch_Perfect26RecordSoundsViewController")
@interface RecordSoundsViewController : UIViewController <AVAudioRecorderDelegate>
@property (nonatomic, weak) IBOutlet UILabel * __null_unspecified recordingInProgress;
@property (nonatomic, weak) IBOutlet UIButton * __null_unspecified stopRecording;
@property (nonatomic, weak) IBOutlet UIButton * __null_unspecified recordButton;
@property (nonatomic, weak) IBOutlet UIButton * __null_unspecified pauseButton;
@property (nonatomic) AVAudioRecorder * __null_unspecified audioRecorder;
@property (nonatomic) RecordedAudio * __null_unspecified recordedAudio;
@property (nonatomic) BOOL paused;
- (void)viewDidLoad;
- (void)didReceiveMemoryWarning;
- (void)viewWillAppear:(BOOL)animated;
- (IBAction)recordAudio:(UIButton * __nonnull)sender;
- (void)audioRecorderDidFinishRecording:(AVAudioRecorder * __null_unspecified)recorder successfully:(BOOL)flag;
- (void)prepareForSegue:(UIStoryboardSegue * __nonnull)segue sender:(id __nullable)sender;
- (IBAction)pauseRecordAudio:(UIButton * __nonnull)sender;
- (IBAction)stopRecordAudio:(UIButton * __nonnull)sender;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURL;

SWIFT_CLASS("_TtC13Pitch_Perfect13RecordedAudio")
@interface RecordedAudio : NSObject
@property (nonatomic) NSURL * __null_unspecified filePathUrl;
@property (nonatomic, copy) NSString * __null_unspecified title;
- (SWIFT_NULLABILITY(nonnull) instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
