//
//  UIViewController+AnimationMachine.h
//  SKAnimationMachine
//
//  Created by Slavko Krucaj on 6.9.2012..
//  Copyright (c) 2012. slavko.krucaj@gmail.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SKTransition : NSObject

@property NSString *transitionId;
@property NSString *toStateId;
@property NSString *fromStateId;
@property NSTimeInterval duration;
@property NSTimeInterval delay;
@property UIViewAnimationCurve animationCurve;

@end

@interface SKView : NSObject

@property NSString *animatedViewId;
@property UIView *animatedView;
@property CGFloat alpha;
@property CGRect frame;
@property CGAffineTransform transform;

@end

@interface SKState : NSObject

@property NSMutableArray *views;
@property NSString *stateId;
@property NSMutableDictionary *transitions;
@property NSString *nextTransition;

- (void)addTransition:(SKTransition *)transition;
- (void)addView:(SKView *)view;

@end

@interface SKGroup : NSObject

@property NSString *stateId;
@property UIView *animatedView;
@property CGFloat alpha;
@property CGRect frame;
@property CGAffineTransform transform;
@property NSMutableDictionary *transitions;
@property NSString *nextStateId;

@end

@interface SKHelper : NSObject

@property SKState *currentState;

@end

@protocol AnimationMachineProtocol <NSObject>
- (void)finishedAnimationToState:(NSString *)stateId;
@end

@interface UIViewController (AnimationMachine)

@property SKState *currentState;
@property NSMutableDictionary *states;
@property id<AnimationMachineProtocol> animationDelegate;

- (void)addState:(SKState *)state;

- (void)initialize:(NSString *)state;
- (void)performTransition:(NSString *)transitionId;

@end
