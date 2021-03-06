//------------------------------------------------------------------------------
//  multiplayer/multiplayerfeatureunit.cc
//  (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "multiplayerfeatureunit.h"
#include "basegamefeature/basegametiming/gametimesource.h"
#include "basegamefeatureunit.h"

using namespace Multiplayer;

namespace MultiplayerFeature
{
__ImplementClass(MultiplayerFeatureUnit, 'MUFU' , Game::FeatureUnit);
__ImplementInterfaceSingleton(MultiplayerFeatureUnit);

//------------------------------------------------------------------------------
/**
*/
MultiplayerFeatureUnit::MultiplayerFeatureUnit() :
applicationPort(64738)
{	
	__ConstructInterfaceSingleton;
}

//------------------------------------------------------------------------------
/**
*/
MultiplayerFeatureUnit::~MultiplayerFeatureUnit()
{
	__DestructInterfaceSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnActivate()
{
    FeatureUnit::OnActivate();

	this->server = NetworkServer::Create();
	this->server->Open();

	this->factory = NetworkFactoryManager::Create();

	BaseGameFeature::BaseGameFeatureUnit::Instance()->SetFactoryManager(this->factory.cast<BaseGameFeature::FactoryManager>());

    this->SetRenderDebug(true);
	
	this->server->SetupLowlevelNetworking();

	ReplicationManager::Instance()->Reference(dynamic_cast<RakNet::Replica3*>(this->player.get_unsafe()));
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnDeactivate()
{
	this->player = 0;
	this->server->Close();
	this->server = 0;
	this->factory = 0;
    FeatureUnit::OnDeactivate();    
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnRenderDebug()
{
	
	FeatureUnit::OnRenderDebug();
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnBeginFrame()
{    
	this->server->OnFrame();
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnFrame()
{    

    FeatureUnit::OnFrame();
}

//------------------------------------------------------------------------------
/**
*/
void
MultiplayerFeatureUnit::OnEndFrame()
{

    
    Game::FeatureUnit::OnEndFrame();
}

//------------------------------------------------------------------------------
/**
*/
const Multiplayer::UniquePlayerId &
MultiplayerFeatureUnit::GetUniqueId() const
{
	return this->player->GetUniqueId();
}

//------------------------------------------------------------------------------
/**
*/
void 
MultiplayerFeatureUnit::RestartNetwork()
{
	this->server->ShutdownLowlevelNetworking();
	this->server->SetupLowlevelNetworking();

	ReplicationManager::Instance()->Reference(dynamic_cast<RakNet::Replica3*>(this->player.get_unsafe()));
}

}; // namespace MultiplayerFeature
