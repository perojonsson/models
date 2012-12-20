/*----------------------------------------------------------------------------
 * File:  dsl_NEEDLEDOWN_class.c
 *
 * Class:       needle down  (NEEDLEDOWN)
 * Component:   dsl
 *
 * (C) Copyright 1998-2012 Mentor Graphics Corporation.  All rights reserved.
 *--------------------------------------------------------------------------*/

#include "dsl_sys_types.h"
#include "ARCH_bridge.h"
#include "LOG_bridge.h"
#include "TIM_bridge.h"
#include "dsl_classes.h"

/*
 * class operation:  load
 */
i_t
dsl_NEEDLEDOWN_op_load( dsl_ASCMD * p_ascmd, dsl_PROGRAM * p_program)
{
  dsl_ASCMD * ascmd; dsl_NEEDLEDOWN * needledown; 
  /* LOG::LogInfo( message:'loading needle down' ) */
  LOG_LogInfo( "loading needle down" );
  /* ASSIGN ascmd = PARAM.ascmd */
  ascmd = p_ascmd;
  /* CREATE OBJECT INSTANCE needledown OF NEEDLEDOWN */
  needledown = (dsl_NEEDLEDOWN *) Escher_CreateInstance( dsl_DOMAIN_ID, dsl_NEEDLEDOWN_CLASS_NUMBER );
  /* RELATE needledown TO ascmd ACROSS R31 */
  dsl_NEEDLEDOWN_R31_Link( ascmd, needledown );
  /* RETURN 1 */
  return 1;

}

/*
 * instance operation:  run
 */
bool
dsl_NEEDLEDOWN_op_run( dsl_NEEDLEDOWN * self)
{
  dsl_ASCMD * ascmd = 0; /* ascmd (ASCMD) */
 
  /* LOG::LogInfo( message:'needle down:  sampling...' ) */
  LOG_LogInfo( "needle down:  sampling..." );
  /* SELECT one ascmd RELATED BY self->ASCMD[R31] */
  ascmd = self->ASCMD_R31;
  /* GENERATE ascmd.completion_event */
  Escher_SendEvent( (Escher_xtUMLEvent_t *) ascmd->completion_event );
  /* RETURN FALSE */
  return FALSE;

}


/*
 * RELATE ASCMD TO NEEDLEDOWN ACROSS R31
 */
void
dsl_NEEDLEDOWN_R31_Link( dsl_ASCMD * supertype, dsl_NEEDLEDOWN * subtype )
{
  if ( (supertype == 0) || (subtype == 0) ) {
    XTUML_EMPTY_HANDLE_TRACE( "NEEDLEDOWN", "dsl_NEEDLEDOWN_R31_Link" );
    return;
  }
  /* Optimized linkage for NEEDLEDOWN->ASCMD[R31] */
  subtype->ASCMD_R31 = supertype;
  /* Optimized linkage for ASCMD->NEEDLEDOWN[R31] */
  supertype->R31_subtype = subtype;
  supertype->R31_object_id = dsl_NEEDLEDOWN_CLASS_NUMBER;
}



/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      needle down  (NEEDLEDOWN)
 * Component:  dsl
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s dsl_NEEDLEDOWN_container[ dsl_NEEDLEDOWN_MAX_EXTENT_SIZE ];
static dsl_NEEDLEDOWN dsl_NEEDLEDOWN_instances[ dsl_NEEDLEDOWN_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_dsl_NEEDLEDOWN_extent = {
  {0}, {0}, &dsl_NEEDLEDOWN_container[ 0 ],
  (Escher_iHandle_t) &dsl_NEEDLEDOWN_instances,
  sizeof( dsl_NEEDLEDOWN ), dsl_NEEDLEDOWN_STATE_1, dsl_NEEDLEDOWN_MAX_EXTENT_SIZE
  };
/*----------------------------------------------------------------------------
 * State and transition action implementations for the following class:
 *
 * Class:      needle down  (NEEDLEDOWN)
 * Component:  dsl
 *--------------------------------------------------------------------------*/

/*
 * State 1:  [a]
 */
static void dsl_NEEDLEDOWN_act1( dsl_NEEDLEDOWN *, const Escher_xtUMLEvent_t * const );
static void
dsl_NEEDLEDOWN_act1( dsl_NEEDLEDOWN * self, const Escher_xtUMLEvent_t * const event )
{
}



  /*
   * Array of pointers to the class state action procedures.
   * Index is the (MC enumerated) number of the state action to execute.
   */
  static const StateAction_t dsl_NEEDLEDOWN_acts[ 2 ] = {
    (StateAction_t) 0,
    (StateAction_t) dsl_NEEDLEDOWN_act1  /* a */
  };

/*
 * For this state machine, there are either no events,
 * no transitions, or no states.
 */
void
dsl_NEEDLEDOWN_Dispatch( Escher_xtUMLEvent_t * event )
{
  /*
   * This is an empty state machine, which is not good to have.
   * But since there are no events that could land here, we will
   * ignore this and assume that it is an incomplete model.
   */
}

