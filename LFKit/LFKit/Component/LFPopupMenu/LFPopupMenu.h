//
//  LFPopupMenu.h
//  LFPopupMenu
//
//  Created by 张林峰 on 2017/8/20.
//  Copyright © 2017年 张林峰. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PopupMenuDirection) {
    PopupMenuDirection_Auto,    //箭头自动确定朝上还是下
    PopupMenuDirection_Up,      //箭头朝上
    PopupMenuDirection_Down     //箭头朝下
};

@interface LFPopupMenuItem : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *selectedImage;
@property (nonatomic, assign) BOOL isSelected;

/** 生成选项对象，标题和图片至少要传一个参数*/
+ (LFPopupMenuItem *)createWithTitle:(NSString *)title image:(UIImage *)image selectedImage:(UIImage*)selectedImage isSelected:(BOOL)isSelected  NS_DEPRECATED_IOS(2_0, 2_0, "该方法已废弃，建议使用+ (LFPopupMenuItem *)createWithTitle:(NSString *)title image:(UIImage *)image action:(void(^)(void))action");

/** 生成选项对象，标题和图片至少要传一个参数*/
+ (LFPopupMenuItem *)createWithTitle:(NSString *)title image:(UIImage *)image action:(void(^)(void))action;

@end






@interface LFPopupMenu : UIView

@property (nonatomic, assign) CGFloat rowHeight;//行高,默认60
@property (nonatomic, assign) CGFloat arrowH;//箭头形高,默认9
@property (nonatomic, assign) CGFloat arrowW;//箭头形宽,默认9
@property (nonatomic, assign) CGFloat minWidth;//弹窗最小宽度，默认0
@property (nonatomic, assign) CGFloat popupMargin;//窗口距屏幕边缘最小距离，默认5
@property (nonatomic, assign) CGFloat leftEdgeMargin;//左边距窗口的距离，默认16
@property (nonatomic, assign) CGFloat rightEdgeMargin;//右边距窗口的距离，默认16
@property (nonatomic, assign) CGFloat textMargin;//文字距图标的距离，默认8
@property (nonatomic, assign) CGFloat lineMargin;//分割线左边距，默认0
@property (nonatomic, assign) CGFloat cornerRadius;//弹窗圆角,默认6
@property (nonatomic, assign) CGFloat arrowCornerRadius;//箭头的圆角，默认0
@property (nonatomic, strong) UIColor *lineColor;//分割线颜色、边框色，默认系统灰色
@property (nonatomic, strong) UIFont *textFont;//默认15
@property (nonatomic, strong) UIColor *textColor;//默认黑色
@property (nonatomic, strong) UIColor *fillColor;//带箭头框的填充色，默认白色
@property (nonatomic, assign) BOOL needBorder;//是否要边框

@property (nonatomic, strong) UIView *maskView;//半透明遮罩层,默认黑色半透明，可自行设置
@property (nonatomic, strong) UIImage *imgBG;//背景图，设置了这个就不用画带箭头的框了。
@property (nonatomic, assign) CGPoint anchorPoint;//设置背景图的情况使用，背景图的三角在背景图的位置比例，如左上角(0,0),右下角(1,1),下边中间(0.5,1)以此类推
@property (nonatomic, strong) UIView *menuSuperView;//本菜单弹窗的父视图，默认在Window上
@property (nonatomic, assign) PopupMenuDirection direction;

@property (nonatomic, copy) void(^dismissComplete)(void);//所以消失的回调
@property (nonatomic, copy) void(^selectDismiss)(void);//选择后消失的回调
@property (nonatomic, copy) void(^otherDismiss)(void);//点其他区域消失的回调

/**
 配置选项，注意：设置上面属性之后调用
 
 @param items 含文字和标题的对象数组
 */
- (void)configWithItems:(NSArray<LFPopupMenuItem *>*)items;

/**
 配置选项，注意：设置上面属性之后调用
 
 @param items 含文字和标题的对象数组
 @param action 点击回调，根据index判断点击的第几个
 */
- (void)configWithItems:(NSArray<LFPopupMenuItem *>*)items action:(void(^)(NSInteger index))action NS_DEPRECATED_IOS(2_0, 2_0, "该方法已废弃，建议使用- (void)configWithItems:(NSArray<LFPopupMenuItem *>*)items");

/**完全自定义菜单弹窗*/
- (void)configWithCustomView:(UIView *)customView;

/**
 显示菜单窗，有imgBG的情况下调用
 @param point 本控件“左上角”位置,相对window
 */
- (void)showInPoint:(CGPoint)point;

/**
 显示菜单窗，无imgBG的情况下调用
 @param point 箭头顶点位置,相对window
 */
- (void)showArrowInPoint:(CGPoint)point;


/**
 显示菜单窗，无imgBG的情况下调用（推荐）
 
 @param view 箭头对准的view
 */
- (void)showArrowToView:(UIView*)view;

/**
 显示菜单窗，无imgBG的情况下调用（同上，只是加了偏移）
 
 @param view 箭头对准的view
 */
- (void)showArrowToView:(UIView*)view offset:(CGFloat)offset;


- (void)dismiss;

@end

