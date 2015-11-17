//
//  NSManagedObjectContext+helpers.h
//  Pods
//
//  Created by Tony Million on 14/01/2015.
//
//

#import <CoreData/CoreData.h>

@interface NSManagedObjectContext (helpers)

-(BOOL)save;
-(void)recursiveSave;

-(void)observeChangesFromParent:(BOOL)observe;

/*因在后台线程更新数据后，要发送通知更新列表。故手动调用递归保存即可*/
//-(void)performBlockAndSave:(void (^)(NSManagedObjectContext *context))block;
//-(void)performBlockAndWaitAndSave:(void (^)(NSManagedObjectContext *context))block;

@end
