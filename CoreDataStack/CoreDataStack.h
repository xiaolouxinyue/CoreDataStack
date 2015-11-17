//
//  TMCoreDataStack.h
//  adventures
//
//  Created by Tony Million on 6/27/14.
//  Copyright (c) 2014 OmniTyke. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import "NSManagedObject+helpers.h"
#import "NSManagedObject+importing.h"
#import "NSManagedObjectContext+helpers.h"


#if DEBUG
#	define CDLog(_format, ...) NSLog(_format, ##__VA_ARGS__)
#else
#	define CDLog(_format, ...)
#endif

#import "NSManagedObject+helpers.h"
#import "NSManagedObject+importing.h"
#import "NSManagedObjectContext+helpers.h"

@interface CoreDataStack : NSObject

@property (readonly, strong, nonatomic) NSManagedObjectContext          *backgroundSaveObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectContext          *mainThreadObjectContext;

@property (readonly, strong, nonatomic) NSManagedObjectModel            *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator    *persistentStoreCoordinator;

@property (assign) BOOL canFailToMemoryContext;
@property (assign) BOOL canDeleteOnFail;

/*
 使用单例模式时，需在didFinishLaunchingWithOptions中调用setup方法初始化
 */
+(CoreDataStack*)sharedInstance;

-(void)setupDataBaseWithManagedObjectModelName:(NSString*)momName databaseName:(NSString*)databaseName canDeleteOnFail:(BOOL)deletable;


/*
 工厂方法
 */
-(id)initWithManagedObjectModelName:(NSString*)momName databaseName:(NSString*)databaseName canDeleteOnFail:(BOOL)deletable;

-(id)initWithManagedObjectModel:(NSManagedObjectModel*)model databaseName:(NSString*)databaseName canDeleteOnFail:(BOOL)deletable;

-(BOOL)removeDatabaseWithName:(NSString*)databaseName error:(NSError **)error;

- (NSManagedObjectContext *)createPrivateObjectContext;


@end
