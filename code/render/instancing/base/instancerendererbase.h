#pragma once
//------------------------------------------------------------------------------
/**
    @class Instancing::InstanceRendererBase
    
    Base class for instance renderers.
    
    (C) 2012 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "core/refcounted.h"
#include "math/matrix44.h"
#include "coregraphics/shaderinstance.h"
namespace Instancing
{
class InstanceRendererBase : public Core::RefCounted
{
	__DeclareClass(InstanceRendererBase);
public:
	/// constructor
	InstanceRendererBase();
	/// destructor
	virtual ~InstanceRendererBase();

	/// sets the shader instance
	void SetShader(const Ptr<CoreGraphics::ShaderInstance>& shader);
	/// gets the shader instance
	const Ptr<CoreGraphics::ShaderInstance>& GetShader() const;

	/// set instancing render multiplier
	void SetInstanceMultiplier(SizeT multiplier);

	/// begins transform updates, clears transform array
	void BeginUpdate(SizeT amount);
	/// adds transform
	void AddTransform(const Math::matrix44& matrix);
    /// add id
    void AddId(const int id);
	/// ends transform updates
	void EndUpdate();

	/// render instances
	virtual void Render(const SizeT multiplier);

protected:
	Ptr<CoreGraphics::ShaderInstance> shader;
	Util::Array<Math::matrix44> modelTransforms;
	Util::Array<Math::matrix44> modelViewTransforms;
	Util::Array<Math::matrix44> modelViewProjectionTransforms;
    Util::Array<int> objectIds;
	bool inBeginUpdate;
}; 

//------------------------------------------------------------------------------
/**
*/
inline void 
InstanceRendererBase::SetShader( const Ptr<CoreGraphics::ShaderInstance>& shader )
{
	n_assert(shader.isvalid());
	this->shader = shader;
}

//------------------------------------------------------------------------------
/**
*/
inline const Ptr<CoreGraphics::ShaderInstance>& 
InstanceRendererBase::GetShader() const
{
	return this->shader;
}

} // namespace Instancing
//------------------------------------------------------------------------------