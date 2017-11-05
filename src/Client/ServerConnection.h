#ifndef CC_SERVERCONNECTION_H
#define CC_SERVERCONNECTION_H
#include "Typedefs.h"
#include "String.h"
#include "Vectors.h"
#include "Input.h"
#include "GameStructs.h"
#include "PickedPosRenderer.h"
/* Represents a connection to either a singleplayer or multiplayer server.
   Copyright 2014-2017 ClassicalSharp | Licensed under BSD-3
*/

/* TODO: WORK THESE OUT*/
bool ServerConnection_IsSinglePlayer;
String ServerConnection_ServerName;
String ServerConnection_ServerMOTD;
String ServerConnection_AppName;

void (*ServerConnection_Connect)(STRING_TRANSIENT String* ip, Int32 port);
void (*ServerConnection_SendChat)(STRING_TRANSIENT String* text);
void (*ServerConnection_SendPosition)(Vector3 pos, Real32 rotY, Real32 headX);
void (*ServerConnection_SendPlayerClick)(MouseButton button, bool isDown, EntityID targetId, PickedPos* pos);
void (*ServerConnection_Tick)(ScheduledTask* task);
void (*ServerConnection_Free)(void);

/* Whether the network processor is currently disconnected from the server. */
bool ServerConnection_Disconnected;
/* Whether the client supports extended player list management, with group names and ranks. */
bool ServerConnection_SupportsExtPlayerList;
/* Whether the server supports handling PlayerClick packets from the client. */
bool ServerConnection_SupportsPlayerClick;
/* Whether the server can handle partial message packets or not. */
bool ServerConnection_SupportsPartialMessages;
/* Whether the server supports receiving all code page 437 characters from this client. */
bool ServerConnection_SupportsFullCP437;

void ServerConnection_RetrieveTexturePack(STRING_TRANSIENT String* url);
void ServerConnection_BeginGeneration(Int32 width, Int32 height, Int32 length, Int32 seed, bool vanilla);
void ServerConnection_EndGeneration(void);
void ServerConnection_InitSingleplayer(void);
void ServerConnection_InitMultiplayer(void);
#endif