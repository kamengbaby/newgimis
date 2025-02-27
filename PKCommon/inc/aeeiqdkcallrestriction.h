#ifndef AEEQDKCALLRESTRICTION_H
#define AEEQDKCALLRESTRICTION_H
/*=============================================================================
 
FILE: AEEQDKCallRestriction.h

SERVICES: The IQDKCallRestriction interface manages all the methods related to 
Call Restriction features of QChat.

GENERAL DESCRIPTION:

PUBLIC CLASSES AND STATIC FUNCTIONS:
   IQDKCallRestriction

        Copyright © 2005 QUALCOMM Incorporated.
               All Rights Reserved.
            QUALCOMM Proprietary
=============================================================================*/
/*=============================================================================
                     INCLUDE FILES FOR MODULE
=============================================================================*/
#include "AEE.h"
#include "AEEQDKDataTypes.h"
#include "AEEIQDKCallRestriction.bid"	//Backward_Comp_START_Apr_19

/*=============================================================================
                    CLASS DEFINITIONS
=============================================================================*/

#define AEEIID_IQDKCALLRSTRICTION 0x01052f2e //Interface ID for 2.0 QueryInterface

typedef struct IQDKCallRestriction IQDKCallRestriction;

AEEINTERFACE(IQDKCallRestriction)
{
   INHERIT_IQueryInterface(IQDKCallRestriction);
   IQDK_ErrorType (*Init)(IQDKCallRestriction *po,
                          AEECLSID appClsID);
   IQDK_ErrorType (*SetByIndex)(IQDKCallRestriction *po,
                                IQDK_CallRestrictionEntry * entry,
                                uint32 callRestrictionIndex);
   IQDK_ErrorType (*RemoveByIndex)(IQDKCallRestriction *po,
                                   uint32 callRestrictionIndex);
   IQDK_ErrorType (*GetCount)(IQDKCallRestriction *po,
                              uint32* pSize);
   IQDK_ErrorType (*GetByIndex)(IQDKCallRestriction *po,
                                IQDK_CallRestrictionEntry *pRestriction,
                                uint32 callRestrictionIndex);
   IQDK_ErrorType (*IsRestricted)(IQDKCallRestriction *po,
                                  IQDK_CallRestrictionDirection direction, 
                                  IQDK_ServicesEnum service,
                                  IQDKAddressData *pAddress,
                                  boolean *restricted);
};

#define IQDKCALLRESTRICTION_AddRef(p)                   AEEGETPVTBL((p),IQDKCallRestriction)->AddRef((p))
#define IQDKCALLRESTRICTION_Release(p)                  AEEGETPVTBL((p),IQDKCallRestriction)->Release((p))
#define IQDKCALLRESTRICTION_QueryInterface(p,clsid,pp)  AEEGETPVTBL((p),IQDKCallRestriction)->QueryInterface((p),(clsid),(pp))
#define IQDKCALLRESTRICTION_SetByIndex(p,entry, id)     AEEGETPVTBL((p),IQDKCallRestriction)->SetByIndex((p),(entry),(id))
#define IQDKCALLRESTRICTION_RemoveByIndex(p,id)         AEEGETPVTBL((p),IQDKCallRestriction)->RemoveByIndex((p),(id))
#define IQDKCALLRESTRICTION_GetCount(p, size)           AEEGETPVTBL((p),IQDKCallRestriction)->GetCount((p), (size))
#define IQDKCALLRESTRICTION_GetByIndex(p,res,id)        AEEGETPVTBL((p),IQDKCallRestriction)->GetByIndex((p),(res),(id))
#define IQDKCALLRESTRICTION_Init(p,clsid)               AEEGETPVTBL((p),IQDKCallRestriction)->Init((p),(clsid))
#define IQDKCALLRESTRICTION_IsRestricted(p,dir,svc,a,r) AEEGETPVTBL((p),IQDKCallRestriction)->IsRestricted((p),(dir),(svc),(a),(r))

/*=====================================================================
  DATA STRUCTURE DOCUMENTATION
=======================================================================
=====================================================================

=======================================================================
=======================================================================
  INTERFACES   DOCUMENTATION
=======================================================================

Interface Name: IQDKCallRestriction

Description:
    IQDKCallRestriction interface provides a set of API methods that are 
intended to be used by applications that will be using the Call Restriction
features of QChat. 

    The QChat System design includes a mechanism that allows the user or the 
carrier to restrict inbound or outbound QChat traffic via an ordered list of 
entries. Each entry in the list specifies whether the user is permitted to 
communicate with the party specified in the restriction or whether 
the user is denied communication with the party specified in the restriction. The
Compilation of these lists and their applications together are referred to as
QChat Call Restrictions.

   Each call restriction is expressed by direction, type, services, and a token
against which QChat addresses will be matched.  For example, an application
might choose to define a restriction that would prevent the user from making a
direct call to other users in a specific domain.  This would be an outbound,
deny, direct calls, restriction against a particular addressing domain.
Similarly, a restriction could be defined to always accept incoming group calls
from a specific addresses - regardless of any other user level restrictions that
may have been established.  This would be an inbound, always allow, group calls,
carrier level restriction for a specific user address.
  

            type:	IQDK_ALLOW, IQDK_DENY, IQDK_ALWAYS_ALLOW
            direction: IQDK_INBOUND, IQDK_OUTBOUND, IQDK_INBOUND_AND_OUTBOUND
            service:	represented by 4 hex digits
                     These four hex digits represent 16 bits, one bit per service.
                     Starting from the least significant bit, each bit represents the
                     following services in order: 
                     Alerts, Direct Calls, Group Calls, Ad Hoc calls, Chatroom Calls, 
                     PresenceOnDemand
                     The remaining bits shall be used for future services and are 
                     currently don't cares.
                     For example: 0001 represents Alerts only
                                  0003 represents Alerts and Direct Calls)
            token: A token is matched against a QChat address. '*' represents a wildcard

  

The IQDKCallRestriction interface instance is obtained via ISHELL_CreateInstance()
mechanism.

The following header file is required:~
AEEQDKCallRestrictions.h

=============================================================================

IQDKCALLRESTRICTION_AddRef()

Description:
   This method increments the reference count of the IQDKCallRestriction Interface object.
   This allows the object to be shared by multiple callers. The object is freed when
   the reference count reaches 0 (zero).

Prototype:
   uint32 IQDKCALLRESTRICTION_AddRef(IQDKCallRestriction * po)

Parameters:
   po : Pointer to the IQDKCallRestriction Interface object

Return Value:
   Incremented reference count for the object

Comments:
   A valid object returns a positive reference count.

Version:
   Introduced in QDK v 2.0

Side Effects:
   None

See Also:
   IQDKCALLRESTRICTION_Release()

=============================================================================

IQDKCALLRESTRICTION_Release()

Description:
   This method decrements the reference count of an object. The object is freed
   from memory and is no longer valid once the reference count reaches 0 (zero).

Prototype:
   uint32 IQDKCALLRESTRICTION_Release(IQDKCallRestriction * po)

Parameters:
   po : Pointer to the IQDKCallRestriction Interface object

Return Value:
   Decremented reference count for the object. The object has been freed and is no
   longer valid if 0 (zero) is returned.

Comments:
   None

Version:
   Introduced in QDK v 2.0

Side Effects:
   None

See Also:
   IQDKCALLRESTRICTION_AddRef()

==============================================================================

IQDKCALLRESTRICTION_QueryInterface()

Description:
   This method retrieves a pointer to an interface conforming to the
   definition of the specified class ID.  This can be used to query for
   extended functionality, like future versions or proprietary extensions.

   Upon a successful query, the interace is returned AddRef'ed.  The caller is
   responsible for calling Release() at some point in the future.  One
   exception is when the pointer returned is not an interface pointer.  In
   that case, the memory will share the lifetime of the object being queried,
   and the returned pointer will not be used to free or release the object.

Prototype:
   int IQDKCALLRESTRICTION_QueryInterface(IQDKCallRestriction *po, AEECLSID id, void **p)

Parameters:
   po : Pointer to IQDKCallRestriction interface
   id : A globally unique id to identify the entity (interface or data) that we
           are trying to query.
   p  : Pointer to the data or interface that we want to retrieve.  If the interface
           is not available, this is set to NULL.

Return Value:
   SUCCESS          : success,
   ECLASSNOTSUPPORT : if class ID not supported

Comments:
   On failure, QueryInterface() must set *p to NULL.

Version:
   Introduced in QDK v 2.0

Side Effects:
   None

See Also:
   None

=============================================================================
IQDKCALLRESTRICTION_Init()

Description:
   This function must be the first API that is called by the QDK application that
   instantiates an object of this interface. This function gives the QChat Client
   a chance to intialize variables for this interface.

Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_Init(IQDKCALLRESTRICTION *po, AEECLSID appClsID)

Parameters:
   po       : Pointer to the IQDKCALLRESTRICTION Interface object.
   appClsId : Class ID of the QDK application that is calling this API.

Return Value:
   SUCCESS   : The interface has been successfully initiated
   EFAILED   : Unknown failure
   EBADCLASS : The po pointer is NULL 

Version:
   Introduced in QDK v 2.0

================================================================================

Function: IQDKCALLRESTRICTION_RemoveByIndex()
                  
Description:
   This function removes an existing user-level QChat call restriction from
   the ordered list of call restrictions at the index provided.
   
Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_RemoveByIndex
   (
      IQDKCallRestriction *po,
      uint32               callRestrictionIndex);
   )
   
Parameters:
   po                   : Pointer to the IQDKCallRestriction Interface object.
   callRestrictionIndex : index of the restriction to be removed

Return Value:
   SUCCESS   : The call restriction was successfully removed.
   EBADCLASS : The po pointer is NULL
   EQDKNOTINITIALIZED : IQDKCALLRESTRICTION_Init() was not called first
	EQDKOUTOFRANGE: invalid call restriction index
	EQDKRESTRICTIONCONFLICT : if the user tries to remove a carrier level call restriction
  
Comments:
   None.

Version:
   Introduced in QDK v 2.0
       
See Also:
   IQDK_Init()
   IQDKCALLRESTRICTION_SetByIndex()

=====================================================================
Function: IQDKCALLRESTRICTION_SetByIndex()
                     
Description:
   This function adds user-level QChat call restrictions to the end of
   the ordered list of call restrictions enforced by the QChat Client.
                      
Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_SetByIndex
   (
      IQDKCallRestriction       *po,
      IQDK_CallRestrictionEntry *entry,
      uint32 callRestrictionIndex
   )
                        
Parameters:
   po    : Pointer to the IQDKCallRestriction Interface object.
   entry : Pointer to an IQDK_CallRestrictionEntry data structure containing
      the addresses against which the QChat Client will add the call
      restriction.  
   callRestrictionIndex : This is an index into the Call Restriction table 
      pointing to a particular Call Restriction. 

Return Value:
   SUCCESS      : The restriction was successfully added to the end of the list
   EBADCLASS    : The po pointer is NULL
   EBADPARM     : entry pointer is NULL
   EQDKRESTRICTIONCONFLICT   : If the user tries to set a carrier level call restriction
   EQDKRESTRICTIONNOTALLOWED : The restriction could not be added because
      user-level and "allow always" restrictions cannot be set.
   EQDKNOTINITIALIZED : IQDKCALLRESTRICTION_Init() was not called first
   
Comments:
   New restrictions are always added to the end of the restriction list.
   To insert a restriction in the middle of the list, the calling
   application would need to retrieve and store the entire list, remove
   each entry, then add back each stored restriction, inserting the new
   restriction at the proper location in the list. This is required and its 
   important to have call restrictions in right required order; since if 
   there are two call restrictions in a list, the one comes later in restriction 
   list will always be considered than old one. The maximum number of call restrictions
   allowed is 100.
                                                 
Version:
   Introduced in QDK v 2.0

See Also:
   IQDKCALLRESTRICTION_RemoveByIndex()
   IQDKCALLRESTRICTION_GetCount()
   IQDKCALLRESTRICTION_GetByIndex()

=====================================================================
Function: IQDKCALLRESTRICTION_GetCount()

Description:
   This function allows applications to get a total count of all the 
   user level and carrier level call restrictions defined in the QChat Client. 
   The maximum count can be returned for call restrictions is 100 (max user 
   level restriction = 80, and max carrier level restriction = 20).  This 
   value will typically be used in IQDKCALLRESTRICTION_GetByIndex().
                                                                                                                              
Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_GetCount
   (
      IQDKCallRestriction *po,
      uint32              *pSize
   )
                                                                                                                              
Parameters:
   po    : Pointer to the IQDK Call Restrictions Interface object.
   pSize : Pointer to a type where the count of the type will be stored.
                                                                                                                              
Return Value:
   SUCCESS   : The number of restrictions was set in pSize param
   EBADCLASS : The po pointer is NULL
   EBADPARM  : pSize pointer is NULL
   EQDKNOTINITIALIZED : IQDKCALLRESTRICTION_Init() was not called first

Version:
   Introduced in QDK v 2.0

See Also:
   IQDKCALLRESTRICTION_GetByIndex()

=====================================================================
Function: IQDKCALLRESTRICTION_GetByIndex()

Description:
   This function allows applications to get a particular restriction
   from the list of call restrictions defined in the QChat Client.
         
Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_GetByIndex
   (
      IQDKCallRestriction       *po,
      IQDK_CallRestrictionEntry *pRestriction,
      uint32                     callRestrictionIndex
   )
                                              
Parameters:
   po                   : Pointer to the IQDK Call Restrictions Interface object.
   pRestriction         : Pointer to an IQDK_CallRestrictionEntry, into
      which the QChat Client will copy the data for a restriction.
   callRestrictionIndex : This is an index into the Call Restriction table 
      pointing to a particular Call Restriction. 

Return Value:

   SUCCESS   : The restriction at specified index was copied into pRestriction
   EBADCLASS : The po pointer is NULL 
   EBADPARM  : pRestriction pointer is NULL
	EQDKOUTOFRANGE : invalid call restriction index.
   EQDKNOTINITIALIZED : IQDKCALLRESTRICTION_Init() was not called first

Version:
   Introduced in QDK v 2.0

See Also:
   IQDKCALLRESTRICTION_GetCount()

=====================================================================
Function: IQDKCALLRESTRICTION_IsRestricted()

Description:
   This function allows applications to find Whether or not an address 
   is restricted from a particular service in the specified direction.
         
Prototype:
   IQDK_ErrorType IQDKCALLRESTRICTION_IsRestricted
   (
      IQDKCallRestriction           *po,
      IQDK_CallRestrictionDirection direction, 
      IQDK_ServicesEnum             service,
      IQDKAddressData               *pAddress,
      boolean                       *restricted
   )
                                              
Parameters:
   po                   : Pointer to the IQDK Call Restrictions Interface object.
   direction            : inbound or outboud but not both
   service              : The type of service
   pAddress             : The address on which a check for restrictions should be performed
   restricted           : Stores whether or not pAddress is restricted to
                          use service in the specified direction.

Return Value:

   SUCCESS   : restricted holds a valid value
   EBADCLASS : The po pointer is NULL
   EBADPARM  : One or more parameters are invalid
   EQDKNOTINITIALIZED : IQDKCALLRESTRICTION_Init() was not called first


Version:
   Introduced in QDK v 2.0

See Also:

=====================================================================
*/
#endif // AEEQDKCALLRESTRICTION_H
