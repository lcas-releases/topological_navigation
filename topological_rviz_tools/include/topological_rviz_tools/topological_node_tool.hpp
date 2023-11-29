#ifndef TOPMAP_NODE_TOOL_H
#define TOPMAP_NODE_TOOL_H

#include <rclcpp/rclcpp.hpp>
#include "rviz_common/tool.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "std_msgs/msg/header.hpp"
#include "topological_navigation_msgs/srv/add_node.hpp"

namespace rviz
{
  class VectorProperty;
  class VisualizationManager;
  class ViewportMouseEvent;
}

namespace topological_rviz_tools
{

// BEGIN_TUTORIAL
// Here we declare our new subclass of rviz::Tool.  Every tool
// which can be added to the tool bar is a subclass of
// rviz::Tool.
class TopmapNodeTool: public rviz::Tool
{
public:
  TopmapNodeTool();
  ~TopmapNodeTool();

  virtual void onInitialize();

  virtual void activate();
  virtual void deactivate();

  virtual int processMouseEvent(rviz::ViewportMouseEvent& event);
private:
  ros::ServiceClient addNodeSrv_;
  ros::Publisher update_map_;
  rclcpp::Logger logger_{rclcpp::get_logger("rviz2")};
};
} // end namespace topological_rviz_tools

#endif // TOPMAP_NODE_TOOL_H
