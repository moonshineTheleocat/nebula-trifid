//------------------------------------------------------------------------------
//  gridaddon.cc
//  (C) 2012-2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "silhouetteaddon.h"
#include "rendermodules/rt/rtpluginregistry.h"
#include "silhouettertplugin.h"

namespace Silhouette
{
__ImplementClass(Silhouette::SilhouetteAddon, 'SIAD', Core::RefCounted);
__ImplementSingleton(Silhouette::SilhouetteAddon);

//------------------------------------------------------------------------------
/**
*/
SilhouetteAddon::SilhouetteAddon()
{
	__ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
SilhouetteAddon::~SilhouetteAddon()
{
	__DestructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void
SilhouetteAddon::Setup()
{
	// register render plugin
	RenderModules::RTPluginRegistry::Instance()->RegisterRTPlugin(&SilhouetteRTPlugin::RTTI);
	this->plugin = RenderModules::RTPluginRegistry::Instance()->GetPluginByRTTI<SilhouetteRTPlugin>(&SilhouetteRTPlugin::RTTI);
}

//------------------------------------------------------------------------------
/**
*/
void
SilhouetteAddon::Discard()
{
	this->plugin = 0;

	// deregister plugin
	RenderModules::RTPluginRegistry::Instance()->UnregisterRTPlugin(&SilhouetteRTPlugin::RTTI);
}

//------------------------------------------------------------------------------
/**
*/
void
SilhouetteAddon::SetVisible(bool b)
{	
	this->plugin->SetVisible(b);
}

//------------------------------------------------------------------------------
/**
*/
void
SilhouetteAddon::SetModels(const Util::Array<Ptr<Graphics::ModelEntity>>& mdls)
{
	this->plugin->SetModels(mdls);
}

//------------------------------------------------------------------------------
/**
*/
void
SilhouetteAddon::SetColor(const Math::float4& col)
{
	this->plugin->SetColor(col);
}

} // namespace Grid