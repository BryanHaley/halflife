/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
#include "../hud.h"
#include "../cl_util.h"
#include "event_api.h"

extern "C"
{
// HLDM
void EV_FireGlock1( struct event_args_s *args  );
void EV_FireGlock2( struct event_args_s *args  );
void EV_FireShotGunSingle( struct event_args_s *args  );
void EV_FireShotGunDouble( struct event_args_s *args  );
void EV_FireMP5( struct event_args_s *args  );
void EV_FireMP52( struct event_args_s *args  );
void EV_FirePython( struct event_args_s *args  );
void EV_FireGauss( struct event_args_s *args  );
void EV_SpinGauss( struct event_args_s *args  );
void EV_Crowbar( struct event_args_s *args );
void EV_FireCrossbow( struct event_args_s *args );
void EV_FireCrossbow2( struct event_args_s *args );
void EV_FireRpg( struct event_args_s *args );
void EV_EgonFire( struct event_args_s *args );
void EV_EgonStop( struct event_args_s *args );
void EV_HornetGunFire( struct event_args_s *args );
void EV_TripmineFire( struct event_args_s *args );
void EV_SnarkFire( struct event_args_s *args );



void EV_TrainPitchAdjust( struct event_args_s *args );

#if defined ( WANTEDHL_DLL ) || defined ( WANTEDHL_CLIENT_DLL )
void EV_Beartrap(struct event_args_s *args);
void EV_Bow(struct event_args_s *args);
void EV_Buffalo(struct event_args_s *args);
void EV_Cannon(struct event_args_s *args);
void EV_Colts(struct event_args_s *args);
void EV_Gattlinggun(struct event_args_s *args);
void EV_Knife(struct event_args_s *args);
void EV_Pick(struct event_args_s *args);
void EV_Pistol(struct event_args_s *args);
void EV_Scorpion(struct event_args_s *args);
void EV_Shotgun(struct event_args_s *args);
void EV_Winchester(struct event_args_s *args);
#endif // defined ( WANTEDHL_DLL ) || defined ( WANTEDHL_CLIENT_DLL )
}

/*
======================
Game_HookEvents

Associate script file name with callback functions.  Callback's must be extern "C" so
 the engine doesn't get confused about name mangling stuff.  Note that the format is
 always the same.  Of course, a clever mod team could actually embed parameters, behavior
 into the actual .sc files and create a .sc file parser and hook their functionality through
 that.. i.e., a scripting system.

That was what we were going to do, but we ran out of time...oh well.
======================
*/
void Game_HookEvents( void )
{
	gEngfuncs.pfnHookEvent( "events/glock1.sc",					EV_FireGlock1 );
	gEngfuncs.pfnHookEvent( "events/glock2.sc",					EV_FireGlock2 );
	gEngfuncs.pfnHookEvent( "events/shotgun1.sc",				EV_FireShotGunSingle );
	gEngfuncs.pfnHookEvent( "events/shotgun2.sc",				EV_FireShotGunDouble );
	gEngfuncs.pfnHookEvent( "events/mp5.sc",					EV_FireMP5 );
	gEngfuncs.pfnHookEvent( "events/mp52.sc",					EV_FireMP52 );
	gEngfuncs.pfnHookEvent( "events/python.sc",					EV_FirePython );
	gEngfuncs.pfnHookEvent( "events/gauss.sc",					EV_FireGauss );
	gEngfuncs.pfnHookEvent( "events/gaussspin.sc",				EV_SpinGauss );
	gEngfuncs.pfnHookEvent( "events/train.sc",					EV_TrainPitchAdjust );
	gEngfuncs.pfnHookEvent( "events/crowbar.sc",				EV_Crowbar );
	gEngfuncs.pfnHookEvent( "events/crossbow1.sc",				EV_FireCrossbow );
	gEngfuncs.pfnHookEvent( "events/crossbow2.sc",				EV_FireCrossbow2 );
	gEngfuncs.pfnHookEvent( "events/rpg.sc",					EV_FireRpg );
	gEngfuncs.pfnHookEvent( "events/egon_fire.sc",				EV_EgonFire );
	gEngfuncs.pfnHookEvent( "events/egon_stop.sc",				EV_EgonStop );
	gEngfuncs.pfnHookEvent( "events/firehornet.sc",				EV_HornetGunFire );
	gEngfuncs.pfnHookEvent( "events/tripfire.sc",				EV_TripmineFire );
	gEngfuncs.pfnHookEvent( "events/snarkfire.sc",				EV_SnarkFire );

#if defined ( WANTEDHL_DLL ) || defined ( WANTEDHL_CLIENT_DLL )
	gEngfuncs.pfnHookEvent("events/beartrap.sc",				EV_Beartrap);
	gEngfuncs.pfnHookEvent("events/bow.sc",						EV_Bow);
	gEngfuncs.pfnHookEvent("events/buffalo.sc",					EV_Buffalo);
	gEngfuncs.pfnHookEvent("events/cannon.sc",					EV_Cannon);
	gEngfuncs.pfnHookEvent("events/colts.sc",					EV_Colts);
	gEngfuncs.pfnHookEvent("events/gattlinggun.sc",				EV_Gattlinggun);
	gEngfuncs.pfnHookEvent("events/knife.sc",					EV_Knife);
	gEngfuncs.pfnHookEvent("events/pick.sc",					EV_Pick);
	gEngfuncs.pfnHookEvent("events/pistol.sc",					EV_Pistol);
	gEngfuncs.pfnHookEvent("events/scorpion.sc",				EV_Scorpion);
	gEngfuncs.pfnHookEvent("events/shotgun.sc",					EV_Shotgun);
	gEngfuncs.pfnHookEvent("events/winchester.sc",				EV_Winchester);
#endif // defined ( WANTEDHL_DLL ) || defined ( WANTEDHL_CLIENT_DLL )
}
