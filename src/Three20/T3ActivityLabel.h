#import "Three20/T3Global.h"

typedef enum {
  T3ActivityLabelStyleWhite,
  T3ActivityLabelStyleGray,
  T3ActivityLabelStyleBlackBezel,
  T3ActivityLabelStyleBlackThinBezel,
  T3ActivityLabelStyleWhiteBezel,
  T3ActivityLabelStyleWhiteBox
} T3ActivityLabelStyle;

@class T3PaintedView;

@interface T3ActivityLabel : UIView {
  T3ActivityLabelStyle style;
  T3PaintedView* bezelView;
  UIActivityIndicatorView* spinner;
  UILabel* labelView;
  BOOL centered;
  BOOL centeredToScreen;
}

@property (nonatomic, readonly) T3ActivityLabelStyle style;
@property (nonatomic, assign) NSString* label;
@property (nonatomic) BOOL centered;
@property (nonatomic) BOOL centeredToScreen;

- (id)initWithFrame:(CGRect)frame style:(T3ActivityLabelStyle)style;

@end