#import "Three20/T3Object.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

#define T3_NULL_PHOTO_INDEX NSUIntegerMax

@protocol T3Photo, T3PhotoSourceDelegate;

///////////////////////////////////////////////////////////////////////////////////////////////////

@protocol T3PhotoSource <T3Object>

@property(nonatomic, copy) NSString* title;

/**
 * The total number of photos in the source, independent of the number that have been loaded.
 */
@property(nonatomic, readonly) NSUInteger numberOfPhotos;

/**
 * The maximum index of photos that have already been loaded.
 */
@property(nonatomic, readonly) NSUInteger maxPhotoIndex;

@property(nonatomic, readonly) BOOL loading;

- (id<T3Photo>)photoAtIndex:(NSUInteger)index;
- (NSUInteger)indexOfPhoto:(id<T3Photo>)photo;

/**
 * Loads a range of photos asynchronously.
 *
 * @param fromIndex The starting index.
 * @param toIndex The ending index, or -1 to load the remainder of photos.
 * @param delegate The object to be notified when loading completes.
 */
- (void)loadPhotosFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex
  delegate:(id<T3PhotoSourceDelegate>)delegate;

@end

@protocol T3PhotoSourceDelegate <NSObject>

- (void)photoSourceLoading:(id<T3PhotoSource>)photoSource fromIndex:(NSUInteger)fromIndex
   toIndex:(NSUInteger)toIndex;
- (void)photoSourceLoaded:(id<T3PhotoSource>)photoSource;
- (void)photoSource:(id<T3PhotoSource>)photoSource loadFailedWithError:(NSError*)error;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@protocol T3Photo <T3Object>

/**
 * The photo source that the photo belongs to.
 */
@property(nonatomic, assign) id<T3PhotoSource> photoSource;

/**
 * The full-size version of the photo.
 */
@property(nonatomic, copy) NSString* url;

/**
 * A small version of the photo.
 */
@property(nonatomic, copy) NSString* smallURL;

/**
 * A very small thumbnail version of the photo.
 */
@property(nonatomic, copy) NSString* thumbURL;

/**
 * The index of the photo within its photo source.
 */
@property(nonatomic) CGSize size;

/**
 * The index of the photo within its photo source.
 */
@property(nonatomic) NSInteger index;

@end