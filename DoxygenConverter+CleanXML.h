//
//  DoxygenConverter+CleanXML.h
//  objcdoc
//
//  Created by Tomaz Kragelj on 17.4.09.
//  Copyright 2009 Tomaz Kragelj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DoxygenConverter.h"

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
/** Implements clean XML documentation related functionality for @c DoxygenConverter 
class.

￼￼This category handles conversion from doxygen created XML files to clean XML. It's
members create clean XML object and index files, fix the links and save the new files
in the proper directory structure.
*/
@interface DoxygenConverter (CleanXML)

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Clean XML handling
//////////////////////////////////////////////////////////////////////////////////////////

/** Creates clean object XML markups.￼

This method will scan the doxygen XML output. For each file it will check if it contains
a known object (by testing the file name) and that the file is documented. For each
known documented file, it will add the original markup in the form of the @c NSXMLParser
to the @c data dictionary. The key of the dictionary will be the name of the described
object.
 
Note that this method will not save the clean XML file yet, it will only prepare the
proper name including full path and will add all the data, including cleaned XML tree
into the database. Until the utility finishes working, it will work on in-memory XML
representation and only save after all steps are finished.

This message is automaticaly sent from @c DoxygenConverter::convert() in the proper order.
See also @c createCleanIndexDocumentationFile(), @c fixCleanObjectDocumentationLinks()
and @c saveCleanObjectDocumentationFiles().

@exception ￼￼￼￼￼NSException Thrown if convertion fails.
*/
- (void) createCleanObjectDocumentationMarkup;

/** Creates clean index XML file.￼

This method will use the data generated by the @c createCleanObjectDocumentationMarkup() and will
create the index file, so it is required that @c createCleanObjectDocumentationMarkup() is sent
to the received before sending this message!

This message is automaticaly sent from @c DoxygenConverter::convert() in the proper order.
See also @c createCleanObjectDocumentationMarkup(), @c fixCleanObjectDocumentationLinks()
and @c saveCleanObjectDocumentationFiles().

@exception ￼￼￼￼￼NSException Thrown if index file creation fails.
*/
- (void) createCleanIndexDocumentationFile;

/** Fixes all links in the clean object XML files.￼

This method will scan the clean XML and will fix all links to class members, the class
and inter-classes and their members properly.
 
This message is automaticaly sent from @c DoxygenConverter::convert() in the proper order.
See also @c createCleanObjectDocumentationMarkup(), @c createCleanIndexDocumentationFile()
and @c saveCleanObjectDocumentationFiles().

@exception ￼￼￼￼￼NSException Thrown if fixing links fails.
*/
- (void) fixCleanObjectDocumentationLinks;

/** Saved clean object XML markups to proper files.￼

This method will save all clean XML markups in the database to proper files.
 
This message is automaticaly sent from @c DoxygenConverter::convert() in the proper order.
See also @c createCleanObjectDocumentationMarkup(), @c createCleanIndexDocumentationFile()
and @c fixCleanObjectDocumentationLinks().

@exception ￼￼￼￼￼NSException Thrown if fixing links fails.
*/
- (void) saveCleanObjectDocumentationFiles;

//////////////////////////////////////////////////////////////////////////////////////////
/// @name Helper methods
//////////////////////////////////////////////////////////////////////////////////////////

/** Prepares the link to the given destination object.￼

The link is prepared for the given @c source object's reference to the given @c destination
object. If the two objects are found in the same subdirectory, the destination file name
is returned. Otherwise the relative link to the destination's file is returned. The
returned link already contains the required html extension.

@param source ￼￼￼￼￼￼The object which is reffering to @c destination objecy.
@param destination ￼￼￼￼￼￼The object to which the @c object is reffering.
@return ￼￼￼￼Returns the required link, including relative path if necessary.
*/
- (NSString*) objectReferenceFromObject:(NSString*) source 
							   toObject:(NSString*) destination;

@end
