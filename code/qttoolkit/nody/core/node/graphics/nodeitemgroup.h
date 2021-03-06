#pragma once
//------------------------------------------------------------------------------
/**
    @class Nody::NodeItemGroup
    
    Implements a QGraphicsItemGroup which handles dragging, dropping, moving etc for a group of items.
    
    (C) 2012 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "core/refcounted.h"
#include <QGraphicsItemGroup>
#include <QGraphicsSceneDragDropEvent>
namespace Nody
{
class NodeGraphics;
class NodeItemGroup : 
	public QGraphicsItemGroup,
	public Core::RefCounted
{
	__DeclareClass(NodeItemGroup);

public:
	/// constructor
	NodeItemGroup();
	/// destructor
	virtual ~NodeItemGroup();

	/// set pointer to graphics node
	void SetNodeGraphics(const Ptr<NodeGraphics>& node);
	/// get pointer to graphics node
	const Ptr<NodeGraphics>& GetNodeGraphics() const;

	/// override mouse press event to flip the layers of the nodes
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	/// we want to override moving nodes so that we can refresh our link graphics
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    /// handle right clicking
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
	Ptr<NodeGraphics> node;
}; 

} // namespace Nody
//------------------------------------------------------------------------------